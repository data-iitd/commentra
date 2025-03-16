#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int main() {
	int n, x;
	scanf("%d %d", &n, &x);

	int *A = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, n, sizeof(int), compare);

	int ans = 0;
	int i = 0, j = 0;
	while (j < n) {
		if (x >= A[i]) {
			ans++;
			x -= A[i];
			i++;
		} else {
			j++;
		}
	}

	if (x > 0 && n == ans) {
		ans--;
	}

	printf("%d\n", ans);

	free(A);

	return 0;
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

