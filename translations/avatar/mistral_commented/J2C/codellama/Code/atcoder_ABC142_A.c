
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double input;
    double countOdd;
    double result;

    // Read input from standard input
    scanf("%lf", &input);

    // Calculate the number of odd numbers in the input
    countOdd = round(input / 2);

    // Calculate the result
    result = countOdd / input;

    // Set the scale and rounding mode for the result
    result = round(result * 1000000000) / 1000000000;

    // Print the result
    printf("%.10lf\n", result);

    // End of code
    return 0;
}