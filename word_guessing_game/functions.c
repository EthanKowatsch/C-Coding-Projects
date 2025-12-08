#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

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
 * Function Name: get_word_list_length
 * Purpose: This function gets the total length of the word list.
 * 
 * Parameter(s):
 *  fp: A pointer to the word textfile.
 * 
 * Return Value(s):
 *  Returns the line count.
 * 
 * Side Effect(s):
 *  None.
 */

int get_word_list_length(FILE *fp) {
    char line[MAX_WORD_LENGTH];

    int line_count = 0;

    while(fgets(line, sizeof(line), fp) != NULL) {
        line_count++;
    }

    return line_count;
}

/**
 * Function Name: load_word_db
 * Purpose: This function loads the word list into memory and an array.
 * 
 * Parameter(s):
 *  fp: A pointer to the word textfile.
 *  len: An integer storing the length of the array of words.
 * 
 * Return Value(s):
 *  Returns the dynamically allocated word list.
 * 
 * Side Effect(s):
 *  None.
 */

char **load_word_db(FILE *fp, int len) {
    // Allocate memory for words list
    char **arr_words = malloc(len * sizeof(char *));

    if(arr_words == NULL) {
        return NULL;
    }

    char line[MAX_WORD_LENGTH];

    int i = 0;

    while(fgets(line, sizeof(line), fp) != NULL){
        // Dynamically allocate memory for each word
        arr_words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
        
        if(arr_words[i] == NULL) {
            // Free all previously allocated words
            for(int j = 0; j < i; j++) {
                free(arr_words[j]);
            }
            // Free the array itself
            free(arr_words);

            return NULL;
        }

        // Copy word to array spot
        line[strcspn(line, "\n")] = '\0';
        strcpy(arr_words[i], line);

        // Increment the index
        i++;
    }

    return arr_words;
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
 * Function Name: generate_word
 * Purpose: This function generates the word to be guessed by the user.
 * 
 * Parameter(s):
 *  fp: A pointer the the word textfile.
 *  len: An integer representing the length of the list.
 * 
 * Return Value(s):
 *  Returns a newly generated word from the list.
 * 
 * Side Effect(s):
 *  None.
 */

char *generate_word(char **word_list, int len) {
    // Generate random index for a word
    int random_word_index = rand() % len;
    // TODO: REMOVE
    printf("DEBUG: Index=%d, Len=%d, Word='%s'\n", random_word_index, len, word_list[random_word_index]);
    return word_list[random_word_index];
}

/**
 * Function Name: 
 * Purpose: This function checks the word guessed by the user.
 * 
 * Parameter(s):
 *  fp: A pointer the the word textfile.
 *  len: An integer representing the length of the list.
 * 
 * Return Value(s):
 *  Returns a newly generated word from the list.
 * 
 * Side Effect(s):
 *  None.
 */

void check_word(char *guessed_word, char *word, int word_length, char *correct_place_letters, char *wrong_place_letters, char *incorrect_letters) {
    // Loop through the word checking each letter to the letter in the right word seeing if any of the guess letters are right
    for(int i = 0; i < word_length; i++) {
        if(tolower(guessed_word[i]) == tolower(word[i])) {
            correct_place_letters[i] = tolower(guessed_word[i]);
        }
        else {
            correct_place_letters[i] = '_';
        }
    }

    // TODO: Add wrong position and incorrect letter logic
}