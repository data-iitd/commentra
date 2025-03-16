#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creating a Scanner object to read input from the console
    int n;
    scanf("%d", &n);
    
    // Printing the input number
    printf("%d ", n);
    
    // Initializing a variable m to hold the current divisor, starting with n
    int m = n;
    
    // Looping from n-1 down to 1 to find and print all divisors of n
    for (int i = n - 1; i > 0; i--) {
        // Checking if i is a divisor of m
        if (m % i == 0) {
            // Printing the divisor
            printf("%d ", i);
            // Updating m to the current divisor
            m = i;
        }
    }
    
    // End of code
    printf("