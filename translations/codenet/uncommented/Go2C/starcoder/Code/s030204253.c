#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	float *a = (float *)malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}
	for (int i = 0; i + 1 < n; i++) {
		qsort(a, n - i - 1, sizeof(float), cmp);
		float *na = (float *)malloc(sizeof(float) * (n - i - 2));
		for (int j = 2; j < n - i - 1; j++) {
			na[j - 2] = a[j];
		}
		na[n - i - 3] = (a[0] + a[1]) / 2;
		free(a);
		a = na;
	}
	printf("%f\n", a[0]);
	free(a);
}

int cmp(const void *a, const void *b) {
	return *(float *)a - *(float *)b;
}

