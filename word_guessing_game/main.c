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

        // Reset has won variable
        bool has_won = false;

        int total_index = 0;

        // Generate new word
        char word[MAX_WORD_LENGTH];
        strcpy(word, generate_word(word_list, length_word_list));

        // Arrays to track the letters
        char accumulated_correct[6] = "_____";
        accumulated_correct[5] = '\0';

        // Add array to track all letters guessed
        char letters_guessed[26];

        // Loop getting user response
        int guess_count = 0;
        do {
            // Prompt user for their guess
            char guess[MAX_WORD_LENGTH];
            
            char correct_place_letters[6] = ""; // Can only have 5 correct letters
            char wrong_place_letters[6] = ""; // Can only have 5 wrong place letters
            char incorrect_letters[22] = ""; // 26 letters in alphabet, 5 of them must be in the word so we don't need space for all 26 letters

            correct_place_letters[0] = '\0';
            wrong_place_letters[0] = '\0';
            incorrect_letters[0] = '\0';

            printf("\n\nEnter word guess %d: ", guess_count + 1);
            fgets(guess, sizeof(guess), stdin);
            guess[strcspn(guess, "\n")] = '\0';

            // Check if word guessed is 5 letters long
            if(strlen(guess) != 5) {
                printf("\nIncorrect Guess: Word must be 5 letters\n");
                continue;
            }

            int word_length = 0 ;
            word_length = strlen(guess);

            // Use the check word function to determine the result of the guessed word
            check_word(guess, word, word_length, correct_place_letters, wrong_place_letters, incorrect_letters);

            // Feature to track all the letters guessed each turn
            for(int i = 0; i < word_length; i++) {
                // Check if this letter is already in letters_guessed
                bool already_guessed = false;
                for(int j = 0; j < total_index; j++) {
                    if(tolower(guess[i]) == letters_guessed[j]) {
                        already_guessed = true;
                        break;
                    }
                }
                
                // Only add if not already in the array
                if(!already_guessed) {
                    letters_guessed[total_index] = tolower(guess[i]);
                    total_index++;
                }
            }

            letters_guessed[total_index] = '\0';

            // Loop to only output correct letters
            for(int i = 0; i < 5; i++) {
                if(correct_place_letters[i] != '_') {
                    accumulated_correct[i] = correct_place_letters[i];
                }
            }

            // Output whats right and wrong to user
            printf("\nGuess: %s", guess);

            // Output of correctly placed letters
            int length_right_letters = strlen(correct_place_letters);
            printf("\nCorrect Letters: ");
            for(int i = 0; i < length_right_letters; i++) {
                printf("%c ", accumulated_correct[i]);
            }

            // Output of wrongly placed letters
            int length_wrong_letters = strlen(wrong_place_letters);
            printf("\nRight Letters, Wrong Place: ");
            for(int i = 0; i < length_wrong_letters; i++) {
                printf("%c ", wrong_place_letters[i]);
            }

            // Output of wrong letters
            int length_incorrect_letters = strlen(incorrect_letters);
            printf("\nWrong letters: ");
            for(int i = 0; i < length_incorrect_letters; i++) {
                printf("%c ", incorrect_letters[i]);
            }

            // Output of all letters guessed total
            int length_all_letters = strlen(letters_guessed);
            printf("\nAll letters Guessed: ");
            for(int i = 0; i < length_all_letters; i++) {
                if((i + 1) == length_all_letters) {
                    printf("%c ", letters_guessed[i]);
                }
                else {
                    printf("%c, ", letters_guessed[i]);
                }
            }
        
            guess_count++;

            // Check if all 5 letters are in the correct place array meaning the user got all 5 letters correct
            if(strcmp(accumulated_correct, word) == 0) {
                has_won = true;
                break;
            }
        } while(guess_count < 5);

        // Check if the user won
        if(has_won == true) {
            printf("\n\nUser won - Total Guesses: %d Word was: %s\n", guess_count, word);
        }
        else {
            printf("\n\nUser lost - Word was: %s\n", word);
        }

        // Determine next action from user after game is over
        char user_response_buff[10];
        char user_response;
        printf("Play again? (y / n): ");
        fgets(user_response_buff, sizeof(user_response_buff), stdin);
        sscanf(user_response_buff, "%c", &user_response);

        // Check user's response
        user_response = tolower(user_response);
        if(user_response == 'n') {
            is_playing = false;
        }
    }

    // Free each word and the array
    for(int i = 0; i < length_word_list; i++) {
        free(word_list[i]);
    }

    free(word_list);

    printf("\nThank you for playing!\nAll memory freed.\n");

    fclose(fp);

    return 0;
}