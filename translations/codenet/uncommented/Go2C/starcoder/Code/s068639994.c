#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100000

int main() {
	int n = getInt();
	int ls[MAX_N];
	for (int i = 0; i < n; i++) {
		ls[i] = getInt();
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			int x = q - p;
			int y = q + p;

			int l = 0;
			while (l < n && ls[l] <= x) {
				l++;
			}
			int r = n - 1;
			while (r >= 0 && ls[r] >= y) {
				r--;
			}

			int sum = r - l;
			if (i >= l && i <= r) {
				sum--;
			}
			if (j >= l && j <= r) {
				sum--;
			}
			sum = max(0, sum);
			ans += sum;
		}
	}

	ans /= 3;
	puts(ans);
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// -----------------------------------------

int getInt() {
	scanf("%d", &input);
	return input;
}

void puts(int a) {
	printf("%d\n", a);
}

