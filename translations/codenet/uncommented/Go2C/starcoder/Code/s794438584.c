#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(lhs, rhs) ((lhs) > (rhs)? (lhs) : (rhs))

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int *values = (int *) malloc(sizeof(int) * N);
	int *weights = (int *) malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &weights[i], &values[i]);
	}
	int **dp = (int **) malloc(sizeof(int *) * (N + 1));
	for (int i = 0; i < N + 1; i++) {
		dp[i] = (int *) malloc(sizeof(int) * (M + 1));
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

