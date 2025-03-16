#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 100000

int main() {
	int n;
	scanf("%d", &n);
	int a[MAX_N];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int xs[MAX_N];
	for (int i = 0; i < n; i++) {
		xs[i] = a[i] - i + 1;
	}
	qsort(xs, n, sizeof(int), cmp);

	int b = xs[n / 2];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(xs[i] - b);
	}
	printf("%d\n", ans);
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

// 