#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int *aa = (int *)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &aa[i]);
	}

	int *dp = (int *)malloc(sizeof(int) * (n + 1));
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			if (aa[i + ii] == 1) {
				continue;
			}
			dp[i + ii] += dp[i];
			dp[i + ii] %= 1000000007;
		}
	}
	printf("%d\n", dp[n]);

	free(aa);
	free(dp);
	return 0;
}
