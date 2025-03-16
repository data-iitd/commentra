#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// Read the values of N and M from standard input
int N, M;
scanf("%d %d", &N, &M);

// Read the array A from standard input and convert it to a NumPy array of int64 type
int64_t *A = (int64_t *)malloc(N * sizeof(int64_t));
for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
}

// Calculate cumulative remainders of the array A when divided by M
// Start with a 0 to handle the case of subarrays starting from index 0
int64_t *cum_remainders = (int64_t *)malloc((N + 1) * sizeof(int64_t));
cum_remainders[0] = 0;
for (int i = 1; i <= N; i++) {
    cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
}

// Count the occurrences of each remainder using Counter
int remainder_counts[M];
memset(remainder_counts, 0, M * sizeof(int));
for (int i = 0; i <= N; i++) {
    remainder_counts[cum_remainders[i]]++;
}

// Initialize a variable to count the number of valid combinations
int combinations = 0;

// Calculate the number of combinations of indices that have the same remainder
for (int i = 0; i < M; i++) {
    combinations += remainder_counts[i] * (remainder_counts[i] - 1) / 2;
}

// Output the total number of combinations found
printf("%d\n", combinations);

