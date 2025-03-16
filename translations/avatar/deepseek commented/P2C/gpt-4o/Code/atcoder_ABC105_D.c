#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long remainder;
    int count;
} RemainderCount;

int compare(const void *a, const void *b) {
    return ((RemainderCount *)a)->remainder - ((RemainderCount *)b)->remainder;
}

int main() {
    int N, M;
    // Read the values of N and M from the standard input
    scanf("%d %d", &N, &M);

    long long *A = (long long *)malloc(N * sizeof(long long));
    long long *cum_remainders = (long long *)malloc((N + 1) * sizeof(long long));
    
    // Read the array A from the standard input
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Calculate the cumulative remainders of the array A modulo M
    cum_remainders[0] = 0; // Include a 0 at the beginning
    for (int i = 1; i <= N; i++) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Count the occurrences of each remainder
    RemainderCount *remainder_counts = (RemainderCount *)malloc((M + 1) * sizeof(RemainderCount));
    for (int i = 0; i < M; i++) {
        remainder_counts[i].remainder = i;
        remainder_counts[i].count = 0;
    }

    for (int i = 0; i <= N; i++) {
        remainder_counts[cum_remainders[i]].count++;
    }

    // Initialize the number of combinations
    long long combinations = 0;

    // Calculate the number of combinations where the difference between two remainders is a multiple of M
    for (int i = 0; i < M; i++) {
        int count = remainder_counts[i].count;
        combinations += (long long)count * (count - 1) / 2;
    }

    // Print the number of combinations
    printf("%lld\n", combinations);

    // Free allocated memory
    free(A);
    free(cum_remainders);
    free(remainder_counts);

    return 0;
}

// <END-OF-CODE>
