#include "quad_eq.h"
#include "common.h"

int main(void)
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int nRoots = 0, inputStatus = 0;

    do
    {
        printf("Введите через пробел коэффициенты квадратного уравнения. Чтобы закончить, введите q.\n");
        inputStatus = InputCoeff(&a, &b, &c);

        while (inputStatus == Repeat)
        {
            printf("Принимаются только числовые значения.\n");
            inputStatus = InputCoeff(&a, &b, &c);
        }

        if (inputStatus == Success)
        {
            nRoots = QuadEq(a, b, c, &x1, &x2);
            OutputRoots(x1, x2, nRoots);
        }
    } while (inputStatus != Exit);
    
    return 0;
}
