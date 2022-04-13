#ifndef TYPES_H
#define TYPES_H

#define ARRAY_SIZE(x) sizeof((x))/sizeof((x[0]))

typedef struct _symbol {
    unsigned char sym;
    char code[255];
    float freq;
    struct _symbol* left;
    struct _symbol* right;
} symbol_t;

union code
{
    unsigned char sym_to_write;
    struct byte
    {
        unsigned b0: 1;
        unsigned b1: 1;
        unsigned b2: 1;
        unsigned b3: 1;
        unsigned b4: 1;
        unsigned b5: 1;
        unsigned b6: 1;
        unsigned b7: 1;
    } byte;
};


#endif
