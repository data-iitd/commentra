#include <stdio.h>
#include <limits.h>

int main() {
    // Declare variables to store input values
    long long A, B, C, K;
    scanf("%lld %lld %lld %lld", &A, &B, &C, &K);

    // Check if the sum of A and B is greater than or equal to K
    if (A + B >= K) {
        // Output the minimum of A and K
<<<<<<< HEAD
        printf("%lld\n", (A < K) ? A : K);
=======
        printf("%lld\n", A < K ? A : K);
>>>>>>> 98c87cb78a (data updated)
    } else {
        // Calculate the result by subtracting the excess amount from A
        printf("%lld\n", A - (K - (A + B)));
    }

    return 0;
}

// <END-OF-CODE>
