
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	int N;
	scanf("%d", &N);
	int A[N];
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	long long dp[N][2][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 20; j++) {
			dp[i][0][j] = LLONG_MIN;
			dp[i][1][j] = LLONG_MIN;
		}
	}

	dp[0][0][10] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 6; j <= 14; j++) {
			if (dp[i - 1][0][j]!= LLONG_MIN) {
				dp[i][1][j + 1] = fmax(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
				dp[i][0][j - 1] = fmax(dp[i][0][j - 1], dp[i - 1][0][j]);
			}
			if (dp[i - 1][1][j]!= LLONG_MIN) {
				dp[i][0][j - 1] = fmax(dp[i][0][j - 1], dp[i - 1][1][j]);
			}
		}
	}

	long long V = 10 + (N / 2) - (N - (N / 2));
	long long T1 = dp[N - 1][0][V];
	long long T2 = dp[N - 1][1][V];

	printf("%lld\n", fmax(T1, T2));

	return 0;
}
