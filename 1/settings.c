#include "settings.h"
#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

SETTINGS *createSettings(int argc, char **argv)
{
    SETTINGS *settings;
    settings = malloc(sizeof(SETTINGS));
    const char *short_options = "lwc";

    const struct option long_options[] = {
        {"lines", 2, NULL, 'l'},
        {"words", 2, NULL, 'w'},
        {"bytes", 2, NULL, 'c'},
        {NULL, 0, NULL, 0}};
    int rez;
    while ((rez = getopt_long(argc, argv, short_options,
                              long_options, NULL)) != -1)
    {

        switch (rez)
        {
        case 'w':
        {
            settings->SHOW_WORDS_COUNT = 1;
            break;
        };
        case 'l':
        {
            settings->SHOW_LINES_COUNT = 1;
            break;
        };

        case 'c':
        {
            settings->SHOW_FILE_SIZE = 1;
            break;
        };
        default:
        {
            printf("found unknown option\n");
            break;
        };
        };
    };

    settings->fileName = argv[argc - 1];
    return settings;
}

void printSettings(SETTINGS *settings)
{
    printf("SHOW_WORDS_COUNT=%d\n", settings->SHOW_WORDS_COUNT);
    printf("SHOW_LINES_COUNT=%d\n", settings->SHOW_LINES_COUNT);
    printf("SHOW_FILE_SIZE=%d\n", settings->SHOW_FILE_SIZE);

    printf("fileName=%s\n", settings->fileName);
}