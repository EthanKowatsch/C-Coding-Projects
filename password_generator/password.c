#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "password.h"

/** 
 * Function Name: get_rand_num
 * Purpose: This function is a helper function to get a random number between a min and a max value.
 * 
 * Parameter(s):
 *  min: An integer number that represents the minimum number the random number can return.
 *  max: An integer number that represents the maximum number the random number can return.
 * 
 * Return Value(s):
 *  Returns an random integer value between the minimum and maximum number.
 * 
 * Side Effect(s):
 *  None.
 */

int get_rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/** 
 * Function Name: generate_password
 * Purpose: This function randomly generates a password using randomly generated characters, numbers and symbols.
 * 
 * Parameter(s):
 *  password: A string pointer to store the newly generated password.
 *  length: An integer value storing the length the password should be.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Modifies the pointer storing the newly generated password.
 */

void generate_password(char *password, int length) {
    int ascii_value = 0;
    int min = 33, max = 126;

    // Loop generating a new ascii value to put in the password that can be any character, number, or symbol
    for(int i = 0; i < length; i++){
        // Get random value to represent the new character, number, or symbol being added to the password
        ascii_value = get_rand_num(min, max);

        // Convert the ascii value randomly generated to a char and put it in the password
        password[i] = (char)ascii_value;
    }

    // Null terminate the password
    password[length - 1] = '\0';
}