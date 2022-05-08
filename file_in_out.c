#include "file_in_out.h"

void reading_from_file(FILE* fp, symbol_t** syms, int** syms_count, int* elem_count)
{
    union code bcode;
    bool isExist;
    int _elem_count = 0;
    char syms_buff[256];

    symbol_t* tmp_syms = NULL;
    int* tmp_syms_count = NULL;
    
    while(!feof(fp))
    {
        isExist = false;
        fread(&bcode.sym_to_write, 1, sizeof(unsigned char), fp);
        if(tmp_syms == NULL)
        {
            tmp_syms = (symbol_t*) malloc(sizeof(symbol_t));
            tmp_syms_count = (int*) malloc(sizeof(int));
            tmp_syms[0].sym = bcode.sym_to_write;
            tmp_syms[0].left = NULL;
            tmp_syms[0].right = NULL;
            tmp_syms_count[0] = 1;
            _elem_count = 1;
            
        }
        else
        {
            for(int i = 0; i < _elem_count; i++)
            {
                if(tmp_syms[i].sym == bcode.sym_to_write)
                {
                    isExist = true;
                    tmp_syms_count[i] += 1;
                    break;
                }
            }
            if(!isExist)
            {
                tmp_syms = (symbol_t*) realloc(tmp_syms, (_elem_count + 1) * sizeof(symbol_t));
                tmp_syms_count = (int*) realloc(tmp_syms_count, (_elem_count + 1) * sizeof(int));
                tmp_syms[_elem_count].sym = bcode.sym_to_write;
                tmp_syms[_elem_count].left = NULL;
                tmp_syms[_elem_count].right = NULL;
                tmp_syms_count[_elem_count] = 1;
                _elem_count += 1;
            }
        }
    }

    *syms = (symbol_t*) malloc(sizeof(tmp_syms));
    *syms_count = (int*) malloc(sizeof(tmp_syms_count));
    
    *elem_count = _elem_count;
    *syms = tmp_syms;
    *syms_count = tmp_syms_count;
}
