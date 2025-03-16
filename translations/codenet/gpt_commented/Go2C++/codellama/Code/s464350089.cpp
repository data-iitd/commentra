
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

// Define a constant for the modulo value
const int mod = 1000000007;

// Define a constant for the input/output buffer size (1MB)
const int ioBufferSize = 1 * 1024 * 1024;

// Define a buffered scanner for reading input
char inputBuffer[ioBufferSize];
char* inputBufferPtr = inputBuffer;
char* inputBufferEnd = inputBuffer + ioBufferSize;

// Function to read the next string from input
char* next() {
	// If the input buffer pointer is at the end of the buffer, read a new chunk of input
	if (inputBufferPtr == inputBufferEnd) {
		// Read a new chunk of input
		cin.read(inputBuffer, ioBufferSize);
		// Reset the input buffer pointer to the beginning of the buffer
		inputBufferPtr = inputBuffer;
	}
	// Return the next character from the input buffer
	return inputBufferPtr++;
}

// Function to read the next integer from input
int nextInt() {
	// Read the next character from input
	char c = next();
	// If the character is a space or newline, read the next character
	while (c == ' ' || c == '\n') {
		c = next();
	}
	// If the character is a digit, read the integer
	if (c >= '0' && c <= '9') {
		// Read the integer
		int i = 0;
		while (c >= '0' && c <= '9') {
			i = (i * 10) + (c - '0');
			c = next();
		}
		// Return the integer
		return i;
	}
	// If the character is not a digit, return 0
	return 0;
}

int main() {
	// Read the values of h and n from input
	int h = nextInt();
	int n = nextInt();
	int a = 0; // Initialize a variable to accumulate the sum of integers

	// Loop to read n integers and accumulate their sum
	for (int i = 0; i < n; i++) {
		a += nextInt();
	}

	// Check if the accumulated sum is less than h
	if (h > a) {
		// If h is greater than the sum, print "No"
		cout << "No" << endl;
	} else {
		// Otherwise, print "Yes"
		cout << "Yes" << endl;
	}

	return 0;
}

