// by syu
#include <stdio.h>
#include <stdlib.h>

// Initialize a global Scanner instance to read from standard input.
struct Scanner {
	int c;
	int len;
	char *p;
	char *q;
};

struct Scanner *NewScanner(FILE *f, int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->c = fgetc(f);
	s->len = 0;
	s->p = s->q = malloc(max);
	s->q[0] = 0;
	return s;
}

int Int(struct Scanner *s) {
	scanf("%d", &s->len);
	return s->len;
}

void Pln(int n) {
	printf("%d\n", n);
}

int main() {
	// Read two integers, n and k, from the input.
	struct Scanner *in = NewScanner(stdin, 0);
	int n = Int(in);
	int k = Int(in);
	
	// Check if n is divisible by k.
	if (n % k == 0) {
		// If n is divisible by k, print 0.
		Pln(0);
	} else {
		// If n is not divisible by k, print 1.
		Pln(1);
	}
}

// Helper function to check if a byte is a space character.
int isSpace(char c) {
	return c =='' || c == '\n' || c == '\r' || c == '\t';
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

