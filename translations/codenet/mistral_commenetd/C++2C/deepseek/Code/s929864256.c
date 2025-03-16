#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Constants definition
#define INF LLONG_MAX // Infinite value for long long int
#define MOD 1000000007 // Modulus value for modular arithmetic

// Function to calculate the maximum value among a+b, a-b, and a*b
long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

// Main function
int main() {
    // Initialize variables
    long long a, b;

    // Read input values from standard input
    scanf("%lld %lld", &a, &b);

    // Calculate the maximum value among a+b, a-b, and a*b
    long long result = max(a+b, max(a-b, a*b));

    // Output the result to standard output
    printf("%lld\n", result);

    // End of the program
    return 0;
}
