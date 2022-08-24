#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>

const double DELTA = 1E-6;

/**
 * @brief Очистка буфера
 * 
 */
void Clean(void);

/**
 * @brief Проверка аргументов на равенство нулю
 * 
 * @param num аргумент
 * @return int 
 */
int check(double num);

#endif // COMMON_H