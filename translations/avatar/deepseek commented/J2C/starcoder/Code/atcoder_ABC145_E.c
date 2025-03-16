
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_T 6000

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    int AB[MAX_N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i][0], &AB[i][1]);
    }
    int dp[MAX_N + 1][MAX_T + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T; j++) {
            dp[i][j] = dp[i - 1][j];
            if (0 <= j - AB[i - 1][0] && j - AB[i - 1][0] < T) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - AB[i - 1][0]] + AB[i - 1][1]);
            }
        }
    }
    printf("%d\n", dp[N][T]);
    return 0;
}

