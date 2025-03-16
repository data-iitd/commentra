
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[100001];
    int x, y;
    scanf("%s %d %d", S, &x, &y);

    int F[100001];
    int i, j, k, l, m, n;
    i = j = k = l = m = n = 0;
    for (int p = 0; S[p]!= '\0'; p++) {
        if (S[p] == 'F') {
            i++;
        } else {
            F[j++] = i;
            i = 0;
        }
    }
    F[j++] = i;

    int dp[2][20001];
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 20001; q++) {
            dp[p][q] = 0;
        }
    }
    dp[0][10000] = 1;
    dp[1][10000] = 1;
    for (int p = 0; p < j; p++) {
        for (int q = 0; q < 20001; q++) {
            if (dp[p % 2][q] == 1) {
                if (q + F[p] < 20001) {
                    dp[(p + 1) % 2][q + F[p]] = 1;
                }
                if (q - F[p] >= 0) {
                    dp[(p + 1) % 2][q - F[p]] = 1;
                }
            }
        }
    }
    if (dp[j % 2][x + 10000] == 1 && dp[j % 2][y + 10000] == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
