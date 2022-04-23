#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "information.h"
#include "file_in_out.h"
#include "types.h"

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

    symbol_t tmp;
    int tmp_i;

    for(int i = 0; i < elem_count; i++)
    {
        for(int j = 0; j < elem_count - 1; j++)
        {
            if(syms_count[j] < syms_count[j + 1])
            {
                tmp_i = syms_count[j + 1];
                syms_count[j + 1] = syms_count[j];
                syms_count[j] = tmp_i;

                tmp = syms[j + 1];
                syms[j + 1] = syms[j];
                syms[j] = tmp;
            }
        }
    }

    set_information(syms, &elem_count, syms_count);

    free(syms);
    free(syms_count);

    return 0;
}
