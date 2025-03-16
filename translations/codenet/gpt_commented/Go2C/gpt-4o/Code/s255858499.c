#include <stdio.h>

int main() {
    int a, b;

    // Read the first integer from input
    scanf("%d", &a);
    // Read the second integer from input
    scanf("%d", &b);

    // Check if the product of a and b is odd
    if ((a * b) % 2 != 0) {
        // If the product is odd, print "Odd"
        printf("Odd\n");
    } else {
        // If the product is even, print "Even"
        printf("Even\n");
    }

    return 0;
}

// <END-OF-CODE>
