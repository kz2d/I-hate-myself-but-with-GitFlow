#include <string.h>
#include "bigintNorm.h"
#include <stdlib.h>
#include <stdio.h>

uint_1024 *createBigInt(unsigned int inp)
{
    uint_1024 *s = initBigInt();
    s->data[0] = inp;

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
    for (int i = 0; i < INT_IN_STRUCT; i++)
    {
        buf += inpF->data[i] + inpS->data[i];
        s->data[i] = buf;
        buf = buf >> sizeof(unsigned int) * 8;
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
    signed long long buf = 0;
    int over = 0;
    for (int i = 0; i < INT_IN_STRUCT; i++)
    {

        buf = inpF->data[i] - inpS->data[i];
        if (over)
        {
            buf -= 1;
            over = 0;
        }
        if (buf < 0)
        {
            buf += 0xffffffff;
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
    for (int z = 0; z < INT_IN_STRUCT; z++)
    {
        for (int bit = 0; bit < sizeof(int) * 8; bit++)
        {
            if (1 << bit & inpS->data[z])
            {
                // printBigIntBinary(s);
                s = sum(s, sdvig(inpF, bit + z * 8 * sizeof(int)));
                // printBigIntBinary(s);
            }
        }
    }
    return s;
}

uint_1024 *sdvig(uint_1024 *inp, int sddvig)
{
    uint_1024 *s = createBigInt(0);
    long long buf = 0;
    const int bitsInInt = 8 * sizeof(int);
    int intSdvig = sddvig / bitsInInt;
    int dopSdvig = sddvig - intSdvig * bitsInInt;
    for (int i = 0; i < INT_IN_STRUCT; i++)
    {
        buf = inp->data[i];
        // printf(" %d %d\n", buf << dopSdvig, buf >> (8 - dopSdvig));

        s->data[i + intSdvig] += buf << dopSdvig;
        if (i + intSdvig < INT_IN_STRUCT)
            s->data[i + intSdvig + 1] += buf >> (bitsInInt - dopSdvig);
    }
    // printBigIntBinary(s);
    return s;
}

void printBigInt(uint_1024 *s)
{
    int prevTime = 0;
    uint_1024_char *outS = malloc(sizeof(uint_1024_char));
    for (int z = 0; z < INT_IN_STRUCT; z++)
    {
        for (int bit = 0; bit < sizeof(int) * 8; bit++)
        {
            if (1 << bit & s->data[z])
            {
                int z = prevTime;
                int iter = 0;
                while (z > 0)
                {
                    outS->data[iter] += z % 10 + '0';
                    if (outS->data[iter] >= 10)
                    {
                        if (iter == INT_IN_STRUCT * 11)
                            printf("OVERFLOW");
                        outS->data[iter + 1] += 1;
                        outS->data[iter] -= 10;
                    }
                    z /= 10;
                }
            }
            prevTime *= 2;
            if (prevTime == 0)
                prevTime = 1;
        }
    }
    for (size_t i = INT_IN_STRUCT * 11 - 1; i >= 0; i--)
    {
        printf("%d", outS->data[i]);
    }
    printf("\n");
}

void printBigIntBinary(uint_1024 *s)
{
    for (int z = 0; z < INT_IN_STRUCT; z++)
    {
        for (int bit = 0; bit < sizeof(int) * 8; bit++)
        {
            if (1 << bit & s->data[z])
            {
                printf("1");
            }
            else
                printf("0");
        }
    }
    printf("\n");
}

uint_1024 *scanBigInt()
{
    char s[1000];
    scanf("%s", s);
    int len = strlen(s);
    uint_1024 *res = initBigInt();
    uint_1024 *ten = createBigInt(10);
    uint_1024 *power = createBigInt(1);
    printf("%d\n", len);
    fflush(stdout);
    for (int i = len - 1; i >= 0; i--)
    {
        res = sum(res, mul(createBigInt(s[i] - '0'), power));
        // printBigIntBinary(res);
        printf("%d\n", i);
        power = mul(power, ten);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    uint_1024 *d = createBigInt(5);
    uint_1024 *dd = createBigInt(32);

    if (1 << 2 & 4)
        printf("lol");
    if (1 << 2 & 5)
        printf("lol");
    if (1 << 2 & 3)
        printf("lol");
    uint_1024 *ddd = scanBigInt();
    printBigIntBinary(ddd);
    // printBigIntBinary(mul(sum(mul(d, dd), d), d));
    return 0;
}
