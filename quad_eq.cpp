#include "quad_eq.h"
#include "common.h"

int QuadEq(double a, double b, double c, double* x1, double* x2)
{
    assert(a  != NAN);
    assert(b  != NAN);
    assert(c  != NAN);
    assert(x1 != x2);

    double x = 0;
    if (IsZero(a))
    {
        return LinEq(b, c, x1);
    }
    else
    {
        if (IsZero(c))
        {
            if (IsZero(b))
            {
                x1 = 0;
                return OneRootQuadEq;
            }
            else 
            {
                *x1 = 0;
                *x2 = -b / a;
                RootsSwap(x1, x2);
                return TwoRootsQuadEq;
            }
        }
        else
        {
            double D = b * b - 4 * a * c;
            if (IsZero(D))
            {
                *x1 = -b / (2 * a);
                return OneRootQuadEq;
            }
            else if (D > 0)
            {
                D = sqrt(D);
                *x1 = (-b + D) / (2 * a);
                *x2 = (-b - D) / (2 * a);
                RootsSwap(x1, x2);
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

    if (!IsZero(c) && !IsZero(b))
    {
        *x1 = -c/b;
        return OneRootLinEq;
    }
    else if (IsZero(c) && !IsZero(b))
    {
        *x1 = 0;
        return OneRootLinEq;
    }
    else if (!IsZero(c) && IsZero(b))
        return NoRootsLinEq;
    else if (IsZero(c) && IsZero(b))
        return InfRoots;

    return Undefined;
}

int InputCoeff(double* a, double* b, double* c)
{
    int count = 0, res = 0;
    char ch = 0;

    count = scanf("%lg %lg %lg", a, b, c);
    if (count < 3)
    {
        scanf("%c", &ch);
        if (ch == 'q')
        {
            res = Exit;
        }
        else 
        {
            CleanInput();
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
        case OneRootLinEq:   printf("Это не квадратное уравнение! Его решение %lg.\n", x1);
                             break;
        case OneRootQuadEq:  printf("Уравнение имеет одно решение: %lg.\n", x1);
                             break;
        case TwoRootsQuadEq: printf("Уравнение имеет два решения: %lg и %lg.\n", x1, x2);
                             break;
        case InfRoots:       printf("Уравнение имеет бесконечное количество корней.\n"); 
                             break;
        default:             assert(0 && "Нет такого случая.");
    }
}

void RootsSwap(double* x1, double* x2)
{
    double x = 0;
    if (*x1 > *x2)
    {
        x = *x1;
        *x1 = *x2;
        *x2 = x;
    }
}