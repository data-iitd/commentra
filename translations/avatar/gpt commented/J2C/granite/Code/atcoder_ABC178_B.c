
#include <stdio.h>
#include <stdlib.h>

// Function to compute (x^y) % mod using modular exponentiation
int modPower(int x, int y, int mod) {
    int res = 1;
    x %= mod; // Reduce x modulo mod
    if (x == 0) return 0; // If x is 0, return 0
    
    // Loop until y becomes 0
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1; // Divide y by 2
        x = (x * x) % mod; // Square x
    }
    return res; // Return the final result
}

int main() {
    long a[4]; // Array to hold four long integers
    
    // Read four long integers from input
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &a[i]);
    }
    
    // Calculate and print the maximum product of pairs from the array
    printf("%ld\n", (long)fmax(a[0] * a[2], fmax(a[1] * a[3], fmax(a[0] * a[3], a[1] * a[2]))));
    
    return 0;
}
