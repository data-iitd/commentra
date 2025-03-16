#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double input;
    if (scanf("%lf", &input) != 1) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    double countOdd = round(input / 2);
    double result = countOdd / input;

    // Print result with 10 decimal places
    printf("%.10f\n", result);

    return 0;
}

// <END-OF-CODE>
