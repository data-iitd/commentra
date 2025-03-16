#include <stdio.h>

int main() {
    // Declare two integer variables to hold the input values
    int a, b;
    
    // Read two integers from standard input
    scanf("%d %d", &a, &b);

    // Check if the product of a and b is even or odd
    if (a * b % 2 == 0) {
        // If the product is even, print "Even"
        printf("Even\n");
    } else {
        // If the product is odd, print "Odd"
        printf("Odd\n");
    }

    return 0;
}
