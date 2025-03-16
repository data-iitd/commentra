#include <stdio.h>

int min(int nums, ...);

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	printf("%d\n", min(n*a, b));

	return 0;
}

int min(int nums, ...) {
	int min = nums;
	int v;
	for (int i = 1; i < nums; i++) {
		v = va_arg(nums, int);
		if (v < min) {
			min = v;
		}
	}
	return min;
}

