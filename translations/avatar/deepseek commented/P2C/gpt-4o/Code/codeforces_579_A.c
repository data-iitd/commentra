#include <stdio.h>
#include <math.h>

int main() {
    // Take an integer input from the user
    int n;
    scanf("%d", &n);
    
    // Initialize a variable x to 1
    int x = 1;
    
    // Continue looping until the base-2 logarithm of n is an integer
    while (log2(n) - (int)log2(n) != 0) {
        // Increment x by 1
        x += 1;
        // Update n by subtracting 2 raised to the power of the integer part of the base-2 logarithm of n
        n -= (int)pow(2, (int)log2(n));
    }
    
    // Print the value of x
    printf("%d\n", x);
    
    return 0;
}

// <END-OF-CODE>
