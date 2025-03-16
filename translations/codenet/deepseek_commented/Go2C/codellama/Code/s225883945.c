#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, k;
	int *a;
	int i, sum, ans;

	scanf("%d %d", &n, &k);
	a = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	// Set the first element of `a` to 0 to avoid unused variable error.
	a[0] = 0;

	sum = k;
	ans = 1;
	// Loop to increment `sum` and `ans` until `sum` is less than `n`.
	while (sum < n) {
		sum = sum - 1 + k;
		ans++;
	}
	printf("%d\n", ans);

	free(a);
	return 0;
}
