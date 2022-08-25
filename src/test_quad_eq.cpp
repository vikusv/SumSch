#include "quad_eq.h"
#include "common.h"
#include "test_quad_eq.h"

int TestNumEq(Output testValues, int testNum)
{
    double x1 = 0, x2 = 0;
    int nRoots = QuadEq(testValues.a, testValues.b, testValues.c, &x1, &x2);
    if (!(nRoots == testValues.nRoots) && !IsEqual(x1, testValues.x1) && !IsEqual(x1, testValues.x1)) 
    {   
        printf("\033[0;31m" // RED
               "Ошибка в тесте %d (a = %lg, b = %lg, c = %lg).\n"
               "Полученные значения: nRoots = %s, x1 = %lg, x2 = %lg.\n"
               "Ожидаемые значения: nRoots = %s, x1 = %lg, x2 = %lg."
               "\033[0m\n", // WHITE
               (testNum + 1), testValues.a, testValues.b, testValues.c, IntToNum[nRoots], x1, x2, IntToNum[testValues.nRoots], testValues.x1, testValues.x2);

               return 1;
    }

    return 0;
}