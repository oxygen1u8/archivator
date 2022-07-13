#include "arch_logic.h"

symbol_t* sort_syms(symbol_t** syms, int* elem_count)
{
    symbol_t tmp;

    for (int i = 0; i < *elem_count; i++) {
        for (int j = 0; j < *elem_count - 1; j++) {
            if ((*syms)[j].freq < (*syms)[j + 1].freq) {
                tmp = (*syms)[j + 1];
                (*syms)[j + 1] = (*syms)[j];
                (*syms)[j] = tmp;
            }
        }
    }
    return *syms;
}

symbol_t* make_tree(symbol_t* syms, int elem_count)
{
    symbol_t *root = NULL;
    symbol_t *tmp = NULL;
    symbol_t *tmp_l = NULL, *tmp_r = NULL;
    symbol_t* array = (symbol_t *) malloc(sizeof(symbol_t) * elem_count);
    memcpy(array, syms, elem_count * sizeof(symbol_t));
    sort_syms(&array, &elem_count);
    while (elem_count != 1) {
        tmp = (symbol_t *) malloc(sizeof(symbol_t));
        memset(tmp, 0, sizeof(symbol_t));

        tmp->freq = array[elem_count - 1].freq + array[elem_count - 2].freq;
        
        tmp_l = (symbol_t *) malloc(sizeof(symbol_t));
        memcpy(tmp_l, &array[elem_count - 1], sizeof(symbol_t));
        tmp_r = (symbol_t *) malloc(sizeof(symbol_t));
        memcpy(tmp_r, &array[elem_count - 2], sizeof(symbol_t));
        
        tmp->left = tmp_l;
        tmp->right = tmp_r;

        elem_count -= 1;
        memcpy(&array[elem_count - 1], tmp, sizeof(symbol_t));
        sort_syms(&array, &elem_count);
        if (elem_count == 1) {
            root = tmp;
        }
    }
    return root;
}

void make_codes(symbol_t **tree, symbol_t **syms, int *elem_count)
{
    symbol_t *tmp = NULL;
    while (*tree != NULL)
    {
        tmp = *tree;
        if (tmp->sym != 0) {
            for (int i = 0; i < *elem_count; i++) {
                if ((*syms)[i].sym == tmp->sym) {
                    strcpy((*syms)[i].code, tmp->code);
                    break;
                }
            }
            break;
        }

        if (tmp->left != NULL) {
            strcat(tmp->left->code, tmp->code);
            strcat(tmp->left->code, "0");
            make_codes(&(*tree)->left, syms, elem_count);
            if ((*tree)->left->left == NULL & (*tree)->left->right == NULL) {
                free((*tree)->left);
                (*tree)->left = NULL;
            }
            if (tmp->freq == 1.0f) {
                continue;
            }
        } else if (tmp->right != NULL) {
            strcat(tmp->right->code, tmp->code);
            strcat(tmp->right->code, "1");
            make_codes(&(*tree)->right, syms, elem_count);
            if ((*tree)->right->left == NULL & (*tree)->right->right == NULL) {
                free((*tree)->right);
                (*tree)->right = NULL;
            }
        } else {
            break;
        }
        if (tmp->freq == 1.0f) {
            free(*tree);
            break;
        }
    }
}
