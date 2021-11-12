#ifndef SETTINGS_H
#define SETTINGS_H

typedef struct settings_struct
{
    int SHOW_WORDS_COUNT;
    int SHOW_LINES_COUNT;
    int SHOW_FILE_SIZE;
    char *fileName;
} SETTINGS;

SETTINGS *createSettings(int argc, char **argv);
void printSettings(SETTINGS *settings);

#endif