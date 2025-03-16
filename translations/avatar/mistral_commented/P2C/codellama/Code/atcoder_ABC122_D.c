
#include <stdio.h>
#include <string.h>

#define MAX 1000000007

int n;

int memo[100000][4];

int ok(char last4[]) {
    int i;
    for (i = 3; i >= 0; i--) {
        char t[4];
        if (i >= 1) {
            t[0] = last4[i];
            t[1] = last4[i-1];
            t[2] = last4[i-2];
            t[3] = last4[i-3];
        } else {
            t[0] = last4[i];
            t[1] = last4[i-1];
            t[2] = last4[i-2];
            t[3] = last4[i-3];
        }
        if (strstr(t, "AGC") != NULL) {
            return 0;
        }
    }
    return 1;
}

int dfs(int cur, char last3[]) {
    if (memo[cur][last3[0] - 'A'] != 0) {
        return memo[cur][last3[0] - 'A'];
    }
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    int i;
    for (i = 0; i < 4; i++) {
        char c = "ACGT"[i];
        if (ok(last3 + c)) {
            ret = (ret + dfs(cur + 1, last3 + 1)) % MAX;
        }
    }
    memo[cur][last3[0] - 'A'] = ret;
    return ret;
}

int main() {
    scanf("%d", &n);
    printf("%d\n", dfs(0, "TTT"));
    return 0;
}

