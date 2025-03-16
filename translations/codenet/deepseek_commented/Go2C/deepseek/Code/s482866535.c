#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 500
#define INF 1000000000

int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int readMatrixDimensions(int mm[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &mm[i], &mm[i + 1]);
    }
}

void matrixChainMultiplication(int mm[], int n, int dp[][MAX_N + 1]) {
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INF;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
}

int main() {
    int n = readInt();
    int mm[MAX_N];
    int dp[MAX_N + 1][MAX_N + 1];

    readMatrixDimensions(mm, n);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    matrixChainMultiplication(mm, n, dp);

    printf("%d\n", dp[1][n]);

    return 0;
}
