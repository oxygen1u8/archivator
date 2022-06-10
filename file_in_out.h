#ifndef FILE_IN_OUT_H
#define FILE_IN_OUT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "types.h"

void reading_from_file(FILE* fp, symbol_t** syms, int** syms_count, 
    int* elem_count);
void writing_to_file(FILE *src, FILE *temp, FILE *dst, symbol_t **syms, int *elem_count);

#endif
