#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "information.h"
#include "file_in_out.h"
#include "types.h"
#include "arch_logic.h"

int main(int argc, char* argv[])
{
    if(argc == 1) {
        fprintf(stderr, "A few arguments!\n");
        return -1;
    }
    
    FILE* fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        fprintf(stderr, "File \"%s\" doesn't exist!\n",  argv[1]);
        return -2;
    }

    symbol_t* syms = NULL;
    int* syms_count = NULL;
    int elem_count = 0;

    reading_from_file(fp, &syms, &syms_count, &elem_count);
    fclose(fp);

    if(syms == NULL) {
        fprintf(stderr, "File is empty!\n");
        return -3;
    }

    int sum_count = 0;

    for(int i = 0; i < elem_count; i++) {
        sum_count += syms_count[i];
    }

    for(int i = 0; i < elem_count; i++) {
        syms[i].freq = (float)syms_count[i] / sum_count;
    }

    free(syms_count);

    symbol_t* tree = make_tree(syms, elem_count);

    make_codes(&tree, &syms, &elem_count);
    for(uint32_t i = 0; i < elem_count; i++) {
        strcat(syms[i].code, "\0");
    }

    fp = fopen(argv[1], "rb");
    char archiveNameTemp[256];
    char archiveName[256];
    strcpy(archiveNameTemp, argv[1]);
    strcat(archiveNameTemp, ".atemp");
    FILE *temp = fopen(archiveNameTemp, "rwb");
    FILE *dest = fopen(archiveName, "wb");

    writing_to_file(fp, temp, dest, &syms, &elem_count);
    fclose(fp);
    fclose(temp);
    fclose(dest);
    set_information(syms, &elem_count);

    free(syms);

    return 0;
}
