
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		n = n >> 1;
	}
	return res;
}

int main() {
	int n, i, j, k, ans;
	int *c;

	scanf("%d", &n);

	c = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	ans = 0;
	qsort(c, n, sizeof(int), compare);

	for (i = 0; i < n; i++) {
		ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
	}

	printf("%d\n", ans * modpow(4, n - 1) % mod);

	free(c);

	return 0;
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

