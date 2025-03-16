#include <stdio.h>
#include <stdlib.h>

// Function to perform ceiling division
long long divUp(long long x, long long y) {
    return (x + y - 1) / y;
}

// Function to get the maximum of two long long values
long long max(long long x, long long y) {
    return (x > y) ? x : y;
}

int main() {
    long long N;
    scanf("%lld", &N); // Read the number of pairs

    long long *T = (long long *)malloc(N * sizeof(long long)); // Allocate memory for T
    long long *A = (long long *)malloc(N * sizeof(long long)); // Allocate memory for A

    // Read pairs of integers into T and A
    for (long long i = 0; i < N; i++) {
        scanf("%lld %lld", &T[i], &A[i]); // Read each pair
    }

    long long t = T[0], a = A[0]; // Initialize t and a with the first pair

    // Iterate through the remaining pairs to compute the required values
    for (long long i = 1; i < N; i++) {
        long long r = max(divUp(t, T[i]), divUp(a, A[i])); // Calculate the required multiplier
        t = T[i] * r; // Update t based on the multiplier
        a = A[i] * r; // Update a based on the multiplier
    }

    printf("%lld\n", t + a); // Output the final result

    free(T); // Free allocated memory for T
    free(A); // Free allocated memory for A

    return 0; // Return success
}

// <END-OF-CODE>
