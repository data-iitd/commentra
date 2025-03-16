
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// by syu

// Initialize a new Scanner to read from standard input
struct Scanner in = {.Scanner = bufio.NewScanner(os.Stdin, 0)};

int main() {
	// Read two integers n and k from input
	int n, k;
	n = in.Int();
	k = in.Int();
	
	// Check if n is divisible by k
	if (n % k == 0) {
		// If divisible, print 0
		printf("0\n");
	} else {
		// If not divisible, print 1
		printf("1\n");
	}
}

// Scanner struct wraps bufio.Scanner for custom functionality
struct Scanner {
	struct bufio.Scanner *Scanner;
};

// NewScanner initializes a new Scanner with a specified buffer size
struct Scanner NewScanner(int r, int max) {
	struct bufio.Scanner s = bufio.NewScanner(r, 0);
	s.Split(scanWords);
	if (max <= 0) {
		max = 1048576;
	}
	s.Buffer([]byte{}, max);
	return &Scanner{s};
}

// Int reads the next token from the input and converts it to an integer
int Scanner.Int(struct Scanner *s) {
	s.Scan();
	int i, e;
	i = strconv.ParseInt(s.Text(), 10, 64);
	if (e != nil) {
		panic(e);
	}
	return int(i);
}

// isSpace checks if a byte is a whitespace character
int isSpace(char b) {
	return b == ' ' || b == '\n' || b == '\r' || b == '\t';
}

// scanWords is a split function for bufio.Scanner that splits input into words
int scanWords(char *data, int atEOF) {
	int start = 0;
	// Skip leading whitespace
	for (start < strlen(data) && isSpace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (int i = start; i < strlen(data); i++) {
		if (isSpace(data[i])) {
			return i + 1, data[start:i], NULL;
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && strlen(data) > start) {
		return strlen(data), data[start:], NULL;
	}
	// Return the current position if no word is found
	return start, NULL, NULL;
}

// Pln is a helper function to print a line with a newline
void Pln(char *s) {
	printf("%s\n", s);
}

