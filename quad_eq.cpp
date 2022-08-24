#include "quad_eq.h"
#include "common.h"

int QuadEq(double a, double b, double c, double* x1, double* x2)
{
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);
    assert(x1 != x2);

    if (check(a))
    {
        return LinEq(b, c, x1);
    }
    else
    {
        if (check(c))
        {
            if (check(b))
            {
                x1 = 0;
                return OneRootQuadEq;
            }
            else 
            {
                *x1 = 0;
                *x2 = -b / a;
                return TwoRootsQuadEq;
            }
        }
        else
        {
            double D = b * b - 4 * a * c;
            if (check(D))
            {
                *x1 = -b / (2 * a);
                return OneRootQuadEq;
            }
            else if (D > 0)
            {
                /* sqrt */ D = sqrt(D);
                *x1 = (-b + D) / (2 * a);
                *x2 = (-b - D) / (2 * a);
                return TwoRootsQuadEq;
            }
            else if (D < 0)
            {
                return NoRootsQuadEq;
            }
        }
    }

    return Undefined;
}

int LinEq(double b, double c, double* x1)
{
    assert (b != NAN);
    assert (c != NAN);

    if (!check(c) && !check(b))
    {
        *x1 = -c/b;
        return OneRootLinEq;
    }
    else if (check(c) && !check(b))
    {
        *x1 = 0;
        return OneRootLinEq;
    }
    else if (!check(c) && check(b))
        return NoRootsLinEq;
    else if (check(c) && check(b))
        return InfRoots;

    return Undefined;
}

int input(double* a, double* b, double* c)
{
    int count = 0, res = 0;
    char ch = 0;

    count = scanf("%lf %lf %lf", a, b, c);
    if (count < 3)
    {
        scanf("%c", &ch);
        if (ch == 'q')
        {
            res = Exit;
        }
        else 
        {
            while (getchar() != '\n');
            res = Repeat;
        }
    }
    if (count == 3)
    {
        res = Success;
    }

    return res;
}

void OutputRoots(const double x1, const double x2, const int nRoots)
{
    switch (nRoots)
    {
        case NoRootsLinEq:   printf("Уравнение не имеет корней.\n");
                             break;
        case NoRootsQuadEq:  printf("Уравнение не имеет действительных корней.\n");
                             break;
        case OneRootLinEq:   printf("Это не квадратное уравнение! Его решение %lf.\n", x1);
                             break;
        case OneRootQuadEq:  printf("Уравнение имеет одно решение: %lf.\n", x1);
                             break;
        case TwoRootsQuadEq: printf("Уравнение имеет два решения: %lf и %lf.\n", x1, x2);
                             break;
        case InfRoots:       printf("Уравнение имеет бесконечное количество корней.\n"); 
                             break;
        default:             assert(0 && "Нет такого случая.");
    }
}
