
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    int x[N], xsum[N+1];
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
        xsum[i+1] = xsum[i] + x[i];
    }
    long long ans = X * N + 5 * xsum[N];
    for (int i = 1; i < N; i++) {
        long long cost = X * i + 5 * (xsum[N] - xsum[N-i]);
        for (int j = 5, k = N-i; k >= 0; j += 2, k -= i) {
            if (cost > ans) break;
            cost += j * (xsum[k] - xsum[k-i]);
        }
        ans = min(ans, cost);
    }
    printf("%lld\n", ans + N * X);
    return 0;
}

