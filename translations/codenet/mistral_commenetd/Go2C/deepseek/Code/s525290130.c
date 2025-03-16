#include <stdio.h>
#include <stdlib.h>

// Function to read next integer from the standard input
int nextInt() {
	int t;
	scanf("%d", &t);
	return t;
}

// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
void reva(int* b, int len) {
	// Reverse the subarray using a simple method of swapping elements
	for (int i = 0; i < len / 2; i++) {
		int temp = b[i];
		b[i] = b[len - 1 - i];
		b[len - 1 - i] = temp;
	}
}

// Main function
int main() {
	// Read the number of elements in the array 'a'
	int n = nextInt();
	// Allocate memory for the array 'a' of size 'n'
	int* a = (int*)malloc(n * sizeof(int));

	// Read 'n' integers from the standard input and store them in the array 'a'
	for (int i = 0; i < n; i++) {
		a[i] = nextInt();
	}

	// Read the number of queries 'q'
	int q = nextInt();

	// Process each query by reversing the subarray of 'a'
	for (int i = 0; i < q; i++) {
		// Read the starting and ending indices of the subarray to be reversed
		int b = nextInt();
		int e = nextInt();

		// Reverse the subarray 'a[b:e]'
		reva(a + b, e - b);
	}

	// Write the reversed array 'a' to the standard output
	for (int i = 0; i < n; i++) {
		// Write each element of the array 'a' to the standard output with a space in between (except for the first element)
		if (i > 0) {
			printf(" ");
		}
		printf("%d", a[i]);
	}
	printf("\n");

	// Free the allocated memory
	free(a);

	return 0;
}
