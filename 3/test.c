#include "vector.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    VECTOR *vector = createVector(10);
    printVector(vector);
    pushToVector(vector, 5);
    pushToVector(vector, 6);
    pushToVector(vector, 7);
    printVector(vector);
    printf("lol=%d\n", popVector(vector));
    printVector(vector);
    vector->start = 98;
    vector->end = 98;
    for (int i = 0; i < 5; i++)
    {
        pushToVector(vector, i);
        printVector(vector);
    }
    int z = atoi("68 ");
    printf("lol=%d\n", atoi("054s"));

    printf("lol=%d\n", z);
    char *day = 0, hour = 0, minutes = 0, statusCode = 0;
    // char *a = "205.189.154.54 - - [01/Jul/1995:01:02:06 -0400] \" GET / cgi - bin / imagemap / countdown ? 99, 176 HTTP / 1.0 \" 302 110";
    char *a = "3|1|2|3|0";
    // sscanf(a, "%s - - [%d/%s:%d:%d:%s] \"%s\" %d %d", NULL, day, NULL, hour, minutes, NULL, NULL, statusCode, NULL);
    sscanf(a, "3|%s|%s|%s|0", day, hour, minutes);
    printf(" %s %s %s ", day, hour, minutes);
    return 0;
}
