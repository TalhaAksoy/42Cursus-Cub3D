#include "mathlib.h"

double  ft_pow(double var, int pow){
    int i = 0;
    double ret = 1;
    while (i < pow){
        ret *= var;
        i++;
    }
    return (ret);
}