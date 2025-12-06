#include <stdio.h>
#include "functions.h"

FILE *open_file(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);

    if(fp == NULL) {
        return NULL;
    }

    return fp;
}

void print_menu(void) {
    printf("--- Word Guessing Game ---\n");
    printf("Rules:\n\t1. Enter 5 Letter word\n\t2. You get 5 guesses, after your 5th guess if you don't get it, you lose\n\t3. Have fun!\n\n");
}

char *generate_word() {

}