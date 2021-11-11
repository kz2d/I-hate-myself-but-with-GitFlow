#ifndef VECTOR_H
#define VECTOR_H

typedef struct vectorr
{
    int start;
    int end;
    int *data;
    int size;
} VECTOR;

VECTOR *createVector(int size);
void printVector(VECTOR *vector);
int popVector(VECTOR *vector);
VECTOR *pushToVector(VECTOR *vector, int item);
void copyEndToStart(VECTOR *vector);
int len(VECTOR *vector);

#endif