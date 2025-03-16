
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner for reading input
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

// Create a new Scanner instance
struct Scanner *NewScanner(FILE *r, int max) {
	// Allocate a new Scanner instance
	struct Scanner *s = malloc(sizeof(struct Scanner));
	// Set the buffer size if it's provided
	if (max <= 0) {
		max = 1048576;
	}
	// Allocate a buffer and set the size
	s->buffer = malloc(max);
	s->size = max;
	// Read the input into the buffer
	fread(s->buffer, 1, max, r);
	// Set the position to the start of the buffer
	s->pos = 0;
	// Return the new Scanner instance
	return s;
}

// Parse an integer from a string
int Int(struct Scanner *s) {
	// Read the next token as a string
	scanf("%s", s->buffer);
	// Parse the string to an integer and return it
	int i;
	sscanf(s->buffer, "%d", &i);
	return i;
}

// Check if a byte is a whitespace character
int isSpace(char b) {
	// Return true if the byte is a space, newline, carriage return, or tab character
	return b =='' || b == '\n' || b == '\r' || b == '\t';
}

// Split function for bufio.Scanner to split on words instead of whitespace
void scanWords(char *data, size_t atEOF, struct Scanner *s) {
	// Initialize the start index
	size_t start = 0;
	// Find the first non-whitespace character
	for (start < strlen(data) && isSpace(data[start])) {
		start++;
	}
	// Iterate through the data and find the next whitespace character or end of data
	for (size_t i = start; i < strlen(data); i++) {
		// If the current character is a whitespace character, return the token and advance the index
		if (isSpace(data[i])) {
			return i + 1, data[start:i], NULL;
		}
	}
	// If we've reached the end of data and there's still data to read, return the remaining data as the token
	if (atEOF && strlen(data) > start) {
		return strlen(data), data[start:], NULL;
	}
	// Return the start index as the token and the length of the token as the advance value
	return start, NULL, NULL;
}

// Print a line with the given arguments
void Pln(char *s[]) {
	// Print the line with the given arguments
	printf("%s\n", s);
}

// Main function
int main(int argc, char *argv[]) {
	// Read the first two integers from the standard input
	struct Scanner *in = NewScanner(stdin, 0);
	int n = Int(in);
	int k = Int(in);

	// Check if n is divisible by k
	if (n % k == 0) {
		// If it is, print 0
		Pln("0");
	} else {
		// If not, print 1
		Pln("1");
	}
	// Free the Scanner instance
	free(in);
	// Return 0
	return 0;
}

