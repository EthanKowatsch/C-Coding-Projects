#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Prototyping the functions
void resetSeatingBoard(int r, int c, int seatingBoard[r][c]);
void printCurrentBoard(int r, int c, int seatingBoard[r][c]);
bool isSeatAvailable(int r, int c, int seatingBoard[r][c]);

int main() {

    // Initialize board
    int seatingBoard[5][5];
    bool pickingSeat = true;
    
    // Get row and column length of the 2D array
    int rowLen = sizeof(seatingBoard) / sizeof(seatingBoard[0]);
    int colLen = sizeof(seatingBoard[0]) / sizeof(seatingBoard[0][0]);

    // Reset the board to the basic form
    resetSeatingBoard(rowLen, colLen, seatingBoard);

    // Loop to allow the users to pick the seats
    while(pickingSeat) {
        // Variable to store user's choice
        char userChoice;

        // Ask user for their choice
        printf("\nWhat would you like to do? (Type: B - Book seat, S - Show seating available, E - Exit Program): ");
        scanf(" %c", &userChoice);

        switch (toupper(userChoice))
        {
        case 'B': {
            printf("Which seat would you like to book?\n");

            // Initialize a value for the row and column number the user wants
            int rowNum;
            int colNum;

            // Get user row and column
            printf("Enter Row Number: ");
            scanf(" %d", &rowNum);
            printf("Enter Column Number: ");
            scanf(" %d", &colNum);

            // Check if the seat is available
            if(isSeatAvailable(rowNum, colNum, seatingBoard)) {
                printf("Your seat is booked!");
                seatingBoard[rowNum - 1][colNum - 1] = 1;
            }
            else {
                printf("Seat is unavailable, please choose again.");
            }
            
            break;
        }
        case 'S':
            // Function to print the current board
            printCurrentBoard(rowLen, colLen, seatingBoard);
            break;
        case 'E':
            pickingSeat = false;
            break;
        default:
            printf("\nThe choice you made is incorrect, please try again.");
            break;
        }
    }

    printf("Thank you for using our program!");

    return 0;
}

// Function for reseting the seating board back to normal
void resetSeatingBoard(int r, int c, int seatingBoard[r][c]) {
    printf("  Movie Theatre Seating\n");

    // For loop to print the board to the seating
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
        {
            // Reset the values for each seat
            seatingBoard[i][j] = 0;
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

// Function to print the currect board if the user wants to view it
void printCurrentBoard(int r, int c, int seatingBoard[r][c]) {
    printf("  Movie Theatre Seating\n");
    
    // For loop to print the current board
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // Check if the currect row and column has a seat booked
            if(seatingBoard[i][j] == 1) {
                if(j == 0) {
                printf("Row %d. X ", i + 1);
                }
                else if(j + 1 == c) {
                    printf("| X");
                }
                else {
                    printf("| X ");
                }
            } 
            else {
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
        }
        
        printf("\n");
        if(i < r - 1) {
            printf("-------------------------");
            printf("\n");
        }
    }
    
}

bool isSeatAvailable(int r, int c, int seatingBoard[r][c]) {
    // Adjust for 1-based input from user
    int rowIdx = r - 1;
    int colIdx = c - 1;

    // Out of bounds check
    if (rowIdx < 0 || colIdx < 0) return false;

    // Check seat availability
    return seatingBoard[rowIdx][colIdx] == 0;
}