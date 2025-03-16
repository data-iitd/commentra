#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Code for B - Traveling AtCoDeer Problem
	int N;
	scanf("%d", &N);

	int *A = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, N, sizeof(int), compare);

	int ans = 0;
	for (int i = 1; i < N; i++) {
		ans += A[i] - A[i-1];
	}

	printf("%d\n", ans);

	free(A);

	return 0;
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

