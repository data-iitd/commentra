#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants definition
const long long INF = 1LL<<60; // Infinite value for long long int
const long long MOD = 1000000007; // Modulus value for modular arithmetic

// Input output functions
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

