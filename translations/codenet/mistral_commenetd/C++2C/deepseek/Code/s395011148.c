#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1 << 18
#define MAXJ 20

long long N, A[MAXN];
long long dp[MAXN][2][MAXJ];

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < MAXJ; j++) {
			dp[i][0][j] = -(1LL << 60);
			dp[i][1][j] = -(1LL << 60);
		}
	}

	dp[0][0][10] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 6; j <= 14; j++) {
			if (dp[i - 1][0][j] != (1LL << 60)) {
				if (dp[i][1][j + 1] < dp[i - 1][0][j] + A[i]) {
					dp[i][1][j + 1] = dp[i - 1][0][j] + A[i];
				}
				if (dp[i][0][j - 1] < dp[i - 1][0][j]) {
					dp[i][0][j - 1] = dp[i - 1][0][j];
				}
			}
			if (dp[i - 1][1][j] != (1LL << 60)) {
				if (dp[i][0][j - 1] < dp[i - 1][1][j]) {
					dp[i][0][j - 1] = dp[i - 1][1][j];
				}
			}
		}
	}

	long long V = 10LL + (N / 2) - (N - (N / 2));
	long long T1 = dp[N][0][V];
	long long T2 = dp[N][1][V];

	printf("%lld\n", (T1 > T2) ? T1 : T2);

	return 0;
}
