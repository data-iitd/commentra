// Importing necessary packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read next integer from the standard input
int nextInt(FILE *fp) {
	int t; // Declare a variable to store the integer
	fscanf(fp, "%d", &t); // Read the next integer from the standard input
	return t; // Return the integer
}

// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
void reva(int *a, int b, int e) {
	// Reverse the subarray using a simple method of swapping elements
	for (int i = 0; i < (e - b + 1) / 2; i++) {
		a[b + i] ^= a[e - i];
		a[e - i] ^= a[b + i];
		a[b + i] ^= a[e - i];
	}
}

// Main function
int main() {
	// Initialize a file pointer to read input from standard input
	FILE *fp = stdin;

	// Read the number of elements in the array 'a'
	int n = nextInt(fp);
	// Allocate memory for the array 'a' of size 'n'
	int *a = (int *)malloc(n * sizeof(int));

	// Read 'n' integers from the standard input and store them in the array 'a'
	for (int i = 0; i < n; i++) {
		a[i] = nextInt(fp);
	}

	// Read the number of queries 'q'
	int q = nextInt(fp);

	// Process each query by reversing the subarray of 'a'
	for (int i = 0; i < q; i++) {
		// Read the starting and ending indices of the subarray to be reversed
		int b = nextInt(fp);
		int e = nextInt(fp);

		// Reverse the subarray 'a[b:e]'
		reva(a, b, e);
	}

	// Write the reversed array 'a' to the standard output
	for (int i = 0; i < n; i++) {
		// Write each element of the array 'a' to the standard output with a space in between (except for the first element)
		if (i > 0) {
			printf(" ");
		}
		printf("%d", a[i]);
	}

	// Free the memory allocated for the array 'a'
	free(a);

	// End of the code
	return 0;
}