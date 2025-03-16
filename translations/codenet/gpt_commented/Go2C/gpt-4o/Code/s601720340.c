#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAGIC 1000000007
#define MAX_SIZE 200000

int N;
int p[MAX_SIZE];

// Function to check if a number exists in the array p
int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0; // Number found
        }
    }
    return 1; // Number not found
}

// Function to read an integer from input
int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Main solving function
void solve() {
    int X = nextInt(); // Read an integer
    N = nextInt(); // Read the size of the array
    for (int i = 0; i < N; i++) {
        p[i] = nextInt(); // Read integers into the array p
    }

    // Check for numbers around X that are not in the array p
    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) { // Check X - i
            printf("%d\n", X - i); // Print the result
            exit(0); // Exit the program
        }
        if (find(X + i) == 1) { // Check X + i
            printf("%d\n", X + i); // Print the result
            exit(0); // Exit the program
        }
    }
}

// Main function to execute the program
int main() {
    solve(); // Call the solve function
    return 0; // Return success
}

// Helper functions for mathematical operations

// Returns the minimum of two integers
int intMin(int a, int b) {
    return (a < b) ? a : b;
}

// Returns the maximum of two integers
int intMax(int a, int b) {
    return (a > b) ? a : b;
}

// Direct calculation of combination
// n, m should be "small"
int combination(int n, int m) {
    if (m > n) {
        return 0; // Not possible to choose more than available
    } else if (m == n || m == 0) {
        return 1; // Only one way to choose all or none
    } else {
        int res = 1;
        for (int i = 0; i < m; i++) {
            res *= (n - i); // Calculate numerator
        }
        for (int i = 1; i <= m; i++) {
            res /= i; // Calculate denominator
        }
        return res; // Return the combination result
    }
}

// Calculate combination modulo based on Lucas theorem
int lucas(int n, int m, int p) {
    int ntemp = n;
    int mtemp = m;
    int res = 1;
    for (int i = 0; i < 100; i++) {
        int nreminder = ntemp % p; // Remainder of n
        ntemp = ntemp / p; // Update n
        int mreminder = mtemp % p; // Remainder of m
        mtemp = mtemp / p; // Update m
        res = res * (combination(nreminder, mreminder) % p); // Combine results
        if (ntemp == 0) {
            break; // Break if n is exhausted
        }
    }
    return res % p; // Return the result modulo p
}

// Wrapper function for combination modulo
int combMod(int n, int m, int p) {
    return lucas(n, m, p); // Call lucas function
}

// Function to calculate the absolute value
int abs(int a) {
    return (a > 0) ? a : -a; // Return absolute value
}

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (a != 0) {
        int temp = b % a;
        b = a;
        a = temp; // Euclidean algorithm
    }
    return b; // Return the GCD
}

// Function to calculate power of 2 modulo a given number
int power2mod(int n, int mod) {
    int res = 1, x = 2;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod; // Update result if the current bit is set
        }
        x = x * x % mod; // Square the base
        n >>= 1; // Right shift n
    }
    return res; // Return the result
}

// Function to calculate power of 2 with modulo magic
int power2(int n) {
    return power2mod(n, MAGIC); // Call power2mod with magic
}

