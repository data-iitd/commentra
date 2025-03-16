
#include <stdio.h>
#include <string.h>
#define MOD 100000007
typedef long long ll;

int ok(char *last4) {
    for (int i = 0; i < 4; i++) {
        char t[4];
        memcpy(t, last4, 4);
        if (i >= 1) {
            char tmp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = tmp;
        }
        if (strstr(t, "AGC")) {
            return 0;
        }
    }
    return 1;
}

ll dfs(int cur, char *last3) {
    static ll dp[1001][8];
    static int vis[1001][8];
    if (vis[cur][last3[0] * 4 + last3[1] * 2 + last3[2]]) {
        return dp[cur][last3[0] * 4 + last3[1] * 2 + last3[2]];
    }
    if (cur == n) {
        return 1;
    }
    vis[cur][last3[0] * 4 + last3[1] * 2 + last3[2]] = 1;
    ll ret = 0;
    for (int i = 0; i < 4; i++) {
        char c = "ACGT"[i];
        if (ok(last3 + c)) {
            ret = (ret + dfs(cur + 1, (last3[1] * 2 + last3[2] * 4 + i) % 8)) % MOD;
        }
    }
    return dp[cur][last3[0] * 4 + last3[1] * 2 + last3[2]] = ret;
}

int main() {
    scanf("%d", &n);
    printf("%lld\n", dfs(0, "TTT"));
    return 0;
}
// END-OF-CODE