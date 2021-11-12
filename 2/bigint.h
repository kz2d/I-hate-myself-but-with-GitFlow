#ifndef BIGINT_H
#define BIGINT_H
#define MAX_INT 32

typedef struct uint_1024_struct
{
    unsigned char data[MAX_INT];
} uint_1024;

uint_1024 *createBigInt(unsigned int inp);
void printBigInt(uint_1024 *settings);
uint_1024 *sum(uint_1024 argc, uint_1024 argv);

#endif