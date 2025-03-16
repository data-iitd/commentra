
#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

// Function to calculate the average of a slice of float64 numbers
float64 ave(float64 *s, int n) {
	float64 sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum += s[i];
	}
	return sum / float64(n);
}

// Function to calculate the difference between two float64 numbers
float64 diff(float64 a, float64 b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// Main function
int main() {
	// Read the number of elements in the array from standard input
	int n = ri();

	// Allocate memory for an array of float64 numbers with the given size
	float64 *a = (float64 *)malloc(n * sizeof(float64));

	// Read each element of the array from standard input and store it in the corresponding index
	for (int i = 0; i < n; i++) {
		a[i] = float64(ri());
	}

	// Calculate the average of the array elements
	float64 ave = ave(a, n);

	// Initialize variables to store the minimum difference and the index of the element with the minimum difference
	float64 minDiff = 999999.9;
	int ansIndex = -1;

	// Iterate through each element of the array and find the one with the minimum difference from the average
	for (int i = 0; i < n; i++) {
		float64 diff = diff(a[i], ave);
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}

	// Print the index of the element with the minimum difference from the average
	printf("%d\n", ansIndex);

	// Free the allocated memory
	free(a);

	// Return from main
	return 0;
}

