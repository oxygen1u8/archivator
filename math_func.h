#ifndef MATH_FUNC_H
#define MATH_FUNC_H

#include "types.h"
#include <math.h>

double entropy_count(symbol_t* syms, int* syms_count);
double bcost(int *fsize_2, double file_length);

#endif
