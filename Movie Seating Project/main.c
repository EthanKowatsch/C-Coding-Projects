#include <stdio.h>
#include <stdbool.h>

void resetSeatingBoard(int, int);

int main() {

    // Initialize board
    int seatingBoard[5][5];
    bool pickingSeat = true;
    
    // Get row and column length of the 2D array
    int rowNum = sizeof(seatingBoard) / sizeof(seatingBoard[0]);
    int colNum = sizeof(seatingBoard[0]) / sizeof(seatingBoard[0][0]);

    // Reset the board to the basic form
    resetSeatingBoard(rowNum, colNum);

    // Loop to allow the users to pick the seats
    while(pickingSeat) {
        // Variable to store user's choice
        char userChoice;

        // Ask user for their choice
        printf("What would you like to do? (Type: B - Book seat, S - Show seating available)");
        scanf("%c", &userChoice);

        
    }

    return 0;
}

// Function for reseting the seating board back to normal
void resetSeatingBoard(int r, int c) {
    printf("  Movie Theatre Seating\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
        {
            if(j == 0) {
                printf("Row %d. O ", i + 1);
            }
            else if(j + 1 == c) {
                printf("| O");
            }
            else {
                printf("| O ");
            }
            
        }
        printf("\n");
        if(i < r - 1) {
            printf("-------------------------");
            printf("\n");
        }
    }
}