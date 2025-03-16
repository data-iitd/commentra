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
	//fmt.Println(N, M)
	//fmt.Println(values, weights)
	int dp[N+1][M+1];
	for (int i = 0; i < N+1; i++) {
		for (int j = 0; j < M+1; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= weights[i-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]);
			}
		}
	}
	printf("%d\n", dp[N][M]);
	return 0;
}

