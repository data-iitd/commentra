#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int mod = 1000000007;
    int memo[n + 1][4];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            memo[i][j] = -1;
        }
    }
    int dfs(int cur, char last3[3]) {
        if (memo[cur][last3[0] - 'A']!= -1) {
            return memo[cur][last3[0] - 'A'];
        }
        if (cur == n) {
            return 1;
        }
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            char c = 'A' + i;
            if (ok(last3, c)) {
                ret = (ret + dfs(cur + 1, last3[1] + c)) % mod;
            }
        }
        memo[cur][last3[0] - 'A'] = ret;
        return ret;
    }
    int ok(char last3[3], char c) {
        char t[3];
        strcpy(t, last3);
        t[0] = c;
        t[1] = last3[0];
        t[2] = last3[1];
        for (int i = 0; i < 3; i++) {
            if (strstr(t, "AGC")!= NULL) {
                return 0;
            }
            char tmp = t[0];
            t[0] = t[1];
            t[1] = t[2];
            t[2] = tmp;
        }
        return 1;
    }
    printf("%d", dfs(0, "TTT"));
    return 0;
}

