
#include <stdio.h>
#include <stdlib.h>

// Define a constant for the modulo value
#define mod 1000000007

// Define a constant for the input/output buffer size (1MB)
#define ioBufferSize 1 * 1024 * 1024

// Function to read the next string from input
char* next() {
	static char buf[ioBufferSize];
	fgets(buf, ioBufferSize, stdin);
	return buf;
}

// Function to read the next integer from input
int nextInt() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	// Read the values of h and n from input
	int h = nextInt(), n = nextInt();
	int a = 0; // Initialize a variable to accumulate the sum of integers

	// Loop to read n integers and accumulate their sum
	for (int i = 0; i < n; i++) {
		a += nextInt();
	}

	// Check if the accumulated sum is less than h
	if (h > a) {
		// If h is greater than the sum, print "No"
		puts("No");
	} else {
		// Otherwise, print "Yes"
		puts("Yes");
	}
}
