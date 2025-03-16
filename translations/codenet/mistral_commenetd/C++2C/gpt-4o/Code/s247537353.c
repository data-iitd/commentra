#include <stdio.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    long long A, B, C, K; // Declare variables for input

    // Read input values from the standard input
    scanf("%lld %lld %lld %lld", &A, &B, &K);

    // Check if the sum of A and B is greater than or equal to K
    if (A + B >= K) {
        // If true, print the minimum value between A and K
        printf("%lld\n", min(A, K));
    } else {
        // If false, calculate the difference between K and the sum of A and B,
        // and subtract it from A to get the required value
        printf("%lld\n", A - (K - (A + B)));
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
