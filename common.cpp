#include "common.h"

int check(double num)
{
    int sol = 0;
    sol = (fabs(num) < DELTA);

    return sol; 
}

void Clean(void)
{
    while (getchar() != '\n');
}
