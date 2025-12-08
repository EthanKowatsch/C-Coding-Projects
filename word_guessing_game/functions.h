#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define MAX_WORD_LENGTH 10
#define FILENAME "word_list.txt"

FILE *open_file(const char *filename, const char *mode);
int get_word_list_length(FILE *fp);
char **load_word_db(FILE *fp, int len);
void print_menu();
char *generate_word(char **word_list, int len);
void check_word(char *guessed_word, char *word, int word_length, char *correct_place_letters, char *wrong_place_letters, char *incorrect_letters);

#endif