#include <stdio.h>
#include <ctype.h>

int main() {

    char unit;
    float temp;

    printf("Enter the unit of temperature (F or C):");
    scanf(" %c", &unit);

    // Always uppercase your letters to prevent case sensitivity
    unit = toupper(unit);

    printf("Enter the temperature in %c:", unit);
    scanf("%f", &temp);

    switch (unit)
    {
        // F to C
        case 'F': {
            float celsiusTemp = (temp - 32) * (5.0 / 9.0);
            printf("The temp in C: %.1f°C", celsiusTemp);
            break;
        }
        // C to F
        case 'C': {
            float fahrenheitTemp = (temp * (9.0 / 5.0)) + 32;
            printf("The temp in F: %.1f°F", fahrenheitTemp);
            break;
        } 
        default:
            printf("Please enter a valid unit");
            break;
    }

    return 0;
}