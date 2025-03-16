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

// Function to compute the maximum product of pairs from the array
long maxProduct(long a[], int n) {
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max = max > (a[i] * a[j])? max : (a[i] * a[j]);
        }
    }
    return max;
}

// Driver code
int main() {
    long a[4]; // Array to hold four long integers
    int n; // Variable to store the size of the array
    scanf("%d", &n); // Read the size of the array
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]); // Read four long integers from input
    }
    printf("%ld", maxProduct(a, n)); // Calculate and print the maximum product of pairs from the array
    return 0;
}

