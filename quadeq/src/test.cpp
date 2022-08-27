#include <stdio.h>
#include "quad_eq.h"
#include "common.h"
#include "test_quad_eq.h"

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