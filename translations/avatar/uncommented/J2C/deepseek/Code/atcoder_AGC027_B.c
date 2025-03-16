#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void solve(void) {
    int N;
    long long X;
    scanf("%d %lld", &N, &X);
    long long x[N], xsum[N + 1];
    xsum[0] = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &x[i]);
        xsum[i + 1] = xsum[i] + x[i];
    }
    long long ans = X * N + 5 * xsum[N];
    for (int i = 1; i < N; i++) {
        long long cost = X * i + 5 * (xsum[N] - xsum[N - i]);
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            if (cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[k - i > 0 ? k - i : 0]);
        }
        ans = ans < cost ? ans : cost;
    }
    printf("%lld\n", ans + N * X);
}

int main(void) {
    solve();
    return 0;
}
