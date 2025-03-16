#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, K, d, a, ans = 0;
	scanf("%d %d", &N, &K);
	int *as = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		as[i] = 0;
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &d);
		for (int j = 0; j < d; j++) {
			scanf("%d", &a);
			as[a - 1]++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (as[i] == 0) {
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
