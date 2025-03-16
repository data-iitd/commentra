#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100000

int read_int() {
    int num = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        num = num * 10 + c - '0';
        c = getchar_unlocked();
    }
    return num;
}

void read_int_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = read_int();
    }
}

void read_string(char *str, int n) {
    for (int i = 0; i < n; i++) {
        str[i] = getchar_unlocked();
    }
    str[n] = '\0';
}

int main() {
    setbuf(stdout, NULL);
    int n;
    char S[MAX_N + 1];
    read_string(S, MAX_N);
    n = strlen(S);

    if (n == 1) {
        if (S[0] == '5' || S[0] == '?') {
            printf("1\n");
        } else {
            printf("0\n");
        }
        return 0;
    }

    int dp[n][13];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (S[i] != '?') {
                dp[i][S[i] - '0']++;
            } else {
                for (int j = 0; j < 10; j++) {
                    dp[i][j]++;
                }
            }
        } else {
            if (S[i] != '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + S[i] - '0') % 13] = (dp[i][(k * 10 + S[i] - '0') % 13] + dp[i - 1][k]) % MOD;
                }
            } else {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] = (dp[i][(k * 10 + j) % 13] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }
    }

    printf("%d\n", dp[n - 1][5]);
    return 0;
}
