#include <stdio.h> // Including standard input-output header

int main() {
    // Declaring a variable to hold the input number
    int n;
    
    // Reading an integer input from the user
    scanf("%d", &n);
    
    // Printing the input number
    printf("%d\n", n);
    
    // Initializing a variable m to hold the current divisor, starting with n
    int m = n;
    
    // Looping from n-1 down to 1 to find and print all divisors of n
    for (int i = n - 1; i > 0; i--) {
        // Checking if i is a divisor of m
        if (m % i == 0) {
            // Printing the divisor
            printf("%d\n", i);
            // Updating m to the current divisor
            m = i;
        }
    }
    
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
