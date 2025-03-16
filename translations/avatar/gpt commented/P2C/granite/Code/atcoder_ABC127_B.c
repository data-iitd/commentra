
#include <stdio.h>

int main() {
    // Read input values for r, D, and x from the user
    double r, D, x;
    scanf("%lf %lf %lf", &r, &D, &x);

    // Iterate over a range of values from 2 to 11 (inclusive)
    for (int i = 2; i <= 11; i++) {
        // Calculate and print the result based on the formula
        // The formula computes a value using the current iteration index i,
        // the input values r, D, and x, and prints the integer result
        printf("%d\n", (int)((r ** (i - 1)) * (x + D / (1 - r)) - D / (1 - r)));
    }

    return 0;
}
