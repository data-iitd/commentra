#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for buffer sizes
const int initialBufSize = 1e4; // Initial buffer size for the scanner
const int maxBufSize = 1e8; // Maximum buffer size for the scanner

// Define a struct to hold the scanner
struct scanner {
	char *buf; // Buffer for the scanner
	int bufSize; // Size of the buffer
	int split; // Split function for the scanner
	int pos; // Current position in the buffer
	int line; // Current line number
};

// Define a struct to hold the scanner
struct scanner sc;

// Initialize the scanner with a buffer and set the split function
void init() {
	sc.buf = (char *) malloc(initialBufSize * sizeof(char)); // Create a byte slice for the buffer
	sc.bufSize = maxBufSize; // Set the buffer size for the scanner
	sc.split = 1; // Split the input by words
	sc.pos = 0; // Set the current position in the buffer
	sc.line = 1; // Set the current line number
}

// Function to read the next word from input
char *next() {
	int i = 0; // Initialize a counter
	while (sc.buf[sc.pos] != ' ' && sc.pos < sc.bufSize) { // Loop through each character in the buffer
		sc.pos++; // Increment the position in the buffer
		i++; // Increment the counter
	}
	char *word = (char *) malloc(i * sizeof(char)); // Create a new string to hold the word
	for (int j = 0; j < i; j++) { // Loop through each character in the word
		word[j] = sc.buf[j]; // Copy the character from the buffer to the word
	}
	sc.pos++; // Increment the position in the buffer
	return word; // Return the word
}

// Function to return the minimum of two integers
int min(int x, int y) {
	if (x > y) {
		return y; // Return y if x is greater
	} else {
		return x; // Return x otherwise
	}
}

// Main function where the program execution begins
int main() {
	char *S = next(); // Read the input string

	int l0, l1 = 0; // Initialize counters for '0's and '1's
	// Loop through each character in the input string
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == '0') {
			l0++; // Increment the counter for '0'
		} else {
			l1++; // Increment the counter for '1'
		}
	}
	// Print the result, which is twice the minimum count of '0's or '1's
	printf("%d\n", 2 * min(l0, l1));
	return 0;
}

