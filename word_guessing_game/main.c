#include <stdio.h>

#include "functions.h"

int main(void) {
    // Open file and save pointer to it's location
    FILE *fp = open_file(FILENAME, "r");

    if(fp == NULL) {
        printf("Error opening word file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];

    print_menu();

    fclose(fp);

    return 0;
}