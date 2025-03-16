#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

// Define constants for base and maximum size
const u64 B = 13131;
const int N = 500000 + 7;

// Declare global variables
int n; // Length of the input string
char s[N]; // Input string
u64 f[N]; // Array to store computed values based on the input string
int g[N]; // Array to store the shift values
u64 map[2 * N]; // Array to count occurrences of computed values (using a simple array for counting)
u64 cnt; // Counter for the final result

// Function to compute power of a number with a given exponent
u64 pow(u64 a, u64 k) {
    // Adjust exponent if negative
    if (k < 0) k += (1llu << 63) - 1;
    u64 t = 1; // Initialize result
    // Exponentiation by squaring
    for (; k; a = a * a, k >>= 1)
        if (k & 1) t = t * a; // Multiply result if current bit is set
    return t; // Return computed power
}

int main() {
    // Read input values: number of operations and the operations string
    scanf("%d%s", &n, s + 1);
    
<<<<<<< HEAD
=======
    // Initialize the map array
    for (int i = 0; i < 2 * N; ++i) {
        map[i] = 0; // Initialize all counts to zero
    }

>>>>>>> 98c87cb78a (data updated)
    // Process each character in the input string
    for (int i = 1; i <= n; ++i) {
        // If the character is '+' or '-', update f and g arrays
        if (s[i] == '+' || s[i] == '-') {
            f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]);
        } else {
            // If the character is '<' or '>', update f and g arrays accordingly
            f[i] = f[i - 1]; // No change in f
            g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1); // Update g based on direction
        }
    }

    // Iterate backwards through the string to count valid combinations
    for (int i = n; i; --i) {
<<<<<<< HEAD
        // Increment the count of the current f value
        map[f[i] + N]++; // Offset by N to handle negative indices
=======
        ++map[f[i] + N]; // Increment the count of the current f value (offset by N)
>>>>>>> 98c87cb78a (data updated)
        // Update the counter with the number of valid combinations found
        cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1] + N];
    }

    // Output the final count of valid combinations
    printf("%llu\n", cnt);

    return 0; // End of the program
}

// <END-OF-CODE>
