#include <stdio.h>

int main() {
    // Declare variables to hold the input integers
    int a, b;

    // Read the first integer input from the user
    scanf("%d", &a);

    // Read the second integer input from the user
    scanf("%d", &b);

    // Check if the first integer 'a' is positive
    if (a > 0) {
        // If 'a' is positive, print the message "Positive"
        printf("Positive\n");
    }
    // Else if the second integer 'b' is non-negative
    else if (b >= 0) {
        // If 'b' is non-negative, print the message "Zero"
        printf("Zero\n");
    }
    // Else if the difference between 'b' and 'a' is even
    else if ((b - a + 1) % 2 == 0) {
        // If the difference is even, print the message "Positive"
        printf("Positive\n");
    }
    // Else, print the message "Negative"
    else {
        printf("Negative\n");
    }

    return 0;
}

// <END-OF-CODE>
