#include <stdio.h>  // Include standard input-output library

int main() {  // Entry point of the C application
    int a, b;  // Declare variables for the two integers
    scanf("%d %d", &a, &b);  // Read two integers from standard input

    int sum = 0;  // Initialize sum variable to 0

    for (int i = 0; i < 2; i++) {  // Iterate through two iterations
        if (a >= b) {  // Check if a is greater than or equal to b
            sum += a;  // Add a to sum
            a--;  // Decrement a by 1
        } else {
            sum += b;  // Add b to sum
            b--;  // Decrement b by 1
        }
    }

    printf("%d\n", sum);  // Print the value of sum to standard output
    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>
