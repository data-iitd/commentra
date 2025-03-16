
// Importing necessary packages
#include <bits/stdc++.h>

using namespace std;

// Function to read next integer from the standard input
int nextInt(int sc) {
	sc = getchar(); // Scan the next token
	int t = 0;
	while (sc!='' && sc!= '\n') {
		t = t*10 + sc - '0';
		sc = getchar();
	}
	return t;
}

// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
void reva(int b[], int e) {
	// Reverse the subarray using a simple method of swapping elements
	for (int i = 0; i < (e-b+1)/2; i++) {
		int temp = b[b+i];
		b[b+i] = b[e-i];
		b[e-i] = temp;
	}
}

// Main function
int main() {
	// Initialize a scanner to read input from standard input
	int sc = getchar();
	int n = 0;
	while (sc!= '\n') {
		n = n*10 + sc - '0';
		sc = getchar();
	}

	// Allocate memory for the array 'a' of size 'n'
	int a[n];

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
		reva(a+b, e-b+1);
	}

	// Write the reversed array 'a' to the standard output
	for (int i = 0; i < n; i++) {
		// Write each element of the array 'a' to the standard output with a space in between (except for the first element)
		if (i > 0) {
			printf(" ");
		}
		printf("%d", a[i]);
	}

	// Flush the buffer to write the output to the standard output
	printf("\n");

// End of the code

