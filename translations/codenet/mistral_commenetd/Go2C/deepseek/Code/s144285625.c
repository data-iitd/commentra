#include <stdio.h>
#include <stdlib.h>

// Function to read next integer from input
int nextInt() {
	int num;
	scanf("%d", &num);
	return num;
}

// Main function
int main() {
	// Reading the number of elements in the array
	int n = nextInt();

	// Allocating memory for the array
	int *ar = (int *)malloc(3 * n * sizeof(int));

	// Reading elements of the array
	for (int i = 0; i < 3 * n; i++) {
		// Reading next integer and storing it in the array
		ar[i] = nextInt();
	}

	// Sorting the array in ascending order
	qsort(ar, 3 * n, sizeof(int), (int (*)(const void *, const void *))compare);

	// Calculating the sum of elements at index 3n-2i-1 in the sorted array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		// Adding the element at index 3n-2i-1 to the sum
		sum += ar[3 * n - (i + 1) * 2];
	}

	// Printing the result
	printf("%d\n", sum);

	// Freeing the allocated memory
	free(ar);

	return 0;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}
