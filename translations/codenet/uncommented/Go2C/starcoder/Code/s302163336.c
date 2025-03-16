#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int *h = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	int *good = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		good[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int ai, bi;
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
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

