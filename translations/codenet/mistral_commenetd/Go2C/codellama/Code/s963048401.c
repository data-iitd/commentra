
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to read a single string from stdin and return it
char* scanner() {
	char* s = malloc(1000000 * sizeof(char));
	fgets(s, 1000000, stdin);
	return s;
}

// Function to read an integer from stdin and return it
int intScanner() {
	char* s = scanner();
	int n = atoi(s);
	free(s);
	return n;
}

// Function to read a floating point number from stdin and return it
float floatScanner() {
	char* s = scanner();
	float n = atof(s);
	free(s);
	return n;
}

// Function to convert a string to an integer
int stringToInt(char* s) {
	int n = atoi(s);
	return n;
}

// Function to read input and process it
int main() {
	// Initialize the scanner buffer and split function for the scanner
	char* buf = malloc(1000000 * sizeof(char));
	char* s = malloc(1000000 * sizeof(char));
	fgets(buf, 1000000, stdin);
	fgets(s, 1000000, stdin);
	int n = atoi(s);
	free(s);

	// Initialize an array of size n to store the elements
	int* as = malloc(n * sizeof(int));

	// Read the elements of the array into the as slice
	for (int i = 0; i < n; i++) {
		s = scanner();
		as[i] = atoi(s);
		free(s);
	}

	// Initialize an empty slice xs to store the unique elements
	int* xs = malloc(1 * sizeof(int));
	xs[0] = as[0];

	// Iterate through the array and add unique elements to the xs slice
	for (int j = 1; j < n; j++) {
		// Binary search to find the index where the current element should be inserted in the xs slice
		int idx = 0;
		for (int i = 0; i < j; i++) {
			if (as[j] < xs[i]) {
				idx = i;
				break;
			}
		}

		// If the current element is not already present in the xs slice, append it
		if (idx == j) {
			xs = realloc(xs, (j + 1) * sizeof(int));
			xs[j] = as[j];
		} else {
			// Otherwise, replace the element at the found index with the current element
			xs[idx] = as[j];
		}
	}

	// Print the length of the xs slice
	printf("%d\n", j);

	// Free the allocated memory
	free(buf);
	free(as);
	free(xs);

	return 0;
}

