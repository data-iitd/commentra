#include <stdio.h>

// Define a function named 'solve' that takes an integer argument 'n'
int solve(int n) {
    // Calculate the sum of first 'n' natural numbers using the formula
    int s = (1 + n) * n / 2;
    
    // Initialize the variable 't' with the value 1
    int t = 1;
    
    // Run the while loop as long as 't' is less than or equal to 'n'
    while (t <= n) {
        // Subtract the contribution of 't' from the sum 's'
        s -= 2 * t;
        
        // Multiply the value of 't' by 2 and update its value
        t *= 2;
    }
    
    // Return the final value of 's'
    return s;
}

int main() {
    // Take an integer input from the user
    int t;
    scanf("%d", &t);
    
    // Run the loop 't' number of times
    for (int i = 0; i < t; i++) {
        // Take an integer input from the user for 'n'
        int n;
        scanf("%d", &n);
        
        // Call the 'solve' function with the input 'n' and print the result
        printf("%d\n", solve(n));
    }
    
    return 0;
}

// <END-OF-CODE>
