#include "arch_logic.h"

symbol_t* sort_syms(symbol_t* syms, int* elem_count)
{
    symbol_t tmp;
    for(int i = 0; i < *elem_count; i++)
    {
        for(int j = 0; j < *elem_count - 1; j++)
        {
            if(syms[j].freq < syms[j + 1].freq)
            {
                tmp = syms[j + 1];
                syms[j + 1] = syms[j];
                syms[j] = tmp;
            }
        }
    }
    return syms;
}

symbol_t* make_tree(symbol_t* syms, int elem_count)
{
    symbol_t* head = (symbol_t*) malloc(sizeof(symbol_t));
    symbol_t* tmp = NULL;
    symbol_t* tmp2 = NULL;

    int elem_count_ = elem_count;

    tmp = (symbol_t*) malloc(elem_count * sizeof(symbol_t));
    memcpy(tmp, syms, elem_count * sizeof(symbol_t));

    while(elem_count_ != 1)
    {
        
    }
    
}
