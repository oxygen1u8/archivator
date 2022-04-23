#include "information.h"

void set_information(symbol_t* syms, int* k, int* kk)
{
    for (int i = 0; i < *k; i++)
    {
        printf("N = %d\tCode = %d\tFreq = %lf\tNum = %d\tSymb = %c\n", i, syms[i].sym, syms[i].freq, (int) syms[i].freq * kk[i], syms[i].sym);
    }
    printf("Entropy = %lf\n", entropy_count(syms, k));
    // printf("Bit cost = %f\n", bcost(fsize_2, *kk));
}
