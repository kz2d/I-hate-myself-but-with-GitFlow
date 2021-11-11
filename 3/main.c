#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "vector.h"

int calculateTime(char *log)
{
    char *index = strpbrk(log, ":") + 1;
    char buffer[4];
    strncpy(buffer, index, 3);
    buffer[3] = '\0';
    int time = atoi(buffer);

    index += 3;
    strncpy(buffer, index, 3);
    buffer[3] = '\0';
    time = time * 60 + atoi(buffer);

    index += 3;
    strncpy(buffer, index, 3);
    buffer[3] = '\0';
    time = time * 60 + atoi(buffer);
    index = strpbrk(log, "[") + 1;
    strncpy(buffer, index, 3);
    buffer[3] = '\0';
    time += atoi(buffer) * 24 * 60 * 60;
    printf("%d", time);
    return time;
}

int main(int argc, char *argv[])
{

    printf("%s\n", argv[argc - 1]);
    fflush(stdout);
    VECTOR *vector = createVector(50);
    char *fileName = argv[argc - 1];
    FILE *opendFile = fopen(fileName, "r");
    if (opendFile == NULL)
    {
        printf("Oops");
        exit(10);
    }
    printf("%c", fgetc(opendFile));
    fflush(stdout);
    int lineSize = 1;
    char *line = malloc(sizeof(char) * lineSize);
    int lastComma = 0;
    char ch;
    int iter = 0;
    int windowSize = 200;
    int lines = 0;
    int day = 0;
    int maxItemsInWindow = 0;
    while ((ch = (char)fgetc(opendFile)) != EOF)
    {
        line[iter] = ch;
        if (iter >= lineSize - 1)
        {
            lineSize *= 2;
            char *buffer = malloc(lineSize * sizeof(char));
            strcpy(buffer, line);
            free(line);
            line = buffer;
        }
        if (ch == '\n')
        {
            line[iter + 1] = '\0';
            lines++;
            if (line[lastComma + 2] == '5')
            {
                printf("%s\n", line);
            }
            fflush(stdout);

            int time = calculateTime(line);
            if (time < vector->data[vector->end - 1])
            {
                day++;
                time = calculateTime(line);
            }

            while (len(vector) > 0 && (vector->data[vector->start] + windowSize < time || vector->data[vector->start] > time))
            {
                popVector(vector);
            }

            vector = pushToVector(vector, time);

            if (len(vector) > maxItemsInWindow)
                maxItemsInWindow = len(vector);

            iter = -1;
        }
        if (ch == '\"')
            lastComma = iter;
        iter++;
    }
    printf("maximum items in window = %d\n", maxItemsInWindow);
    fclose(opendFile);
    return 0;
}