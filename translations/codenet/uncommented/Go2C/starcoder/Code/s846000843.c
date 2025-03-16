#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 1000000

int main() {
	int n;
	scanf("%d", &n);

	int aa[MAX_N];
	for (int i = 0; i < n; i++) {
		scanf("%d", &aa[i]);
	}

	int cumsum[MAX_N];
	cumsum[0] = aa[0];
	for (int i = 1; i < n; i++) {
		cumsum[i] = cumsum[i-1] + aa[i];
	}

	int ans = 2020202020;
	for (int i = 1; i < n-1; i++) {
		ans = fmin(ans, abs(cumsum[n-1] - cumsum[i] - (cumsum[i] - cumsum[0])));
	}

	printf("%d\n", ans);
}

