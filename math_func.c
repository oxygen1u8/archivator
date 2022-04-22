#include "math_func.h"

double entropy(symbol_t* symbols, int* syms_count)
{
    float H = 0.0f;
    for(int i = 0; i < *syms_count; i++)
        H += symbols[i].freq * log2(symbols[i].freq);
    return -H;
}
