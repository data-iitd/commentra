#include <stdio.h>

// Constants definition
#define INF (1LL<<60) // Infinite value for long long int
#define MOD 1000000007 // Modulus value for modular arithmetic

// Input output functions
int main() {
    // Initialize variables
    long long a, b;

    // Read input values from standard input
    scanf("%lld %lld", &a, &b);

    // Calculate the maximum value among a+b, a-b, and a*b
    long long result = a + b;
    if (a - b > result) result = a - b;
    if (a * b > result) result = a * b;

    // Output the result to standard output
    printf("%lld\n", result);

    // End of the program
    return 0;
}

// <END-OF-CODE>
