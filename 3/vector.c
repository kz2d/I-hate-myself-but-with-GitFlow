#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

VECTOR *createVector(int size)
{
    VECTOR *vector;
    size_t arrayLength = 0;

    vector = malloc(sizeof(VECTOR));
    vector->end = arrayLength;
    vector->data = malloc(sizeof(int) * size);
    vector->size = size;
    return vector;
}

void freeVector(VECTOR *v)
{
    free(v->data);
    free(v);
}
void copyVector(VECTOR *from, VECTOR *to)
{
    for (int i = from->start; i < from->end; i++)
    {
        to->data[i] = from->data[i];
    }
    to->start = from->start;
    to->end = from->end;
}

int popVector(VECTOR *vector)
{
    if (vector->start == vector->end)
        return 0;
    vector->start++;
    return vector->data[vector->start - 1];
}

VECTOR *pushToVector(VECTOR *vector, int item)
{
    if (vector->size == vector->end)
    {
        if (vector->end - vector->start > vector->size * 3 / 4)
        {
            // printf("bingo");
            // fflush(stdout);
            VECTOR *buf = createVector(vector->size * 2);
            copyVector(vector, buf);
            freeVector(vector);
            // printVector(buf);
            vector = buf;
        }
        else
            copyEndToStart(vector);
    }

    vector->data[vector->end] = item;
    vector->end++;
    return vector;
}

void copyEndToStart(VECTOR *vector)
{
    for (int i = vector->start, z = 0; i < vector->end; z++, i++)
    {
        vector->data[z] = vector->data[i];
    }
    vector->end = vector->end - vector->start;
    vector->start = 0;
}
int len(VECTOR *vector) { return vector->end - vector->start; }

void printVector(VECTOR *vector)
{
    printf("[ ");
    for (int i = vector->start; i < vector->end; i++)
    {
        printf("%d, ", vector->data[i]);
    }
    printf("]");
    printf("  start=%d, end=%d  size=%d\n", vector->start, vector->end, vector->size);
}