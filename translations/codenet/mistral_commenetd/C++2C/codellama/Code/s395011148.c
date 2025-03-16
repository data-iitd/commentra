#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 1000000
#define MAX_J 20

long long N, A[MAX_N];
long long dp[MAX_N][2][MAX_J];

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	// Initialize dp array with minimum values
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < MAX_J; j++) {
			dp[i][0][j] = LLONG_MIN;
			dp[i][1][j] = LLONG_MIN;
		}
	}

	// Base case: dp[0][0][10] = 0
	dp[0][0][10] = 0;

	// Iterate through all the elements of the array A
	for (int i = 1; i <= N; i++) {
		for (int j = 6; j <= 14; j++) {
			if (dp[i - 1][0][j] != LLONG_MIN) {
				dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j]);
			}
			if (dp[i - 1][1][j] != LLONG_MIN) {
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j]);
			}
		}
	}

	// Calculate the value of T1 and T2
	long long V = 10LL + (N / 2) - (N - (N / 2));
	long long T1 = dp[N][0][V];
	long long T2 = dp[N][1][V];

	// Print the maximum value of T1 and T2
	printf("%lld\n", max(T1, T2));

	return 0;
}

