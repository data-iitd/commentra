#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, i, j, ai, bi, ans;
	scanf("%d %d", &n, &m);
	int *h = (int *)malloc(n * sizeof(int));
	int *good = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &h[i]);
		good[i] = 1;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &ai, &bi);
		ai--;
		bi--;
		if (h[ai] > h[bi]) {
			good[bi] = 0;
		} else if (h[ai] < h[bi]) {
			good[ai] = 0;
		} else {
			good[ai] = 0;
			good[bi] = 0;
		}
	}
	ans = 0;
	for (i = 0; i < n; i++) {
		if (good[i]) {
			ans++;
		}
	}
	printf("%d\n", ans);
	free(h);
	free(good);
	return 0;
}
