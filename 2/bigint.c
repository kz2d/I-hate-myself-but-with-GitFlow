#include <string.h>
#include "bigint.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_UINT 0x7FFFFF

uint_1024 *createBigInt(unsigned int inp)
{
    uint_1024 *s = initBigInt();
    for (size_t i = 0; inp != 0; i++)
    {
        s->data[i] = inp % 10;
        inp /= 10;
    }

    return s;
}

uint_1024 *initBigInt()
{
    uint_1024 *s;
    s = malloc(sizeof(uint_1024));

    return s;
}
uint_1024 *sum(uint_1024 *inpF, uint_1024 *inpS)
{
    uint_1024 *s = initBigInt();
    long long buf = 0;
    for (int i = 0; i < MAX_INT; i++)
    {
        buf += inpF->data[i] + inpS->data[i];
        s->data[i] = buf % 10;
        buf /= 10;
    }
    if (buf)
    {
        printf("OVERLOAD");
    }
    return s;
}

uint_1024 *minus(uint_1024 *inpF, uint_1024 *inpS)
{
    uint_1024 *s = initBigInt();
    long long buf = 0;
    int over = 0;
    for (int i = 0; i < MAX_INT; i++)
    {

        buf = inpF->data[i] - inpS->data[i];
        if (over)
        {
            buf -= 1;
            over = 0;
        }
        if (buf < 0)
        {
            buf += 10;
            over = 1;
        }
        s->data[i] = buf;
    }
    if (over)
    {
        printf("under minus");
    }
    return s;
}

uint_1024 *mul(uint_1024 *inpF, uint_1024 *inpS)
{
    uint_1024 *s = initBigInt();
    int buf = 0;
    for (int z = 0; z < MAX_INT; z++)
    {
        short int el = inpF->data[z];
        for (int i = 0; i < MAX_INT - z; i++)
        {
            buf += inpS->data[i] * el;
            s->data[i + z] = buf % 10;
            buf /= 10;
        }
        if (buf)
        {
            printf("OVERLOAD");
        }
    }
    return s;
}

int qual_zero(uint_1024 *inp)
{
    for (int i = 0; i < MAX_INT; i++)
    {
        if (inp->data[i] != 0)
            return 0;
    }
    return 1;
}

void printBigInt(uint_1024 *s)
{
    for (size_t i = MAX_INT - 1; i >= 0; i--)
    {
        printf("%d", s->data[i]);
    }
    printf("\n");
}

uint_1024 *scanBigInt()
{
    char s[100000];
    scanf("%s", s);
    int len = strlen(s) - 1;
    uint_1024 *res = initBigInt();
    for (size_t i = 0; len >= 0; i++, len--)
    {
        res->data[len] = s[i];
    }
    return res;
}