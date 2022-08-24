#ifndef QUAD_EQ_H
#define QUAD_EQ_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

enum InputStatus
{
    Exit    = 1, 
    Repeat  = 2,
    Success = 3,
};

enum RootStatus
{
    NoRootsLinEq   =  0,
    NoRootsQuadEq  =  1,
    OneRootLinEq   =  2,
    OneRootQuadEq  =  3,
    TwoRootsQuadEq =  4,
    InfRoots       =  5,

    Undefined      = -1,
};

/**
 * @brief Решение квадратных уравнений вида ax^2+bx+c=0
 * 
 * @param a старший коэффициент
 * @param b второй коэффициент
 * @param c свободный член
 * @param x1 первый (или единственный) уравнения 
 * @param x2 второй корень уравнения
 * @return int 
 */
int QuadEq(double a, double b, double c, double* x1, double* x2);

/**
 * @brief Решение линейныйх уравнений вида bx+c=0
 * 
 * @param b коэффициент при неизвестной
 * @param c свободный член
 * @param x1 корень уравнения
 * @return int 
 */
int LinEq(double b, double c, double* x1);


/**
 * @brief Считывание коэффициентов уравнения при пользовательском вводе
 * 
 * @param a старший коэффициент
 * @param b второй коэффициент
 * @param c свободный член
 * @return int 
 */
int InputCoeff(double* a, double* b, double* c);

/**
 * @brief Вывод корней квадратного уравнения
 * 
 */
void OutputRoots(double x1, double x2, int nRoots);

#endif // QUAD_EQ_H
