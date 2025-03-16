

#include <stdio.h>
#include <stdlib.h>

// Function to read a single string from stdin and return it
char* Scanner() {
	char buf[1024];
	fgets(buf, 1024, stdin);
	buf[strlen(buf) - 1] = '\0';
	return buf;
}

// Function to read an integer from stdin and return it
int intScanner() {
	int n;
	scanf("%d", &n);
	return n;
}

// Function to read a floating point number from stdin and return it
double floatScanner() {
	double n;
	scanf("%lf", &n);
	return n;
}

// Function to convert a string to an integer
int stringToInt(char* s) {
	return atoi(s);
}

// Initialize the modulus value
#define mod 1000000007

// Initialize a buffer to store the unique elements
char buf[1024];

// Function to read input and process it
int main() {
	// Read the number of elements in the array
	int n = intScanner();

	// Initialize an array of size n to store the elements
	int as[n];

	// Read the elements of the array into the as slice
	for (int i = 0; i < n; i++) {
		as[i] = intScanner();
	}

	// Initialize an empty slice xs to store the unique elements
	int xs[n];
	xs[0] = as[0];
	int xs_len = 1;

	// Iterate through the array and add unique elements to the xs slice
	for (int j = 1; j < n; j++) {
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

	return 0;
}
