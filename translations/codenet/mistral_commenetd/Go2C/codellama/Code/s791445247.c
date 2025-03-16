
// by syu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner for reading input
struct Scanner in;

int main() {
	// Read the first two integers from the standard input
	int n, k;
	scanf("%d %d", &n, &k);

	// Check if n is divisible by k
	if (n % k == 0) {
		// If it is, print 0
		printf("0\n");
	} else {
		// If not, print 1
		printf("1\n");
	}
}

// Define a new Scanner type
struct Scanner {
	// Initialize a new bufio.Scanner instance
	struct bufio_Scanner *s;
};

// Create a new Scanner instance
struct Scanner *NewScanner(FILE *r, int max) {
	// Initialize a new bufio.Scanner instance
	struct bufio_Scanner *s = bufio_NewScanner(r);
	// Set the split function to split on words instead of whitespace
	s->split = scanWords;
	// Set the buffer size if it's provided
	if (max <= 0) {
		max = 1048576;
	}
	// Set the buffer and return the new Scanner instance
	s->buffer = malloc(max);
	s->max = max;
	return &(struct Scanner){s};
}

// Parse an integer from a string
int Scanner_Int(struct Scanner *s) {
	// Read the next token as a string
	s->s->scan(s->s);
	// Parse the string to an integer and return it
	int i = atoi(s->s->text);
	// Return the integer value
	return i;
}

// Check if a byte is a whitespace character
int isSpace(char b) {
	// Return true if the byte is a space, newline, carriage return, or tab character
	return b == ' ' || b == '\n' || b == '\r' || b == '\t';
}

// Split function for bufio.Scanner to split on words instead of whitespace
int scanWords(char *data, int atEOF) {
	// Initialize the start index
	int start = 0;
	// Find the first non-whitespace character
	for (start = 0; start < strlen(data) && isSpace(data[start]); start++) {
		start++;
	}
	// Iterate through the data and find the next whitespace character or end of data
	for (int i = start; i < strlen(data); i++) {
		// If the current character is a whitespace character, return the token and advance the index
		if (isSpace(data[i])) {
			return i + 1;
		}
	}
	// If we've reached the end of data and there's still data to read, return the remaining data as the token
	if (atEOF && strlen(data) > start) {
		return strlen(data);
	}
	// Return the start index as the token and the length of the token as the advance value
	return start;
}

// Print a line with the given arguments
void Pln(int s, ...) {
	// Print the line with the given arguments
	va_list args;
	va_start(args, s);
	vprintf(s, args);
	va_end(args);
	printf("\n");
}

