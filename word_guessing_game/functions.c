#include <stdio.h>
#include "functions.h"

/**
 * Function Name: open_file
 * Purpose: This function opens the file and returns the open file address.
 * 
 * Parameter(s):
 *  filename: A string containing the filename path.
 *  mode: A string containing the mode that the file will be opened in.
 * 
 * Return Value(s):
 *  Returns NULL if the file doesn't open.
 *  Returns the pointer to the open file.
 * 
 * Side Effect(s):
 *  None.
 */

FILE *open_file(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);

    if(fp == NULL) {
        return NULL;
    }

    return fp;
}

/**
 * Function Name: print_menu
 * Purpose: This function prints the menu for the game.
 * 
 * Parameter(s):
 *  None.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the menu to the console for the user.
 */

void print_menu(void) {
    printf("\n--- Word Guessing Game ---\n");
    printf("Rules:\n\t1. Enter 5 Letter word\n\t2. You get 5 guesses, after your 5th guess if you don't get it, you lose\n\t3. Have fun!\n\n");
}

/**
 * Function Name: print_menu
 * Purpose: This function prints the menu for the game.
 * 
 * Parameter(s):
 *  None.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the menu to the console for the user.
 */

char *generate_word() {
    return NULL;
}