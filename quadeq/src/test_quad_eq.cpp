#include "quad_eq.h"
#include "common.h"
#include "test_quad_eq.h"

#define RED_TEXT   "\033[0;31m" 
#define WHITE_TEXT "\033[0m\n"

/**
 * @brief Массив соответствия количества корней и их строкового представления 
 * 
 */
static const char *IntToNum[] = {
    "0", "0", "1", "1", "2", "INF"
};

int TestNumEq(Output testValues, int testNum)
{
    double x1 = 0, x2 = 0;
    int nRoots = QuadEq(testValues.a, testValues.b, testValues.c, &x1, &x2);
    if (!(nRoots == testValues.nRoots) && !IsEqual(x1, testValues.x1) && !IsEqual(x1, testValues.x1)) 
    {   
        printf(
                RED_TEXT
               "Ошибка в тесте %d (a = %lg, b = %lg, c = %lg).\n"
               "Полученные значения: nRoots = %s, x1 = %lg, x2 = %lg.\n"
               "Ожидаемые значения: nRoots = %s, x1 = %lg, x2 = %lg."
                WHITE_TEXT, 
               (testNum + 1), testValues.a, testValues.b, testValues.c, IntToNum[nRoots], x1, x2, 
               IntToNum[testValues.nRoots], testValues.x1, testValues.x2
               );

               return 1;
    }

    return 0;
}