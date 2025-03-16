#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 501

int getNextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

void matrixChainMultiplication(int n, int mm[], int dp[][MAX_N]) {
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = 0x7FFFFFFF; // Initialize to a large number
            for (int k = i; k <= j - 1; k++) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }
}

int main() {
    int n = getNextInt();
    int mm[MAX_N];
    int dp[MAX_N][MAX_N];

    for (int i = 0; i < n; i++) {
        mm[i] = getNextInt();
        mm[i + 1] = getNextInt();
    }

    memset(dp, 0, sizeof(dp));
    matrixChainMultiplication(n, mm, dp);

    printf("%d\n", dp[1][n]);

    return 0;
}
