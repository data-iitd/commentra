#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double input;
    double countOdd;
    double result;

    // Reading a double value from the input
    if (scanf("%lf", &input) != 1) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    // Calculating the number of odd numbers up to the given input
    countOdd = round(input / 2);

    // Performing the division and setting the scale to 10
    result = countOdd / input;

    // Printing the result with a precision of 10 decimal places
    printf("%.10f\n", result);

    return EXIT_SUCCESS;
}

