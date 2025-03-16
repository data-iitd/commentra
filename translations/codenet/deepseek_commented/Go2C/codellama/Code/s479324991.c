#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	
	double *arr = (double *)malloc(n * sizeof(double));
	
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}
	
	qsort(arr, n, sizeof(double), cmp);
	
	double prev = arr[0];
	
	for (int i = 1; i < n; i++) {
		prev = (prev + arr[i]) / 2;
	}
	
	printf("%lf\n", prev);
	
	return 0;
}

int cmp(const void *a, const void *b) {
	return *(double *)a - *(double *)b;
}

