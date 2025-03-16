#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 500
#define INF 1000000000

int dp[MAX_N + 1][MAX_N + 1];
int mm[MAX_N + 1];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &mm[i], &mm[i + 1]);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] > cost) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("%d\n", dp[1][n]);

    return 0;
}
