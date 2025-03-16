
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

// Initialize the modulus value
#define mod 1000000007

// Function to read input and process it
int main(void) {
	// Initialize a buffer to store the unique elements
	int buf[mod];

	// Read the number of elements in the array
	int n = atoi(fgets(buf, mod, stdin));

	// Initialize an array of size n to store the elements
	int as[n];

	// Read the elements of the array into the as slice
	for (int i = 0; i < n; i++) {
		as[i] = atoi(fgets(buf, mod, stdin));
	}

	// Initialize an empty slice xs to store the unique elements
	int xs[n];
	int xs_len = 0;

	// Iterate through the array and add unique elements to the xs slice
	for (int j = 0; j < n; j++) {
		// Binary search to find the index where the current element should be inserted in the xs slice
		int idx = 0;
		while (idx < xs_len && xs[idx] < as[j]) {
			idx++;
		}

		// If the current element is not already present in the xs slice, append it
		if (idx == xs_len) {
			xs[xs_len] = as[j];
			xs_len++;
		} else {
			// Otherwise, replace the element at the found index with the current element
			xs[idx] = as[j];
		}
	}

	// Print the length of the xs slice
	printf("%d\n", xs_len);
}

