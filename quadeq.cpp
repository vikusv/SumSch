/**
 * @file quadeq.cpp
 * @author Viktoria
 * @brief Решение квадратных уравнений
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <cmath>
#include <assert.h>
#define INF -1
#define DELTA 0.000001

enum StatusInput
{
    Exit    = 1, 
    Repeat  = 2,
    Success = 3,
};
/**
 * @brief Решение квадратных уравнений вида ax^2+bx+c=0
 * 
 * @param a старший коэффициент
 * @param b второй коэффициент
 * @param c свободный член
 * @param x1 первый (или единственное, если корни равный) уравнения 
 * @param x2 второй корень уравнения
 * @param x единственный корень уравнения, если старший член равен нулю
 * @return int 
 */
int QuadEq(double a, double b, double c, double* x1, double* x2, double* x);
/**
 * @brief Решение линейныйх уравнений вида bx+c=0
 * 
 * @param b коэффициент при неизвестной
 * @param c свободный член
 * @param x корень уравнения
 * @return int 
 */
int LinEq(double b, double c, double* x);

/**
 * @brief Проверка аргументов на равенство нулю
 * 
 * @param num аргумент
 * @return int 
 */
int check(double num);
/**
 * @brief Считывание коэффициентов уравнения при пользовательском вводе
 * 
 * @param a старший коэффициент
 * @param b второй коэффициент
 * @param c свободный член
 * @return int 
 */
int input(double* a, double* b, double* c);
/**
 * @brief Очистка буфера
 * 
 */
void Clean(void);

int main(void)
{
    double a = 0, b = 0, c = 0, D = 0, x1 = 0, x2 = 0, x = 0;
    int n = 0, res = 0;
    printf("Введите через пробел коэффициенты квадратного уравнения. Чтобы закончить, введите q.\n");
    res = input(&a, &b, &c);
    if (res == Repeat)
    {
        while (res == Repeat)
        {
            printf("Принимаются только числовые значения.\n");
            res = input(&a, &b, &c);
        }
    }
    while (res == Success)
    {
        n = QuadEq(a, b, c, &x1, &x2, &x);
        if (n == 2)
            printf("Уравнение имеет два решения: %lf и %lf.\n", x1, x2);
        else if (n == 1)
            {
                if (check(a))
                {
                    if (x == 0)
                        printf("Это не квадратное уравнение! Его решение %lf.\n", x); 
                    else
                        printf("Это не квадратное уравнение! Его решение %lf.\n", x);
                }
                else 
                    printf("Уравнение имеет одно решение: %lf.\n", x1);
            }
        else if (n == 0)
        {
            if (check(a))
                printf("Уравнение не имеет корней.\n");
            else 
                printf("Уравнение не имеет действительных корней.\n");
        }
        else if (n == INF)
            printf("Уравнение имеет бесконечное количество корней.\n");
       
        printf("Введите через пробел коэффициенты квадратного уравнения. Чтобы закончить, введите q.\n");
        res = input(&a, &b, &c);
        if (res == Repeat)
        {
            while (res == Repeat)
            {
                printf("Принимаются только числовые значения.\n");
                res = input(&a, &b, &c);
            }
        }
    }
    
    return 0;
}
int QuadEq(double a, double b, double c, double* x1, double* x2, double* x)
{
    double D = 0;
    int n = 0;
    if (check(a))
    {
        n = LinEq(b, c, x);
    }
    else
    {
        D = b*b - 4*a*c;
        if (D > 0)
        {
            n = 2;
            *x1 = (-b + sqrt(D))/(2*a);
            *x2 = (-b - sqrt(D))/(2*a);
        }
        else if (check(D))
        {
            n = 1;
            *x1 = -b/(2*a);
        }
        else if (D < 0)
        {
            n = 0;
        }
    }

    return n;
}
int LinEq(double b, double c, double* x)
{
    assert (*x == NAN);
    int n;
    if (!check(c) && !check(b))
    {
        *x = -c/b;
        n = 1;
    }
    else if (check(c) && !check(b))
    {
        *x = 0;
        n = 1;
    }
    else if (!check(c) && check(b))
        n = 0;
    else if (check(c) && check(b))
        n = INF;

    return n;
}
int check(double num)
{
    int sol = 0;
    sol = (fabs(num) < DELTA);

    return sol; 
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
void Clean(void)
{
    while (getchar() != '\n');
}