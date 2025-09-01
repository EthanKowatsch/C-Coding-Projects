#include <stdio.h>
#include <math.h>

int main() {

    // Create a value for pi
    const double PI = 3.14159;
    double radius;

    // Ask user to input the radius of the circle
    printf("Enter radius of the circle: ");
    scanf("%lf", &radius);

    // Calculate the circumference
    double circumference = 2* radius * PI;

    // Calculate the area of the circle
    double area = PI * pow(radius, 2);

    // Output the circumference to the user
    printf("The circumference of the circle is: %.2lf units\n", circumference);
    printf("The area of the circle is: %.2lf units\n", area);

    return 0;
}