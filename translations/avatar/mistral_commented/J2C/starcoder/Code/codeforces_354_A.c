#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, L, R, QL, QR;
    scanf("%d", &N);
    scanf("%d", &L);
    scanf("%d", &R);
    scanf("%d", &QL);
    scanf("%d", &QR);

    int W[N];
    int sum[N+1];
    for (int n = 0; n < N; n++) {
        scanf("%d", &W[n]);
        sum[n+1] = sum[n] + W[n];
    }

    long min = LLONG_MAX;
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR;
        int rCount = N - lCount;

        long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;

        int llCount = (lCount - rCount - 1) > 0? (lCount - rCount - 1) : 0;
        int rrCount = (rCount - lCount - 1) > 0? (rCount - lCount - 1) : 0;

        cand += llCount * QL;
        cand += rrCount * QR;

        min = cand < min? cand : min;
    }

    printf("%ld\n", min);
    return 0;
}

