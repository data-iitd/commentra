#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, L, R, QL, QR;
    int *W, *sum;
    long min;
    int firstR, lCount, rCount, llCount, rrCount;

    scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR);
    W = (int *)malloc(N * sizeof(int));
    sum = (int *)malloc((N + 1) * sizeof(int));

    for (int n = 0; n < N; n++) {
        scanf("%d", &W[n]);
        sum[n + 1] = sum[n] + W[n];
    }

    min = LONG_MAX;

    for (firstR = 0; firstR <= N; firstR++) {
        lCount = firstR;
        rCount = N - lCount;

        long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;

        llCount = lCount - rCount - 1;
        rrCount = rCount - lCount - 1;
        if (llCount > 0) cand += llCount * QL;
        if (rrCount > 0) cand += rrCount * QR;

        min = cand < min ? cand : min;
    }

    printf("%ld\n", min);

    free(W);
    free(sum);

    return 0;
}

