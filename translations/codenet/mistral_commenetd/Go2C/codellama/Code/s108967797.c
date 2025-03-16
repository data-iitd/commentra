
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int ri() {
	int n; // Initialize a variable to store the read integer
	scanf("%d", &n); // Read an integer from standard input
	return n; // Return the read integer
}

// Function to calculate the average of a slice of float64 numbers
float ave(float *s, int n) {
	float sum = 0; // Initialize a variable to store the sum of numbers in the slice
	for (int i = 0; i < n; i++) { // Iterate through each number in the slice
		sum += s[i]; // Add the current number to the sum
	}
	return sum / n; // Calculate and return the average
}

// Function to calculate the difference between two float64 numbers
float diff(float a, float b) {
	if (a > b) { // Check if the first number is greater than the second number
		return a - b; // If so, return the difference
	}
	return b - a; // If not, return the negative difference
}

// Main function
int main() {
	// Read the number of elements in the array from standard input
	int n = ri();

	// Allocate memory for an array of float64 numbers with the given size
	float *a = (float *)malloc(n * sizeof(float));

	// Read each element of the array from standard input and store it in the corresponding index
	for (int i = 0; i < n; i++) {
		a[i] = ri(); // Read an integer from standard input and convert it to a float64 number
	}
	// Print the array for debugging purposes (uncomment this line if needed)
	// printf("%f\n", a);

	// Calculate the average of the array elements
	float ave = ave(a, n);

	// Initialize variables to store the minimum difference and the index of the element with the minimum difference
	float minDiff = 999999.9;
	int ansIndex = -1;

	// Iterate through each element of the array and find the one with the minimum difference from the average
	for (int i = 0; i < n; i++) {
		float diff = diff(a[i], ave); // Calculate the difference between the current element and the average
		if (diff < minDiff) { // Check if the difference is smaller than the current minimum difference
			minDiff = diff; // If so, update the minimum difference
			ansIndex = i; // and the index of the answer
		}
	}

	// Print the index of the element with the minimum difference from the average
	printf("%d\n", ansIndex);

	// Free the allocated memory
	free(a);

	return 0;
}

