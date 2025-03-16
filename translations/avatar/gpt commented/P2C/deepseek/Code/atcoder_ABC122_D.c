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

int dfs(int cur, char* last3, int memo[51][4 * 4 * 4], int n) {
    if (memo[cur][hash(last3)] != -1) {
        return memo[cur][hash(last3)];
    }
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    char chars[] = "ACGT";
    for (int i = 0; i < 4; i++) {
        char next_char = chars[i];
        if (ok(strcat(last3, &next_char))) {
            ret = (ret + dfs(cur + 1, &last3[1], memo, n)) % MOD;
        }
    }
    memo[cur][hash(last3)] = ret;
    return ret;
}

int hash(char* str) {
    return (str[0] - 'A') * 16 + (str[1] - 'A') * 4 + (str[2] - 'A');
}

int main() {
    int n;
    scanf("%d", &n);
    int memo[51][4 * 4 * 4];
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dfs(0, "TTT", memo, n));
    return 0;
}
