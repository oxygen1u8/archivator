#ifndef ARCH_LOGIC_H
#define ARCH_LOGIC_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"

symbol_t* sort_syms(symbol_t **syms, int *elem_count);
symbol_t* make_tree(symbol_t *, int);
void make_codes(symbol_t **, symbol_t **, int *); 

#endif
