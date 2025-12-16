#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "password.h"

int main(void) {
    // Enure randomization when generating each value
    srand(time(NULL));

    printf("\n--- Password Generator ---\n");

    // Get the length of the password from the user
    int length_password = 0;
    char password_input_buff[100];

    printf("\nEnter length of new password: ");
    fgets(password_input_buff, sizeof(password_input_buff), stdin);
    sscanf(password_input_buff, "%d", &length_password);

    if(length_password <= 1 || length_password > 100) {
        printf("\nIncorrect password length. Must be greater than 1 or less than 101.\n");
        return 1;
    }

    // Allocate enough memory for the new password
    char *new_password = malloc(length_password + 1 * sizeof(char));

    if(new_password == NULL) {
        printf("\nError allocating memory.\n");
        return 1;
    }

    // Generate new password for user
    generate_password(new_password, length_password + 1);

    printf("\nYour new password could be: %s\n", new_password);

    // Free password memory
    free(new_password);

    return 0;
}