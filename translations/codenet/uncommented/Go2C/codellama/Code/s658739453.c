#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define d 1000000007

int main() {
	int n, p;
	scanf("%d", &n);
	scanf("%d", &p);

	int64_t mdans[p];
	for (int index = 0; index < p; index++) {
		int64_t n1;
		scanf("%ld", &n1);
		mdans[index] = n1;
	}

	int64_t dp[n+1];
	dp[0] = 1;
	dp[1] = 1;

	if (mdans[1]) {
		dp[1] = 0;
	}

	for (int i = 2; i <= n; i++) {
		if (mdans[i]) {
			continue;
		}
		dp[i] = (dp[i-1] + dp[i-2]) % d;

	}

	printf("%ld\n", dp[n]);
}

