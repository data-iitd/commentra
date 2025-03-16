#include <stdio.h>

int main() {
    // Declare two integer variables to hold the input values
    int a, b;
    
    // Read two integers from standard input
    scanf("%d %d", &a, &b);
    
    // Calculate the product of the two integers and check if it is even or odd
    int product = a * b;
    if (product % 2 == 0) {
        // If the product is even, print "Even"
        printf("Even\n");
    } else {
        // If the product is odd, print "Odd"
        printf("Odd\n");
    }
    
    return 0;
}

// <END-OF-CODE>
