#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} PP;

ll key[1005] = {0};
ll cost[1005] = {0};
ll dp[1 << 12 + 5][1005] = {0};

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);

    for (int i = 0; i < (1 << 12 + 5); i++) {
        for (int j = 0; j < 1005; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        ll b;
        scanf("%lld", &cost[i]);
        scanf("%lld", &b);

        for (int j = 0; j < b; j++) {
            ll c;
            scanf("%lld", &c);
            key[i] += (1 << (c - 1));
        }
    }

    for (ll i = 0; i < (1 << n); i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] < dp[i][j + 1]) {
                dp[i][j + 1] = dp[i][j];
            }
            if (dp[i][j] + cost[j + 1] < dp[i | key[j + 1]][j + 1]) {
                dp[i | key[j + 1]][j + 1] = dp[i][j] + cost[j + 1];
            }
        }
    }

    if (dp[(1 << n) - 1][m] == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", dp[(1 << n) - 1][m]);
    }

    return 0;
}
