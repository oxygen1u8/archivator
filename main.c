#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "information.h"
#include "file_in_out.h"
#include "types.h"
#include "arch_logic.h"

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        fprintf(stderr, "A few arguments!\n");
        return -1;
    }
    
    FILE* fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        fprintf(stderr, "File \"%s\" doesn't exist!\n",  argv[1]);
        return -2;
    }

    symbol_t* syms = NULL;
    int* syms_count = NULL;
    int elem_count = 0;

    reading_from_file(fp, &syms, &syms_count, &elem_count);
    fclose(fp);

    if(syms == NULL)
    {
        fprintf(stderr, "File is empty!\n");
        return -3;
    }

    int sum_count = 0;

    for(int i = 0; i < elem_count; i++)
    {
        sum_count += syms_count[i];
    }

    for(int i = 0; i < elem_count; i++)
    {
        syms[i].freq = (float)syms_count[i] / sum_count;
    }

    free(syms_count);

    symbol_t tmp;
    int tmp_i;

    syms = sort_syms(syms, &elem_count);
    symbol_t* tree = make_tree(syms, elem_count);

    set_information(syms, &elem_count);

    free(syms);
    

    return 0;
}
