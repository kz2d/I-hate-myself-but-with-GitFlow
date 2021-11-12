#include <stdio.h>
#include <stdlib.h>
#include "settings.h"

int main(int argc, char *argv[])
{
    SETTINGS *settings = createSettings(argc, argv);
    printSettings(settings);
    FILE *opendFile = fopen(settings->fileName, "r");
    int line_count = 0;
    int word_count = 0;
    int char_count = 0;
    int in_word = 1;
    char ch;

    while ((ch = fgetc(opendFile)) != EOF)
    {
        char_count++;

        if (ch == ' ' || ch == '\t' || ch == '\n')
        {

            if (in_word)
            {
                in_word = 0;
                word_count++;
            }

            if (ch == '\n')
                line_count++;
        }
        else
        {
            in_word = 1;
        }
    }
    if (in_word)
    {
        word_count++;
    }

    if (settings->SHOW_FILE_SIZE)
        printf("file size in bytes = %d\n", char_count);
    if (settings->SHOW_LINES_COUNT)
        printf("lines count = %d\n", line_count);
    if (settings->SHOW_WORDS_COUNT)
        printf("word count = %d\n", word_count);

    fclose(opendFile);
    return 0;
}