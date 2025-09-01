#include <stdio.h>
#include <math.h>

int main() {

    char operator;
    double num1;
    double num2;
    double result;

    printf("Enter operation (+, -, x, /, ^):");
    scanf("%c", &operator);

    printf("Enter Number 1:");
    scanf("%lf", &num1);
    
    printf("Enter Number 2:");
    scanf("%lf", &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("\n%.2lf + %.2lf = %.2lf", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("\n%.2lf - %.2lf = %.2lf", num1, num2, result);
        break;
    case 'x':
        result = num1 * num2;
        printf("\n%.2lf x %.2lf = %.2lf", num1, num2, result);
        break;
    case '/':
        result = num1 / num2;
        printf("\n%.2lf / %.2lf = %.2lf", num1, num2, result);
        break;
    case '^':
        result = pow(num1, num2);
        printf("\n%.2lf ^ %.1lf = %.2lf", num1, num2, result);
        break;
    default:
        printf("Please enter valid numbers and symbols.");
        break;
    }

    return 0;
}