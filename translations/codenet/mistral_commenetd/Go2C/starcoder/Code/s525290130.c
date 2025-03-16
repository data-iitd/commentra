// Importing necessary packages
#include <stdio.h>
#include <stdlib.h>

// Function to read next integer from the standard input
int nextInt(int *sc) {
	scanf("%d", sc);
	return *sc;
}

// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
void reva(int *a, int b, int e) {
	// Reverse the subarray using a simple method of swapping elements
	for (int i = 0; i < (e-b)/2; i++) {
		int temp = a[b+i];
		a[b+i] = a[e-i];
		a[e-i] = temp;
	}
}

// Main function
int main() {
	// Initialize a scanner to read input from standard input
	int sc;
	scanf("%d", &sc);
	int *a = (int *) malloc(sc * sizeof(int));

	// Read the number of elements in the array 'a'
	int n = nextInt(&sc);
	// Read 'n' integers from the standard input and store them in the array 'a'
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// Read the number of queries 'q'
	int q = nextInt(&sc);

	// Process each query by reversing the subarray of 'a'
	for (int i = 0; i < q; i++) {
		// Read the starting and ending indices of the subarray to be reversed
		int b = nextInt(&sc);
		int e = nextInt(&sc);

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

	// End of the code
	return 0;
}

