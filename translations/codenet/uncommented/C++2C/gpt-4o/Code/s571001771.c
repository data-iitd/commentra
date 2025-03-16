#include <stdio.h>
#include <limits.h>

typedef long long ll;
<<<<<<< HEAD

ll key[1005] = {0};
ll cost[1005] = {0};
ll dp[(1 << 12) + 5][1005];
=======
ll key[1005] = {0};
ll cost[1005] = {0};
ll dp[(1 << 12) + 5][1005] = {0};
>>>>>>> 98c87cb78a (data updated)
const ll INF = 123456789012;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    
    for (int i = 0; i < (1 << 12) + 5; i++) {
        for (int j = 0; j < 1005; j++) {
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

// <END-OF-CODE>
