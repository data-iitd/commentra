#include <stdio.h>

int main() {
    int r, D, x;

    // Read three integers from input: r, D, and x
    scanf("%d %d %d", &r, &D, &x);
    
    // Perform calculations and print the result for 10 iterations
    for (int i = 1; i <= 10; i++) {
        x = r * x - D; // Update x based on the formula
        printf("%d\n", x); // Print the current value of x
    }

    return 0;
}

// <END-OF-CODE>
