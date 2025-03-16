#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	float arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%f", &arr[i]);
	}
	qsort(arr, n, sizeof(float), compare);
	float prev = arr[0];
	for (int i = 1; i < n; i++) {
		prev = (prev + arr[i]) / 2;
	}
	printf("%f\n", prev);
}

int compare(const void *a, const void *b) {
	return *(float*)a - *(float*)b;
}

