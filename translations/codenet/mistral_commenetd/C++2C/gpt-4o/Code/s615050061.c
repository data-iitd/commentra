#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

const u64 B = 13131; // Base number for exponentiation
const int N = 500000 + 7; // Maximum size of input string

int n; // Number of symbols in input string
char s[N]; // Input string
u64 f[N]; // Intermediate result array
int g[N]; // Exponent array
u64 map[1000000]; // Array to store counts of intermediate results (using a large enough size)
u64 cnt; // Final result

// Function to calculate B raised to the power of k
u64 pow(u64 a, u64 k) {
    if (k < 0) k += (1llu << 63) - 1; // Handle negative exponents by converting them to positive
    u64 t = 1; // Initialize result to 1
    for (; k; a = a * a, k >>= 1) // Calculate exponentiation using bitwise right shift and multiplication
        if (k & 1) t = t * a; // If the current bit is 1, add the current base to the result
    return t; // Return the result
}

int main() {
    // Uncomment to read input from a file
    // freopen("code.in", "r", stdin);
    // freopen("code.out", "w", stdout);

    scanf("%d%s", &n, s + 1); // Read the number of symbols and the input string from standard input

    // Initialize the first element of f and g arrays
    f[0] = 0;
    g[0] = 0;

    // Process each symbol in the input string
    for (int i = 1; i <= n; ++i) {
        // Update the current element of f array based on the current symbol
        if (s[i] == '+' || s[i] == '-')
            f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]);
        // If the current symbol is not an operator, just copy the previous value of f to the current position
        else
            f[i] = f[i - 1], g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1);
    }

    // Calculate the final result
    for (int i = n; i; --i) {
        map[f[i]]++; // Increment the count of the intermediate result in the map
        cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]; // Add the contribution of the current symbol to the final result
    }

    printf("%llu\n", cnt); // Print the final result to standard output

    return 0;
}

// <END-OF-CODE>
