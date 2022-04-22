#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_in_out.h"
#include "types.h"

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "rb");
    if(argc == 1)
    {
        fprintf(stderr, "A few arguments!\n");
        return -1;
    }
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
    
    if(syms != NULL)
    {
        for(int i = 0; i < elem_count; i++)
        {
            printf("%c - %d\n", syms[i].sym, syms_count[i]);
        }
    }
    else
    {
        fprintf(stderr, "File is empty!\n");
        return -3;
    }

    if(syms != NULL)
    {
        free(syms);
        free(syms_count);
    }

    return 0;
}
