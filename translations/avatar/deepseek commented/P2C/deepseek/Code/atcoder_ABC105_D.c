#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int *cum_remainders = (int *)malloc((N + 1) * sizeof(int));
    cum_remainders[0] = 0;
    for (int i = 1; i <= N; i++) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    int *remainder_counts = (int *)calloc(M, sizeof(int));
    for (int i = 0; i <= N; i++) {
        remainder_counts[cum_remainders[i]]++;
    }

    long long combinations = 0;
    for (int i = 0; i < M; i++) {
        combinations += (long long)remainder_counts[i] * (remainder_counts[i] - 1) / 2;
    }

    printf("%lld\n", combinations);

    free(A);
    free(cum_remainders);
    free(remainder_counts);

    return 0;
}
