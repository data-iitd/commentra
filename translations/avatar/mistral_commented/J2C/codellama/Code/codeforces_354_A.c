#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int N, L, R, QL, QR;
    scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR);

    int *W = (int *)malloc(N * sizeof(int));
    int *sum = (int *)malloc((N + 1) * sizeof(int));

    for (int n = 0; n < N; n++) {
        scanf("%d", &W[n]);
        sum[n + 1] = sum[n] + W[n];
    }

    long min = LONG_MAX;

    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR;
        int rCount = N - lCount;

        long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;

        int llCount = max(0, lCount - rCount - 1);
        int rrCount = max(0, rCount - lCount - 1);

        cand += llCount * QL;
        cand += rrCount * QR;

        min = min(cand, min);
    }

    printf("%ld\n", min);

    free(W);
    free(sum);

    return 0;
}

