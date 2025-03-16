#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int lhs, int rhs) {
    return (int)fmax(lhs, rhs);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int *values = (int *)malloc(N * sizeof(int));
    int *weights = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    int **dp = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i < N + 1; i++) {
        dp[i] = (int *)malloc((M + 1) * sizeof(int));
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= weights[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }
    printf("%d\n", dp[N][M]);
    for (int i = 0; i < N + 1; i++) {
        free(dp[i]);
    }
    free(dp);
    free(values);
    free(weights);
    return 0;
}
