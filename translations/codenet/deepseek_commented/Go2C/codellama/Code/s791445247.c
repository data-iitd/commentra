// by syu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a global Scanner instance to read from standard input.
struct Scanner in = {stdin, 0};

int main() {
	// Read two integers, n and k, from the input.
	int n, k;
	scanf("%d %d", &n, &k);
	
	// Check if n is divisible by k.
	if (n % k == 0) {
		// If n is divisible by k, print 0.
		printf("0\n");
	} else {
		// If n is not divisible by k, print 1.
		printf("1\n");
	}
	
	return 0;
}

// Define a custom Scanner type to read input efficiently.
struct Scanner {
	FILE *fp;
	int max;
};

// Create a new Scanner instance with the given reader and buffer size.
struct Scanner NewScanner(FILE *fp, int max) {
	struct Scanner s = {fp, max};
	return s;
}

// Read and return an integer from the input.
int Scanner_Int(struct Scanner *s) {
	int i;
	char *e;
	fscanf(s->fp, "%d", &i);
	return i;
}

// Helper function to check if a byte is a space character.
int isSpace(char b) {
	return b == ' ' || b == '\n' || b == '\r' || b == '\t';
}

// Custom split function for bufio.Scanner to split by words.
int scanWords(char *data, int atEOF) {
	int start = 0;
	while (start < strlen(data) && isSpace(data[start])) {
		start++;
	}
	for (int i = start; i < strlen(data); i++) {
		if (isSpace(data[i])) {
			return i + 1;
		}
	}
	if (atEOF && strlen(data) > start) {
		return strlen(data);
	}
	return start;
}

// Helper function to print a line of output.
void Pln(int n, ...) {
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", va_arg(args, int));
	}
	printf("\n");
	va_end(args);
}

