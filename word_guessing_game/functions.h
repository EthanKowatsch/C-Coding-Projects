#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define MAX_WORD_LENGTH 5
#define FILENAME "word_list.txt"

FILE *open_file(const char *filename, const char *mode);
void print_menu();
char *generate_word();

#endif