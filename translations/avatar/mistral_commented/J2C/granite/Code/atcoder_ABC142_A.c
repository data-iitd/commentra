

#include <stdio.h> // Include standard input/output library
#include <math.h> // Include mathematical library
#include <stdlib.h> // Include standard library

int main() {
    double input; // Declare input variable as a double
    double countOdd; // Declare countOdd variable as a double
    double result; // Declare result variable as a double

    // Read input from standard input
    if (scanf("%lf", &input)!= 1) { // Check if input is successfully read
        fprintf(stderr, "Error: Invalid input\n"); // Print error message if input is invalid
        exit(1); // Exit the program with a non-zero status code
    }

    // Calculate the number of odd numbers in the input
    countOdd = round(input / 2);

    // Calculate the result
    result = countOdd / input;

    // Print the result
    printf("%.10lf\n", result); // Print the result with 10 decimal places

    return 0; // Return a zero status code
}

