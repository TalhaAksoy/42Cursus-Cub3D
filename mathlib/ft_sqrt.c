#include "mathlib.h"

double ft_sqrt(double var)
{
    double i = 0;
    double j = var / 2;

    while (j != i)
    {
        i = j;
        j = (var / i + i) / 2;
    }

    return j;
}