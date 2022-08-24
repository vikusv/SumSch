#include "quad_eq.h"
#include "common.h"

int main(void)
{
    double a = 0, b = 0, c = 0, D = 0, x1 = 0, x2 = 0, x = 0;
    int n = 0, res = 0;

    do
    {
        printf("Введите через пробел коэффициенты квадратного уравнения. Чтобы закончить, введите q.\n");
        res = input(&a, &b, &c);

        while (res == Repeat)
        {
            printf("Принимаются только числовые значения.\n");
            res = input(&a, &b, &c);
        }

        if (res == Success)
        {
            n = QuadEq(a, b, c, &x1, &x2);
            OutputRoots(x1, x2, n);
        }
    } while (res != Exit);
    
    return 0;
}
