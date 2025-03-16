// Import the standard input-output library
#include <stdio.h>

int main() {
    // Declare two integer variables "a" and "b"
    int a, b;

    // Read input values from the standard input
    scanf("%d %d", &a, &b);

    // Calculate the product of "a" and "b"
    int product = a * b;

    // Check if the product is even or odd using an if statement
    if (product % 2 == 0) {
        // If the product is even, print the message "Even" to the standard output
        printf("Even\n");
    } else {
        // If the product is odd, print the message "Odd" to the standard output
        printf("Odd\n");
    }

    return 0;
}

// <END-OF-CODE>
