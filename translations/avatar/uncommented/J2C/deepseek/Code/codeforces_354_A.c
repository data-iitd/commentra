#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, L, R, QL, QR;
    scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR);
    int W[N];
    int sum[N + 1];
    sum[0] = 0;
    for (int n = 0; n < N; n++) {
        scanf("%d", &W[n]);
        sum[n + 1] = sum[n] + W[n];
    }
    long long min = LLONG_MAX;
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR;
        int rCount = N - lCount;
        long long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;
        int llCount = lCount > rCount ? lCount - rCount - 1 : 0;
        int rrCount = rCount > lCount ? rCount - lCount - 1 : 0;
        cand += llCount * QL;
        cand += rrCount * QR;
        if (cand < min) {
            min = cand;
        }
    }
    printf("%lld\n", min);
    return 0;
}
