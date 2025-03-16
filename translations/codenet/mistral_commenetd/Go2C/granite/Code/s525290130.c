
#include <stdio.h>
#include <stdlib.h>

// Function to read next integer from the standard input
int nextInt(FILE *sc) {
	int t;
	scanf("%d", &t);
	return t;
}

// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
void reva(int *b, int n) {
	// Reverse the subarray using a simple method of swapping elements
	for (int i = 0; i < n/2; i++) {
		int temp = b[i];
		b[i] = b[n-1-i];
		b[n-1-i] = temp;
	}
}

int main() {
	// Initialize a file pointer'sc' to read input from standard input
	FILE *sc = stdin;

	// Read the number of elements in the array 'a'
	int n = nextInt(sc);
	// Allocate memory for the array 'a' of size 'n'
	int *a = (int*)malloc(n * sizeof(int));

	// Read 'n' integers from the standard input and store them in the array 'a'
	for (int i = 0; i < n; i++) {
		a[i] = nextInt(sc);
	}

	// Read the number of queries 'q'
	int q = nextInt(sc);

	// Process each query by reversing the subarray of 'a'
	for (int i = 0; i < q; i++) {
		// Read the starting and ending indices of the subarray to be reversed
		int b = nextInt(sc);
		int e = nextInt(sc);

		// Reverse the subarray 'a[b:e]'
		reva(&a[b], e-b);
	}

	// Write the reversed array 'a' to the standard output
	for (int i = 0; i < n; i++) {
		// Write each element of the array 'a' to the standard output with a space in between (except for the first element)
		if (i > 0) {
			printf(" ");
		}
		printf("%d", a[i]);
	}

	// Flush the output buffer to write the output to the standard output
	fflush(stdout);

// End of the code