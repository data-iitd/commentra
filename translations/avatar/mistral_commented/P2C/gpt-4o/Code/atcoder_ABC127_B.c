#include <stdio.h>
#include <math.h>

int main() {
    // Take three integers as input from the user
    int r, D, x;
    scanf("%d %d %d", &r, &D, &x);

    // Iterate through the range of numbers from 2 to 11 (12 is excluded)
    for (int i = 2; i < 12; i++) {
        // Calculate the expression and print the integer result
        double result = pow(r, i - 1) * (x + D / (1.0 - r)) - D / (1.0 - r);
        printf("%d\n", (int)round(result));
    }

    return 0;
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)
// <END-OF-CODE>
