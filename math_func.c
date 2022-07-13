#include "math_func.h"

double entropy_count(symbol_t* symbols, int* syms_count)
{
    double H = 0.0;
    for (int i = 0; i < *syms_count; i++)
        H += symbols[i].freq * log2(symbols[i].freq);
    return -H;
}

double bcost(int *fsize_2, double file_length)
{
    
}
