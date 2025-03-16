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
    scanf("%d %d", &N, &M);
    
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long *cum_remainders = (long long *)malloc((N + 1) * sizeof(long long));
    cum_remainders[0] = 0;

    for (int i = 1; i <= N; i++) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Count occurrences of each remainder
    RemainderCount *remainder_counts = (RemainderCount *)malloc((N + 1) * sizeof(RemainderCount));
    int unique_remainders = 0;

    for (int i = 0; i <= N; i++) {
        long long rem = cum_remainders[i];
        int found = 0;

        for (int j = 0; j < unique_remainders; j++) {
            if (remainder_counts[j].remainder == rem) {
                remainder_counts[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            remainder_counts[unique_remainders].remainder = rem;
            remainder_counts[unique_remainders].count = 1;
            unique_remainders++;
        }
    }

    long long combinations = 0;
    for (int i = 0; i < unique_remainders; i++) {
        long long count = remainder_counts[i].count;
        combinations += count * (count - 1) / 2;
    }

    printf("%lld\n", combinations);

    free(A);
    free(cum_remainders);
    free(remainder_counts);
    
    return 0;
}

// <END-OF-CODE>
