#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Prototyped functions
double deposit(double, double);
double withdraw(double, double);
void showAccountSummary(double, const char[]);

int main() {

    // Starting balance variable
    double balance = 0;
    char accountName[100];
    bool isActive = true;

    // Get users account name
    printf("\nEnter Account Name: ");
    fgets(accountName, sizeof(accountName), stdin);
    // Removes new line
    size_t len = strlen(accountName);
    if (len > 0 && accountName[len - 1] == '\n') {
        accountName[len - 1] = '\0';
    }

    // Get users starting balance
    printf("\nEnter Starting Balance: ");
    scanf("%lf", &balance);
    // To get rid of new line to prevent an entry to the 
    getchar();
    
    // Loop options while user wants to access account
    while(isActive) {
        // Save user's choice in a variable
        char userChoice;
        // Allow the user to choose what they want to do
        printf("\nWhat would you like to do to %s? (Type: D - Deposit, W -  Withdraw, S - Show Account Total, E - Exit Program): ", accountName);
        scanf("%c", &userChoice);
        getchar();

        // Switch statement to decide which function to perform
        switch (userChoice)
        {
        case 'D': {
            // Create variable for amount to withdraw
            double depositAmount;

            // Prompt user to enter the amount
            printf("\nHow much would you like to deposit: ");
            scanf("%lf", &depositAmount);
            getchar();

            // Call function to deposit
            balance = deposit(balance, depositAmount);
            break;
        }
        case 'W': {
            // Create variable for amount to withdraw
            double withdrawAmount;

            // Prompt user to enter the amount
            printf("\nHow much would you like to withdraw: ");
            scanf("%lf", &withdrawAmount);
            getchar();

            // Call function to withdraw
            balance = withdraw(balance, withdrawAmount);
            break;
        }    
        case 'S':
            // Show the account summary
            showAccountSummary(balance, accountName);
            break;
        case 'E':
            isActive = false;
            printf("\nThank you for using the program!");
            break;
        default:
            printf("Please enter valid inputs (Type: D - Deposit, W -  Withdraw, S - Show Account Total).");
            break;
        }
    }
        
    return 0;
}

// Function to deposit amount
double deposit(double userBalance, double depositAmount){
    // Update the user's balance after the deposit
    double updatedUserBalance = userBalance + depositAmount;
    return updatedUserBalance;
}

//Function to withdraw amount
double withdraw(double userBalance, double withdrawAmount) {
    // Update the user's balance after the withdrawal
    double updatedUserBalance = userBalance - withdrawAmount;
    return updatedUserBalance;
}

// Function to show account summary
void showAccountSummary(double userBalance, const char accountName[]) {
    // Print the user's balance
    printf("================== \n%s Current Balance: \n$%.2lf\n==================", accountName, userBalance);
}