#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int *mm = (int *)malloc(sizeof(int) * (n+1));
	int **dp = (int **)malloc(sizeof(int *) * (n+1));
	for (int i = 0; i <= n; i++) {
		dp[i] = (int *)malloc(sizeof(int) * (n+1));
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &mm[i]);
		scanf("%d", &mm[i+1]);
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n-l+1; i++) {
			int j = i + l - 1;
			for (int k = i; k <= j-1; k++) {
				int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}
