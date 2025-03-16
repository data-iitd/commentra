#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

int main(int argc, char **argv) {
    // Read the values of N and M from the standard input
    int N, M;
    scanf("%d %d", &N, &M);

    // Read the array A from the standard input
    int64_t *A = malloc(N * sizeof(int64_t));
    for (int i = 0; i < N; i++) {
        scanf("%" PRId64, A + i);
    }

    // Calculate the cumulative remainders of the array A modulo M
    // Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
    int64_t *cum_remainders = malloc((N + 1) * sizeof(int64_t));
    cum_remainders[0] = 0;
    for (int i = 0; i < N; i++) {
        cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
    }

    // Count the occurrences of each remainder
    int64_t *remainder_counts = malloc(M * sizeof(int64_t));
    memset(remainder_counts, 0, M * sizeof(int64_t));
    for (int i = 0; i < N; i++) {
        remainder_counts[cum_remainders[i]]++;
    }

    // Initialize the number of combinations
    int64_t combinations = 0;

    // Calculate the number of combinations where the difference between two remainders is a multiple of M
    for (int i = 0; i < M; i++) {
        combinations += remainder_counts[i] * (remainder_counts[i] - 1) / 2;
    }

    // Print the number of combinations
    printf("%" PRId64 "\n", combinations);

    // Free the memory
    free(A);
    free(cum_remainders);
    free(remainder_counts);

    return EXIT_SUCCESS;
}

