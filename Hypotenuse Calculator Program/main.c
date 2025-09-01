#include <stdio.h>
#include <math.h>

int main() {

    // Create variables for the sides of the triangle
    double side1;
    double side2;

    // Ask user for the lengths of the two sides
    printf("Enter Length of Side 1: ");
    scanf("%lf", &side1);
    printf("Enter Length of Side 2: ");
    scanf("%lf", &side2);

    // Calculate the hypotenuse
    double hypotenuse = pow(side1, 2) + pow(side2, 2);
    hypotenuse = sqrt(hypotenuse);

    printf("The hypotenuse length is %.2lf units\n", hypotenuse);

    return 0;
}