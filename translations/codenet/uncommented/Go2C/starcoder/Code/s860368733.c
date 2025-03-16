#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	int *h = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	int *counter = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (h[a-1] < h[b-1]) {
			counter[a] = 1;
		} else if (h[a-1] > h[b-1]) {
			counter[b] = 1;
		} else if (h[a-1] == h[b-1]) {
			counter[a] = 1;
			counter[b] = 1;
		}
	}
	printf("%d\n", n - __builtin_popcount(counter[0], n));
	free(h);
	free(counter);
}
