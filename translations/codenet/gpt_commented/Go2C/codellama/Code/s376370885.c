
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (os.Stdin)
struct Scanner in = {.Scanner = bufio.NewScanner(os.Stdin, 0)};

int main() {
	// Read two integers n and k from the input
	int n, k;
	n = in.Int();
	k = in.Int();
	
	// Check if n is divisible by k
	if (n % k == 0) {
		// If n is divisible by k, print 0
		printf("0\n");
	} else {
		// If n is not divisible by k, print 1
		printf("1\n");
	}
}

// Scanner struct wraps bufio.Scanner for custom input handling
struct Scanner {
	struct bufio.Scanner *Scanner;
};

// NewScanner initializes a new Scanner with a specified buffer size
struct Scanner NewScanner(int r, int max) {
	struct bufio.Scanner s = bufio.NewScanner(r, 0); // Create a new Scanner
	s.Split(scanWords); // Set the split function to scan words
	if (max <= 0) {
		max = 1048576; // Default buffer size if max is not specified
	}
	s.Buffer([]byte{}, max); // Set the buffer size for the scanner
	return &Scanner{s}; // Return the new Scanner instance
}

// Int reads the next token from the input and converts it to an integer
int Scanner.Int(struct Scanner *s) {
	s->Scan(); // Scan the next token
	int i, e = strconv.ParseInt(s->Text(), 10, 64); // Parse the token as an integer
	if (e != NULL) {
		panic(e); // Panic if there is an error during parsing
	}
	return int(i); // Return the parsed integer
}

// isSpace checks if a byte is a whitespace character
int isSpace(char b) {
	return b == ' ' || b == '\n' || b == '\r' || b == '\t';
}

// scanWords is a custom split function for the Scanner to tokenize input
int scanWords(char *data, int atEOF) {
	int start = 0;
	// Skip leading whitespace
	for (start < strlen(data) && isSpace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (int i = start; i < strlen(data); i++) {
		if (isSpace(data[i])) {
			return i + 1, data[start:i], NULL; // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && strlen(data) > start) {
		return strlen(data), data[start:], NULL;
	}
	return start, NULL, NULL; // Return the current position if no word is found
}

// Pln is a convenience function to print a line to standard output
void Pln(char *s) {
	printf("%s\n", s); // Print the provided arguments
}

