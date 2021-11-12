#ifndef BIGINT_H
#define BIGINT_H
#define INT_IN_STRUCT 32

typedef struct uint_1024_struct
{
    unsigned int data[INT_IN_STRUCT];
} uint_1024;

typedef struct word_uint_1024_struct
{
    char data[INT_IN_STRUCT * 11];
} uint_1024_char;

uint_1024 *createBigInt(unsigned int inp);

uint_1024 *initBigInt();

uint_1024 *sum(uint_1024 *inpF, uint_1024 *inpS);

uint_1024 *minus(uint_1024 *inpF, uint_1024 *inpS);

uint_1024 *mul(uint_1024 *inpF, uint_1024 *inpS);

uint_1024 *sdvig(uint_1024 *inp, int sddvig);

void printBigInt(uint_1024 *s);

void printBigIntBinary(uint_1024 *s);

uint_1024 *scanBigInt();

#endif