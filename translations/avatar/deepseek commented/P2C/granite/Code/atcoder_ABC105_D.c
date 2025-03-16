
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int cum_remainders[N + 1];
    cum_remainders[0] = 0;
    for (int i = 0; i < N; i++) {
        cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
    }

    int remainder_counts[M];
    memset(remainder_counts, 0, sizeof(remainder_counts));
    for (int i = 0; i <= N; i++) {
        remainder_counts[cum_remainders[i]]++;
    }

    long long combinations = 0;
    for (int i = 0; i < M; i++) {
        combinations += (long long)remainder_counts[i] * (remainder_counts[i] - 1) / 2;
    }

    printf("%lld\n", combinations);

    return 0;
}
