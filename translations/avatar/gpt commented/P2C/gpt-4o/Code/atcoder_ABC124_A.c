#include <stdio.h>

int main() {
    int a, b, c = 0;

    // Read two integers from input and assign them to variables a and b
    scanf("%d %d", &a, &b);

    // Loop for 2 iterations
    for (int i = 0; i < 2; i++) {
        // Add the maximum of a and b to c
        c += (a > b) ? a : b;

        // Decrease the larger of the two numbers (a or b) by 1
        if (a >= b) {
            a--;  // If a is greater than or equal to b, decrement a
        } else {
            b--;  // Otherwise, decrement b
        }
    }

    // Print the final accumulated value of c
    printf("%d\n", c);

    return 0;
}

// <END-OF-CODE>
