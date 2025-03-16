
#include <stdio.h>
#include <math.h>

int max(int lhs, int rhs) {
    return (int)fmax(lhs, rhs);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int values[N];
    int weights[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    int dp[N+1][M+1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= weights[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]);
            }
        }
    }
    printf("%d\n", dp[N][M]);
    return 0;
}
