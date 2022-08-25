#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>


const double DELTA = 1E-6;

/**
 * @brief Очистка буфера ввода
 * 
 */
void CleanInput();

/**
 * @brief Проверка аргументов на равенство
 * 
 * @param a 
 * @param b
 * @return 1 - если аргументы равны, 0 - не равны
 */
int IsEqual(double a, double b);

/**
 * @brief Проверка аргумента на равенство нулю
 * 
 * @param num 
 * @return 1 - если аргументр равен нувлю, 0 - не равен
 */
int IsZero(double num);

#endif // COMMON_H