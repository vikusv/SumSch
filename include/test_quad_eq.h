#ifndef TEST_QUAD_EQ
#define TEST_QUAD_EQ

#include <stdio.h>

/**
 * @brief Структура с данными о коэффициентах уравнения, количестве его корней и значениях корней
 * 
 */
struct Output {
        double a, b, c;
        int nRoots;
        double x1, x2;
    };

/**
 * @brief Тестирование программы решения квадаратного уравнения по наммым из структуры
 * 
 * @param testValues структура с коэффициентами и ожидаемыми значениями
 * @param testNum индекс теста
 * @return 1 - тест пройден с ошибками, 0 - без ошибок
 */
int TestNumEq(Output testValues, int testNum);


#endif // TEST_QUAD_EQ