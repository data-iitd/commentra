#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double input;
    double countOdd;
    double result;

    // Read input from standard input
    if (scanf("%lf", &input) != 1) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    // Calculate the number of odd numbers in the input
    countOdd = round(input / 2);

    // Calculate the result
    result = countOdd / input;

    // Print the result
    printf("%.10f\n", result);

    return EXIT_SUCCESS;
}

