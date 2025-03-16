


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the number of elements from standard input
	int n;
	scanf("%d", &n);

	// Initialize a slice to hold the float64 numbers
	float *a = (float *)malloc(n * sizeof(float));

	// Read n float64 numbers from standard input into the slice
	for (int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}

	// Perform a series of operations to reduce the slice
	for (int i = 0; i + 1 < n; i++) {
		// Sort the slice in ascending order
		qsort(a, n, sizeof(float), compare);

		// Create a new slice to hold the modified values
		float *na = (float *)malloc(0);

		// Append all elements from the third element onward to the new slice
		for (int j = 2; j < n; j++) {
			na = (float *)realloc(na, (j - 1) * sizeof(float));
			memcpy(na + (j - 2), a + j, sizeof(float));
		}

		// Calculate the average of the first two elements and append it to the new slice
		float avg = (a[0] + a[1]) / 2;
		na = (float *)realloc(na, (n - 2) * sizeof(float));
		memcpy(na + (n - 3), &avg, sizeof(float));

		// Update the original slice to be the new slice
		free(a);
		a = na;
	}

	// Print the final remaining element in the slice
	printf("%f\n", a[0]);

	free(a);
	return 0;
}

float compare(const void *a, const void *b) {
	return *(float *)a - *(float *)b;
}

