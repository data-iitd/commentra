#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, m, i, ai, bi, ans;
	int *h, *good;
	char *line;
	size_t size;

	if (scanf("%d %d", &n, &m) != 2) {
		return 1;
	}
	h = (int *)malloc(n * sizeof(int));
	good = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		if (scanf("%d", &h[i]) != 1) {
			return 1;
		}
		good[i] = 1;
	}
	for (i = 0; i < m; i++) {
		if (scanf("%d %d", &ai, &bi) != 2) {
			return 1;
		}
		if (h[ai - 1] > h[bi - 1]) {
			good[bi - 1] = 0;
		} else if (h[ai - 1] < h[bi - 1]) {
			good[ai - 1] = 0;
		} else {
			good[ai - 1] = 0;
			good[bi - 1] = 0;
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

