#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define d 1000000007

int main() {
	int n, p;
	scanf("%d", &n);
	scanf("%d", &p);

	int64_t *mdans = malloc(sizeof(int64_t) * p);
	for (int index = 0; index < p; index++) {
		int64_t n1;
		scanf("%ld", &n1);
		mdans[index] = n1;
	}

	int64_t *dp = malloc(sizeof(int64_t) * (n+1));
	dp[0] = 1;
	dp[1] = 1;

	if (mdans[0] == 1) {
		dp[1] = 0;
	}

	for (int i = 2; i <= n; i++) {
		if (mdans[i-1] == i) {
			continue;
		}
		dp[i] = (dp[i-1] + dp[i-2]) % d;
	}

	printf("%ld\n", dp[n]);
	free(dp);
	free(mdans);
	return 0;
}
