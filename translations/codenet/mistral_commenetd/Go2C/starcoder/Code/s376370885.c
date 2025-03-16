// by syu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom scanner type that wraps bufio.Scanner
typedef struct {
	FILE *f; // File pointer
	char *b; // Buffer
	int n;   // Buffer size
	int i;   // Current index
	int j;   // Last index
} Scanner;

// Initialize a new Scanner instance with the given file pointer and maximum buffer size
Scanner *NewScanner(FILE *f, int n) {
	Scanner *s = malloc(sizeof(Scanner)); // Allocate memory for the Scanner instance
	s->f = f; // Set the file pointer
	s->b = malloc(n); // Allocate memory for the buffer
	s->n = n; // Set the buffer size
	s->i = 0; // Set the current index to 0
	s->j = 0; // Set the last index to 0
	return s; // Return the Scanner instance
}

// Parse an integer from the current scanner data
int Int(Scanner *s) {
	fscanf(s->f, "%d", &s->i); // Parse the next token from the input
	return s->i; // Return the parsed integer
}

// Check if a byte is a whitespace character
int isSpace(char c) {
	return c =='' || c == '\n' || c == '\r' || c == '\t';
}

// Split input data into tokens using scanWords function
void scanWords(Scanner *s, char *data, int atEOF) {
	int start = 0; // Initialize start index of the token
	for (start = 0; start < s->j && isSpace(data[start]); start++) {
		// Increment start index while reading whitespace characters
	}
	for (int i = start; i < s->j; i++) {
		if (isSpace(data[i])) {
			s->i = atoi(data + start); // Parse the token as an integer
			return; // Return if a whitespace character is found
		}
	}
	if (atEOF && s->j > start) {
		// If we've reached the end of the input and there are still characters left in the buffer
		s->i = atoi(data + start); // Parse the remaining characters as an integer
	}
}

// Print a line to the console with the given arguments
void Pln(char *s,...) {
	va_list args;
	va_start(args, s);
	vprintf(s, args);
	va_end(args);
	printf("\n");
}

// Entry point of the program
int main() {
	Scanner *in = NewScanner(stdin, 1048576); // Read two integers n and k from standard input
	int n = Int(in);
	int k = Int(in);
	if (n % k == 0) {
		// If n is divisible by k, print 0 to the console
		Pln("0");
	} else {
		// If n is not divisible by k, print 1 to the console
		Pln("1");
	}
	return 0;
}

