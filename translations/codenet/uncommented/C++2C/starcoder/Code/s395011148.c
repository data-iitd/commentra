#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

int main() {
	int N;
	scanf("%d", &N);
	int A[1 << 18];
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	int dp[1 << 18][2][20];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 20; j++) {
			dp[i][0][j] = -(1LL << 60);
			dp[i][1][j] = -(1LL << 60);
		}
	}
	dp[0][0][10] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 6; j <= 14; j++) {
			if (dp[i - 1][0][j]!= (1LL << 60)) {
				dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j]);
			}
			if (dp[i - 1][1][j]!= (1LL << 60)) {
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j]);
			}
		}
	}

	int V = 10LL + (N / 2) - (N - (N / 2));
	int T1 = dp[N][0][V];
	int T2 = dp[N][1][V];
	printf("%d\n", max(T1, T2));
	return 0;
}

