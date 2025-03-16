#include <stdio.h>

int main() {
    int r, D, x; // Declare integer variables for radius, D, and x
    scanf("%d %d %d", &r, &D, &x); // Read three integers from standard input

    for (int i = 1; i <= 10; i++) { // Loop 10 times
        printf("%d\n", r * x - D); // Print the result of the calculation
        x = r * x - D; // Update x for the next iteration
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
