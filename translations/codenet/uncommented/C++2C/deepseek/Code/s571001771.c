#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 1005
#define MAX_M 1005
#define INF LLONG_MAX

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} PP;

ll key[MAX_N] = {0};
ll cost[MAX_M] = {0};
ll dp[1 << 12 + 5][MAX_M] = {0};

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < (1 << 12 + 5); i++) {
        for (int j = 0; j < MAX_M; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        ll b;
        scanf("%lld %lld", &cost[i], &b);
        for (int j = 0; j < b; j++) {
            ll c;
            scanf("%lld", &c);
            key[i] += (1 << (c - 1));
        }
    }
    for (ll i = 0; i < (1 << n); i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j + 1] = dp[i][j] < dp[i][j + 1] ? dp[i][j] : dp[i][j + 1];
            dp[i | key[j + 1]][j + 1] = dp[i | key[j + 1]][j + 1] < dp[i][j] + cost[j + 1] ? dp[i | key[j + 1]][j + 1] : dp[i][j] + cost[j + 1];
        }
    }
    if (dp[(1 << n) - 1][m] == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", dp[(1 << n) - 1][m]);
    }
    return 0;
}
