#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	float *a = (float *) malloc(n * sizeof(float));
	for (int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}
	for (int i = 0; i + 1 < n; i++) {
		qsort(a, n, sizeof(float), compare);
		float *na = (float *) malloc(0);
		for (int j = 2; j < n; j++) {
			na = (float *) realloc(na, (j - 1) * sizeof(float));
			na[j - 2] = a[j];
		}
		na = (float *) realloc(na, (n - 1) * sizeof(float));
		na[n - 2] = (a[0] + a[1]) / 2;
		a = na;
	}
	printf("%f\n", a[0]);
	free(a);
	return 0;
}

float compare(const void *a, const void *b) {
	return *(float *) a - *(float *) b;
}

