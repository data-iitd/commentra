#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define rep(i, k, n) for (int i = k; i < n; ++i)

void chmin(int *a, int b) {
    if (*a > b) *a = b;
}

int main() {
    const int INF = INT_MAX;
    int dp[101000];
    for (int i = 0; i < 101000; ++i) dp[i] = INF;
    dp[0] = 0;

    // input
    int N, K;
    scanf("%d %d", &N, &K);
    int h[N];
    rep(i, 0, N) scanf("%d", &h[i]);

    // dp
    rep(i, 0, N) {
        rep(j, 1, K + 1) {
            if (i + j < N) {
                chmin(&dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            }
        }
    }

    // output
    printf("%d\n", dp[N - 1]);
    return 0;
}

// <END-OF-CODE>
