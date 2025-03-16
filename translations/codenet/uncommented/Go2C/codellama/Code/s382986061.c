#include <stdio.h>

int main() {
	int N, K, d, a;
	int as[100000];
	int i, j;
	int ans;

	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		as[i] = 0;
	}
	for (i = 0; i < K; i++) {
		scanf("%d", &d);
		for (j = 0; j < d; j++) {
			scanf("%d", &a);
			as[a]++;
		}
	}
	ans = 0;
	for (i = 1; i <= N; i++) {
		if (as[i] == 0) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

