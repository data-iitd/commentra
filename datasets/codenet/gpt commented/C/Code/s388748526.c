#include <stdio.h>  // Include standard input-output library
#include <math.h>   // Include math library for mathematical constants and functions

int main() {
    double r;  // Declare a variable to store the radius

    // Prompt the user to input the radius
    printf("Enter the radius: ");
    scanf("%lf", &r);  // Read the radius from user input

    // Calculate and print the area and circumference of the circle
    // Area = π * r^2
    // Circumference = 2 * π * r
    printf("%lf %lf\n", r * r * M_PI, 2 * M_PI * r);

    return 0;  // Return 0 to indicate successful execution
}
