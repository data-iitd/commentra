#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long *data;
    int size;
} Counter;

Counter create_counter(int size) {
    Counter counter;
    counter.data = (long long *)calloc(size, sizeof(long long));
    counter.size = size;
    return counter;
}

void free_counter(Counter counter) {
    free(counter.data);
}

int main() {
    // Read input number of rows and columns
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize array 'A' with given dimensions
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Calculate cumulative remainders
    long long *cum_remainders = (long long *)malloc((N + 1) * sizeof(long long));
    cum_remainders[0] = 0; // Starting with zero
    for (int i = 1; i <= N; i++) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Count the occurrences of each cumulative remainder
    Counter remainder_counts = create_counter(M);
    for (int i = 0; i <= N; i++) {
        remainder_counts.data[cum_remainders[i]]++;
    }

    // Calculate the number of combinations of elements having the same remainder
    long long combinations = 0;
    for (int i = 0; i < M; i++) {
        long long count = remainder_counts.data[i];
        combinations += count * (count - 1) / 2;
    }

    // Print the result
    printf("%lld\n", combinations);

    // Free allocated memory
    free(A);
    free(cum_remainders);
    free_counter(remainder_counts);

    return 0;
}

// <END-OF-CODE>
