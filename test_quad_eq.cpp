#include <stdio.h>
#include "quad_eq.h"
#include "common.h"

struct Output {
        double a, b, c;
        int nRoots;
        double x1, x2;
    };

int TestNumEq(Output testValues, int testNum);

int main(void)
{
    Output OutputData[] = {
                      {  1,     2,   3,  NoRootsQuadEq,    0,    0}, 
                      {  0,    -5,  -3,   OneRootLinEq, -0.6,    0},
                      {  6,     0,   0,  OneRootQuadEq,    0,    0}, 
                      {-15,     8,   0, TwoRootsQuadEq,    0, 0.53},
                      {6.3, -15.1, 4.9, TwoRootsQuadEq, 0.39, 2.01},
                      {  1,     2,   1,  OneRootQuadEq,   -1,    0},
                      {  0,     0,   0,       InfRoots,    0,    0},
                      {8.2,   1.9, 2.5,  NoRootsQuadEq,    0,    0},
                     };
    int ErrorTests = 0;
    int testSum = (int) (sizeof (OutputData) / sizeof (OutputData[0]));
    for (int testNum = 0; testNum < testSum; testNum++)
    {
        ErrorTests += TestNumEq(OutputData[testNum], testNum);
    }
    printf("Количество тестов с ошибками - %d.\n", ErrorTests);

    return 0;
}

int TestNumEq(Output testValues, int testNum)
{
    double x1 = 0, x2 = 0;
    int nRoots = QuadEq(testValues.a, testValues.b, testValues.c, &x1, &x2);
    if (!(nRoots == testValues.nRoots) && !IsEqual(x1, testValues.x1) && !IsEqual(x1, testValues.x1)) 
    {
        printf("Ошибка в тесте %d (a = %lg, b = %lg, c = %lg).\n"
               "Полученные значения: nRoots = %d, x1 = %lg, x2 = %lg.\n"
               "Ожидаемые значения: nRoots = %d, x1 = %lg, x2 = %lg.\n", 
               (testNum + 1), testValues.a, testValues.b, testValues.c, nRoots, x1, x2, testValues.nRoots, testValues.x1, testValues.x2);

               return 1;
    }

    return 0;
}

