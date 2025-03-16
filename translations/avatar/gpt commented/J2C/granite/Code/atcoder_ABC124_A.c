
#include <stdio.h> // Include the standard input/output library

int main() {
    int a, b, sum = 0; // Declare and initialize variables a, b, and sum
    
    // Read two integers from the user
    scanf("%d %d", &a, &b);
    
    // Loop to iterate twice to calculate the sum
    for (int i = 0; i < 2; i++) {
        // Check if 'a' is greater than or equal to 'b'
        if (a >= b) {
            sum += a; // Add 'a' to the sum
            a--; // Decrement 'a' by 1
        } else {
            sum += b; // Add 'b' to the sum
            b--; // Decrement 'b' by 1
        }
    }
    
    // Output the final sum to the console
    printf("%d", sum);
    
    return 0; // Return 0 to indicate successful execution
}
