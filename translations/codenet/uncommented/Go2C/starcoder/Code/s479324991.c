#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), cmp);
	int prev = arr[0];
	for (int i = 1; i < n; i++) {
		prev = (prev + arr[i]) / 2;
	}
	printf("%d\n", prev);
}

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

