#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"

int main(void) {
    // Open file and save pointer to it's location
    FILE *fp = open_file(FILENAME, "r");

    if(fp == NULL) {
        printf("Error opening word file.\n");
        return 1;
    }

    bool is_playing = true;

    while(is_playing) {
        // Print menu for user
        print_menu();


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

    printf("\nThank you for playing!\n");

    fclose(fp);

    return 0;
}