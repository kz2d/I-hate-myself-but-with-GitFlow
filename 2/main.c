#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *s;
    scanf("%s", s);
    printf("%s\n", s);
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }

    return 0;
}
