

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Initialize variables and read input
	// Code for A - Initialize variables and read input
	int N;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &N);

	int *A = (int*)malloc(N * sizeof(int));
	printf("Enter the elements of the array: ");
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	// Sort the array in ascending order
	// Code for C - Sort the array
	qsort(A, N, sizeof(int), cmpfunc);

	// Calculate the answer
	// Code for D - Calculate the answer
	int ans = 0;
	printf("Calculating the answer...\n");
	for (int i = 1; i < N; i++) {
		ans += A[i] - A[i-1];
	}

	// Print the answer
	// Code for E - Print the answer
	printf("The answer is: %d\n", ans);

	// Free memory
	free(A);

	return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

