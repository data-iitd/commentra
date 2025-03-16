#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUF_SIZE 10000000

int main() {
	int n;
	int *as;
	int *xs;
	int b;
	int i;
	int ans;

	scanf("%d", &n);
	as = (int *)malloc(sizeof(int) * n);
	xs = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &as[i]);
		xs[i] = as[i] - i + 1;
	}
	qsort(xs, n, sizeof(int), cmp);

	b = xs[n / 2];
	ans = 0;
	for (i = 0; i < n; i++) {
		ans += abs(xs[i] - b);
	}
	printf("%d\n", ans);

	free(as);
	free(xs);
	return 0;
}

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int abs(int n) {
	if (n < 0) {
		return -n;
	}
	return n;
}

