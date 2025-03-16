#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    // Read the values of N and M from standard input
    scanf("%d %d", &N, &M);

    // Allocate memory for the array A
    long long *A = (long long *)malloc(N * sizeof(long long));
    // Read the array A from standard input
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Create an array to store cumulative remainders
    long long *cum_remainders = (long long *)malloc((N + 1) * sizeof(long long));
    cum_remainders[0] = 0; // Start with 0 to handle the case of subarrays starting from index 0

    // Calculate cumulative remainders of the array A when divided by M
    for (int i = 1; i <= N; i++) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Count occurrences of each remainder
    long long *remainder_counts = (long long *)calloc(M, sizeof(long long));
    for (int i = 0; i <= N; i++) {
        remainder_counts[cum_remainders[i]]++;
    }

    // Initialize a variable to count the number of valid combinations
    long long combinations = 0;

    // Calculate the number of combinations of indices that have the same remainder
    for (int i = 0; i < M; i++) {
        if (remainder_counts[i] > 1) {
            combinations += (remainder_counts[i] * (remainder_counts[i] - 1)) / 2; // Combinations of 2 from count
        }
    }

    // Output the total number of combinations found
    printf("%lld\n", combinations);

    // Free allocated memory
    free(A);
    free(cum_remainders);
    free(remainder_counts);

    return 0;
}

// <END-OF-CODE>
