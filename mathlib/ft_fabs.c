#include "mathlib.h"

double  ft_fabs(double var){
    if (var >= 0){
        return (var);
    }
    else{
        return (-var);
    }
}