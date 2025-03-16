#include <stdio.h>

int main() {
    // Declare variables to hold the values of A, B, K, and the results x, y
    long A, B, K; 
    long x, y; 

    // Read input values A, B, and K from standard input
    scanf("%ld %ld %ld", &A, &B, &K);

    // Initialize x with the value of A and y with the value of B
    x = A; 
    y = B; 

    // Subtract K from A and assign the result to x
    x = A - K; 

    // Check if the result x is negative
    if (x < 0) {
        // If x is negative, adjust y by adding the negative value of x to B
        y = B + x; 
        // Set x to 0 since it cannot be negative
        x = 0; 
        
        // Ensure y is not negative
        if (y < 0) {
            y = 0; 
        } 
    } 

    // Print the values of x and y
    printf("%ld %ld\n", x, y); 

    return 0;
}

// <END-OF-CODE>
