

#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

// Function to calculate the average of a slice of float64 numbers
double ave(double *s, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i];
	}
	return sum / n;
}

// Function to calculate the difference between two float64 numbers
double diff(double a, double b) {
	return a > b? a - b : b - a;
}

int main() {
	// Read the number of elements in the array from standard input
	int n = ri();

	// Allocate memory for an array of float64 numbers with the given size
	double *a = (double *)malloc(sizeof(double) * n);

	// Read each element of the array from standard input and store it in the corresponding index
	for (int i = 0; i < n; i++) {
		a[i] = ri();
	}

	// Print the array for debugging purposes (uncomment this line if needed)
	// for (int i = 0; i < n; i++) {
	// 	printf("%f ", a[i]);
	// }
	// printf("\n");

	// Calculate the average of the array elements
	double ave = ave(a, n);

	// Initialize variables to store the minimum difference and the index of the element with the minimum difference
	double minDiff = 999999.9;
	int ansIndex = -1;

	// Iterate through each element of the array and find the one with the minimum difference from the average
	for (int i = 0; i < n; i++) {
		double diff = diff(a[i], ave);
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}

	// Print the index of the element with the minimum difference from the average
	printf("%d\n", ansIndex);

// End of the code


Translate the above C code to Rust and end with comment "