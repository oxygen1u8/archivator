#include "file_in_out.h"

void reading_from_file(FILE* fp, symbol_t** syms, int** syms_count, int* elem_count)
{
    union code bcode;
    bool isExist;
    char syms_buff[256];
    uint32_t syms_count_buff[256];
    memset(syms_count_buff, 0, 256 * sizeof(uint32_t));

    while(!feof(fp)) {
        isExist = false;
        if(fread(&bcode.sym_to_write, 1, sizeof(unsigned char), fp) != 1) {
            break;
        }
        for(uint32_t i = 0; i < *elem_count; i++) {
            if(syms_buff[i] == bcode.sym_to_write) {
                isExist = true;
                syms_count_buff[i] += 1;
                break;
            }
        }
        if(!isExist) {
            *elem_count += 1;
            syms_buff[*elem_count - 1] = bcode.sym_to_write;
            syms_count_buff[*elem_count - 1] += 1;
        }
    }

    *syms = (symbol_t*) malloc(*elem_count * sizeof(symbol_t));
    (void)memset(*syms, 0, *elem_count * sizeof(symbol_t));
    *syms_count = (int*) malloc(*elem_count * sizeof(int));
    (void)memset(*syms_count, 0, *elem_count * sizeof(int));

    for(uint32_t i = 0; i < *elem_count; i++) {
        (*syms)[i].sym = syms_buff[i];
        (*syms_count)[i] = syms_count_buff[i];
    }
}

void writing_to_file(FILE *src, FILE *temp, FILE *dst, symbol_t **syms, int *elem_count)
{
    union code bcode;
    
}
