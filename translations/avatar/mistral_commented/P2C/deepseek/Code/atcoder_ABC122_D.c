#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int ok(char last4[]) {
    for (int i = 3; i >= 0; i--) {
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

int dfs(int cur, char last3[], int memo[51][5], int n) {
    if (memo[cur][last3[0] - 'A'] != -1) {
        return memo[cur][last3[0] - 'A'];
    }
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    char nucleotides[] = "ACGT";
    for (int i = 0; i < 4; i++) {
        if (ok(last3, nucleotides[i])) {
            last3[2] = nucleotides[i];
            ret = (ret + dfs(cur + 1, last3 + 1, memo, n)) % MOD;
        }
    }
    memo[cur][last3[0] - 'A'] = ret;
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int memo[51][5];
    memset(memo, -1, sizeof(memo));
    char last3[] = "TT";
    printf("%d\n", dfs(0, last3, memo, n));
    return 0;
}
