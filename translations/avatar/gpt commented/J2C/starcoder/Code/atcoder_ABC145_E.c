#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#define MAX_N 100000
#define MAX_T 6000

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    int A[MAX_N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A[i][0], &A[i][1]);
    }
    int dp[MAX_N + 1][MAX_T + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            if (i == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            if (0 <= j - A[i - 1][0] && j - A[i - 1][0] < T) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - A[i - 1][0]] + A[i - 1][1]);
            }
        }
    }
    printf("%d\n", dp[N][T]);
    return 0;
}

