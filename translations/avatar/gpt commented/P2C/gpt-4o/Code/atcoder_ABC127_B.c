#include <stdio.h>
#include <math.h>

int main() {
    int r, D, x;

    // Read input values for r, D, and x from the user
    scanf("%d %d %d", &r, &D, &x);

    // Iterate over a range of values from 2 to 11 (inclusive)
    for (int i = 2; i <= 11; i++) {
        // Calculate and print the result based on the formula
        // The formula computes a value using the current iteration index i,
        // the input values r, D, and x, and prints the integer result
        int result = (int)(pow(r, i - 1) * (x + (double)D / (1 - r)) - (double)D / (1 - r));
        printf("%d\n", result);
    }

    return 0;
}

// <END-OF-CODE>
