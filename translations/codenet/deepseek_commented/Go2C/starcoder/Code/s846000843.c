#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000

int main() {
	int n;
	scanf("%d", &n);
	int a[MAX_N];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int cumsum[MAX_N];
	cumsum[0] = 0;
	for (int i = 0; i < n; i++) {
		cumsum[i+1] = cumsum[i] + a[i];
	}
	int ans = 2020202020;
	for (int i = 1; i < n-1; i++) {
		int diff = abs(cumsum[n-1] - cumsum[i] - (cumsum[i] - cumsum[0]));
		if (diff < ans) {
			ans = diff;
		}
	}
	printf("%d\n", ans);
}

