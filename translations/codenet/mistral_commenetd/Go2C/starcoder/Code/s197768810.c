
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int readInt() {
	// Declare a variable to store the input
	int input;
	// Read a word from standard input
	scanf("%d", &input);
	// Return the read integer
	return input;
}

// Function to read a float64 from standard input
double readFloat64() {
	// Declare a variable to store the input
	double input;
	// Read a word from standard input
	scanf("%lf", &input);
	// Return the read float64
	return input;
}

// Function to read a string from standard input
char* readString() {
	// Declare a variable to store the input
	char input[1000];
	// Read a word from standard input
	scanf("%s", input);
	// Return the read string
	return input;
}

// Main function
int main() {
	// Read the number of elements n and the number of queries m from standard input
	int n = readInt();
	int m = readInt();
	// Allocate an array a of size n
	int* a = (int*) malloc(n * sizeof(int));
	// Initialize a variable sum to keep track of the sum of elements in the array
	int sum = 0;
	// Process each query
	for (int i = 0; i < m; i++) {
		// Read an integer from standard input and add it to the array a
		a[i] = readInt();
		// Add the current element to the sum
		sum += a[i];
		// Check if the sum is greater than the size of the array
		if (sum > n) {
			// If so, print -1 and exit the program
			printf("-1");
			return 0;
		}
	}
	// Print the result, which is the difference between the size of the array and the sum of its elements
	printf("%d", n - sum);
	return 0;
}

