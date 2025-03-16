#include <stdio.h>
#include <stdlib.h>

int main() {
	// Read the number of elements N from input
	int N;
	scanf("%d", &N);

	// Initialize a slice A to hold N integers
	int *A = (int *)malloc(N * sizeof(int));
	
	// Read N integers from input into the slice A
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	// Sort the slice A in ascending order
	qsort(A, N, sizeof(int), compare);

	// Initialize a variable to hold the total difference sum
	int ans = 0;
	
	// Calculate the sum of differences between consecutive elements in the sorted slice
	for (int i = 1; i < N; i++) {
		ans += A[i] - A[i-1];
	}

	// Output the total sum of differences
	printf("%d\n", ans);

	// Free the memory allocated for the slice A
	free(A);

	return 0;
}

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

