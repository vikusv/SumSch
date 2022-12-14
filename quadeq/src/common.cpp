#include "common.h"

int IsEqual(double a, double b)
{
    return (fabs(a - b) < DELTA); 
}

int IsZero(double num)
{
    return IsEqual(num, 0);
}

void CleanInput() 
{
    while (getchar() != '\n');
}
