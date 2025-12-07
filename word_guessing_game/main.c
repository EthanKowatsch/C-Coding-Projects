#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "functions.h"

int main(void) {
    // Open file and save pointer to it's location
    FILE *fp = open_file(FILENAME, "r");

    if(fp == NULL) {
        printf("Error opening word file.\n");
        return 1;
    }

    // Get length of word list and rewind file
    int length_word_list = get_word_list_length(fp);
    rewind(fp);

    // Allocate word list
    char **word_list = load_word_db(fp, length_word_list);

    if(word_list == NULL) {
        printf("Error loading database of words.\n");
        return 1;
    }

    // Ensure randomization when generating word
    srand(time(NULL));

    // Loop game until user chooses to exit
    bool is_playing = true;
    while(is_playing) {
        // Print menu for user
        print_menu();

        // Generate new word
        char word[MAX_WORD_LENGTH];
        strcpy(word, generate_word(word_list, length_word_list));

        // Loop getting user response

        // Determine next action from user after game is over
        char user_response_buff[10];
        char user_response;
        printf("Play again? (y / n): ");
        fgets(user_response_buff, sizeof(user_response_buff), stdin);
        sscanf(user_response_buff, "%c", &user_response);

        user_response = tolower(user_response);

        if(user_response == 'n') {
            is_playing = false;
        }
    }

    // Free each word
    for(int i = 0; i < length_word_list; i++) {
        free(word_list[i]);
    }
    // Free the array itself
    free(word_list);

    printf("\nThank you for playing!\nAll memory freed.\n");

    fclose(fp);

    return 0;
}