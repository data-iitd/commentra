#include <stdio.h>

int main() {
    int a, b;

    // Read two integers from standard input
    scanf("%d %d", &a, &b);

    // Check if 'a' is positive
    if (a > 0) {
        // If it is, print the string 'Positive'
        printf("Positive\n");
    }
    // If 'a' is not positive, check if 'b' is non-negative
    else if (a <= 0 && b >= 0) {
        // If it is, print the string 'Zero'
        printf("Zero\n");
    }
    // If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
    else {
        // If it is, print the string 'Negative'
        if ((a + b) % 2 == 0) {
            printf("Negative\n");
        }
        // Otherwise, print the string 'Positive'
        else {
            printf("Positive\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
