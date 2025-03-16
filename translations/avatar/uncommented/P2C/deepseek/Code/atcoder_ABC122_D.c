#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int ok(char* last4) {
    for (int i = 0; i < 4; i++) {
        char t[5];
        strcpy(t, last4);
        if (i >= 1) {
            char temp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = temp;
        }
        if (strstr(t, "AGC") != NULL) {
            return 0;
        }
    }
    return 1;
}

int dfs(int cur, char* last3, int memo[51][4][4][4], int n) {
    if (memo[cur][last3[0] - 'A'][last3[1] - 'A'][last3[2] - 'A'] != -1) {
        return memo[cur][last3[0] - 'A'][last3[1] - 'A'][last3[2] - 'A'];
    }
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    char chars[] = "ACGT";
    for (int i = 0; i < 4; i++) {
        if (ok(last3 + 1)) {
            ret = (ret + dfs(cur + 1, last3 + 1, memo, n)) % MOD;
        }
        char temp = last3[2];
        last3[2] = chars[i];
        last3[0] = last3[1];
        last3[1] = temp;
    }
    memo[cur][last3[0] - 'A'][last3[1] - 'A'][last3[2] - 'A'] = ret;
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int memo[51][4][4][4];
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dfs(0, "TTT", memo, n));
    return 0;
}
