#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

int main(int argc, char **argv) {
    // Read the values of N and M from standard input
    int N, M;
    scanf("%d %d", &N, &M);

    // Read the array A from standard input and convert it to a NumPy array of int64 type
    int64_t *A = malloc(N * sizeof(int64_t));
    for (int i = 0; i < N; i++) {
        scanf("%" PRId64, A + i);
    }

    // Calculate cumulative remainders of the array A when divided by M
    // Start with a 0 to handle the case of subarrays starting from index 0
    int64_t *cum_remainders = malloc((N + 1) * sizeof(int64_t));
    cum_remainders[0] = 0;
    for (int i = 0; i < N; i++) {
        cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
    }

    // Count the occurrences of each remainder using Counter
    int64_t *remainder_counts = malloc(M * sizeof(int64_t));
    for (int i = 0; i < M; i++) {
        remainder_counts[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        remainder_counts[cum_remainders[i]]++;
    }

    // Initialize a variable to count the number of valid combinations
    int64_t combinations = 0;

    // Calculate the number of combinations of indices that have the same remainder
    for (int i = 0; i < M; i++) {
        combinations += remainder_counts[i] * (remainder_counts[i] - 1) / 2;  // Combinations of 2 from count
    }

    // Output the total number of combinations found
    printf("%" PRId64 "\n", combinations);

    // Free the memory allocated for the arrays
    free(A);
    free(cum_remainders);
    free(remainder_counts);

    return EXIT_SUCCESS;
}

