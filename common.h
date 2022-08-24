#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>

const double DELTA = 1E-6;

/**
 * @brief Очистка буфера
 * 
 */
void CleanInput();

/**
 * @brief Проверка аргументов на равенство
 * 
 * @param a 
 * @param b
 * @return int 
 */
int IsEqual(double a, double b);

/**
 * @brief Проверка аргумента на равенство нулю
 * 
 * @param num 
 * @return int 
 */
int IsZero(double num);

#endif // COMMON_H