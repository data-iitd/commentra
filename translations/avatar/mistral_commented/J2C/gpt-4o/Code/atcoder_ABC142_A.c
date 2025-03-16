#include <stdio.h>      // Include standard input/output library
#include <stdlib.h>     // Include standard library for memory allocation and conversion
#include <math.h>       // Include math library for mathematical functions

int main() {
    double input;      // Variable to store the input
    double countOdd;   // Variable to store the count of odd numbers
    double result;     // Variable to store the final result

    // Try to read input and perform calculations
    if (scanf("%lf", &input) != 1) { // Read input as a double
        fprintf(stderr, "Invalid input\n"); // Print error message for invalid input
        return 1; // Exit with error status
    }

    // Calculate the number of odd numbers in the input
    countOdd = round(input / 2);

    // Calculate the result as a fraction of countOdd and input
    result = countOdd / input;

    // Print the result with 10 decimal places
    printf("%.10f\n", result);

    return 0; // Exit with success status
}

// <END-OF-CODE>
