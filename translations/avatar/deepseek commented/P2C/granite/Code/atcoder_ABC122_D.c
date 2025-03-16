
#include <stdio.h>
#include <string.h>

#define MOD 100000007

typedef struct {
    int ok;
    int dp[4];
} Node;

Node memo[100001];

int ok(char *last4) {
    int i;
    for (i = 0; i < 4; i++) {
        char t[5];
        memcpy(t, last4, 4);
        if (i > 0) {
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

int dfs(int cur, char *last3) {
    Node *node = &memo[cur];
    if (node->ok!= -1) {
        return node->ok;
    }
    if (cur == n) {
        return 1;
    }
    int i;
    node->ok = 0;
    for (i = 0; i < 4; i++) {
        char c = "ACGT"[i];
        if (ok(last3 + c)) {
            node->dp[i] = (node->dp[i] + dfs(cur + 1, last3 + 1)) % MOD;
            node->ok = (node->ok + node->dp[i]) % MOD;
        }
    }
    return node->ok;
}

int main() {
    int i;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        memo[i].ok = -1;
    }
    printf("%d\n", dfs(0, "TTT"));
    return 0;
}

