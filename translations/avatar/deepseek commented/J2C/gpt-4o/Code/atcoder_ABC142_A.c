#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Main function is the entry point of the program
int main() {
    // Variable to hold the input
    double input;
    
    // Reading a double value from the input
    if (scanf("%lf", &input) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1; // Exit with error code
    }

    // Calculating the number of odd numbers up to the given input
    double countOdd = round(input / 2);

    // Using double to handle decimal calculations
    double result = countOdd / input;

    // Printing the result with 10 decimal places
    printf("%.10f\n", result);

    return 0; // Successful termination
}

// <END-OF-CODE>
