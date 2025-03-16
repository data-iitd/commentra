
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a global Scanner instance to read from standard input
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(void) {
	struct Scanner *scanner = malloc(sizeof(struct Scanner));
	scanner->buffer = NULL;
	scanner->size = 0;
	scanner->pos = 0;
	return scanner;
}

void FreeScanner(struct Scanner *scanner) {
	free(scanner->buffer);
	free(scanner);
}

void Scan(struct Scanner *scanner, char *input) {
	scanner->buffer = input;
	scanner->size = strlen(input);
	scanner->pos = 0;
}

int Int(struct Scanner *scanner) {
	int result = 0;
	int sign = 1;
	int i = 0;
	while (scanner->pos < scanner->size && isspace(scanner->buffer[scanner->pos])) {
		scanner->pos++;
	}
	if (scanner->pos == scanner->size) {
		return 0;
	}
	if (scanner->buffer[scanner->pos] == '-') {
		sign = -1;
		scanner->pos++;
	} else if (scanner->buffer[scanner->pos] == '+') {
		scanner->pos++;
	}
	for (i = scanner->pos; i < scanner->size; i++) {
		if (!isdigit(scanner->buffer[i])) {
			break;
		}
	}
	result = atoi(scanner->buffer + scanner->pos);
	scanner->pos = i;
	return result * sign;
}

int main(void) {
	// Read two integers, n and k, from standard input
	struct Scanner *in = NewScanner();
	Scan(in, "100 10");
	int n = Int(in);
	int k = Int(in);
	FreeScanner(in);
	
	// Check if n is divisible by k
	if (n % k == 0) {
		// If n is divisible by k, print 0
		printf("0\n");
	} else {
		// If n is not divisible by k, print 1
		printf("1\n");
	}
	return 0;
}

