#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	double *a = (double *)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	for (int i = 0; i + 1 < n; i++) {
		qsort(a, n, sizeof(double), cmp);
		double *na = (double *)malloc((n - 2) * sizeof(double));
		for (int j = 2; j < n; j++) {
			na[j - 2] = a[j];
		}
		na[n - 3] = (a[0] + a[1]) / 2;
		free(a);
		a = na;
	}
	printf("%lf\n", a[0]);
	free(a);
	return 0;
}

int cmp(const void *a, const void *b) {
	return *(double *)a - *(double *)b;
}

