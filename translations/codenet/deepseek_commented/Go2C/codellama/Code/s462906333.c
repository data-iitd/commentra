#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 10000

// ---------------------------------------------------------
int main() {
	int n, x, i, k, kans, ans;
	int a[MAX_SIZE], v[MAX_SIZE];
	char line[MAX_SIZE];

	scanf("%d", &n);
	scanf("%d", &x);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		v[i] = a[i];
	}
	ans = 1e14;
	for (k = 0; k < n; k++) {
		kans = 0;
		for (i = 0; i < n; i++) {
			if (i - k < 0) {
				v[i] = min(v[i], a[n + i - k]);
			} else {
				v[i] = min(v[i], a[i - k]);
			}
			kans += v[i];
		}
		ans = min(ans, kans + k * x);
	}

	printf("%d\n", ans);

	return 0;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// 