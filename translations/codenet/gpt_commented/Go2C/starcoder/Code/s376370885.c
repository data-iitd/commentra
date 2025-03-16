

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->buffer = malloc(max);
	s->size = max;
	s->pos = 0;
	return s;
}

void FreeScanner(struct Scanner *s) {
	free(s->buffer);
	free(s);
}

int scanWords(struct Scanner *s, char *data, int atEOF) {
	size_t start = 0;
	// Skip leading whitespace
	while (start < s->size && isspace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (size_t i = start; i < s->size; i++) {
		if (isspace(data[i])) {
			return i + 1; // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && s->size > start) {
		return s->size;
	}
	return start; // Return the current position if no word is found
}

int Int(struct Scanner *s) {
	scanf("%s", s->buffer);
	int i = atoi(s->buffer);
	return i;
}

int main() {
	// Read two integers n and k from the input
	struct Scanner *in = NewScanner(1048576);
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->buffer = malloc(max);
	s->size = max;
	s->pos = 0;
	return s;
}

void FreeScanner(struct Scanner *s) {
	free(s->buffer);
	free(s);
}

int scanWords(struct Scanner *s, char *data, int atEOF) {
	size_t start = 0;
	// Skip leading whitespace
	while (start < s->size && isspace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (size_t i = start; i < s->size; i++) {
		if (isspace(data[i])) {
			return i + 1; // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && s->size > start) {
		return s->size;
	}
	return start; // Return the current position if no word is found
}

int Int(struct Scanner *s) {
	scanf("%s", s->buffer);
	int i = atoi(s->buffer);
	return i;
}

int main() {
	// Read two integers n and k from the input
	struct Scanner *in = NewScanner(1048576);
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->buffer = malloc(max);
	s->size = max;
	s->pos = 0;
	return s;
}

void FreeScanner(struct Scanner *s) {
	free(s->buffer);
	free(s);
}

int scanWords(struct Scanner *s, char *data, int atEOF) {
	size_t start = 0;
	// Skip leading whitespace
	while (start < s->size && isspace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (size_t i = start; i < s->size; i++) {
		if (isspace(data[i])) {
			return i + 1; // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && s->size > start) {
		return s->size;
	}
	return start; // Return the current position if no word is found
}

int Int(struct Scanner *s) {
	scanf("%s", s->buffer);
	int i = atoi(s->buffer);
	return i;
}

int main() {
	// Read two integers n and k from the input
	struct Scanner *in = NewScanner(1048576);
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->buffer = malloc(max);
	s->size = max;
	s->pos = 0;
	return s;
}

void FreeScanner(struct Scanner *s) {
	free(s->buffer);
	free(s);
}

int scanWords(struct Scanner *s, char *data, int atEOF) {
	size_t start = 0;
	// Skip leading whitespace
	while (start < s->size && isspace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (size_t i = start; i < s->size; i++) {
		if (isspace(data[i])) {
			return i + 1; // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && s->size > start) {
		return s->size;
	}
	return start; // Return the current position if no word is found
}

int Int(struct Scanner *s) {
	scanf("%s", s->buffer);
	int i = atoi(s->buffer);
	return i;
}

int main() {
	// Read two integers n and k from the input
	struct Scanner *in = NewScanner(1048576);
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->buffer = malloc(max);
	s->size = max;
	s->pos = 0;
	return s;
}

void FreeScanner(struct Scanner *s) {
	free(s->buffer);
	free(s);
}

int scanWords(struct Scanner *s, char *data, int atEOF) {
	size_t start = 0;
	// Skip leading whitespace
	while (start < s->size && isspace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (size_t i = start; i < s->size; i++) {
		if (isspace(data[i])) {
			return i + 1; // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && s->size > start) {
		return s->size;
	}
	return start; // Return the current position if no word is found
}

int Int(struct Scanner *s) {
	scanf("%s", s->buffer);
	int i = atoi(s->buffer);
	return i;
}

int main() {
	// Read two integers n and k from the input
	struct Scanner *in = NewScanner(1048576);
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->buffer = malloc(max);
	s->size = max;
	s->pos = 0;
	return s;
}

void FreeScanner(struct Scanner *s) {
	free(s->buffer);
	free(s);
}

int scanWords(struct Scanner *s, char *data, int atEOF) {
	size_t start = 0;
	// Skip leading whitespace
	while (start < s->size && isspace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (size_t i = start; i < s->size; i++) {
		if (isspace(data[i])) {
			return i + 1; // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && s->size > start) {
		return s->size;
	}
	return start; // Return the current position if no word is found
}

int Int(struct Scanner *s) {
	scanf("%s", s->buffer);
	int i = atoi(s->buffer);
	return i;
}

int main() {
	// Read two integers n and k from the input
	struct Scanner *in = NewScanner(1048576);
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->buffer = malloc(max);
	s->size = max;
	s->pos = 0;
	return s;
}

void FreeScanner(struct Scanner *s) {
	free(s->buffer);
	free(s);
}

int scanWords(struct Scanner *s, char *data, int atEOF) {
	size_t start = 0;
	// Skip leading whitespace
	while (start < s->size && isspace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (size_t i = start; i < s->size; i++) {
		if (isspace(data[i])) {
			return i + 1; // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if (atEOF && s->size > start) {
		return s->size;
	}
	return start; // Return the current position if no word is found
}

int Int(struct Scanner *s) {
	scanf("%s", s->buffer);
	int i = atoi(s->buffer);
	return i;
}

int main() {
	// Read two integers n and k from the input
	struct Scanner *in = NewScanner(1048576);
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
struct Scanner {
	char *buffer;
	size_t size;
	size_t pos;
};

struct Scanner *NewScanner(int max) {
	struct Scanner *s = malloc(sizeof(struct Scanner));
	s->buffer = malloc(max);
	s->size = max;
	s->pos = 0;
	return s;
}

void FreeScanner(struct Scanner *s) {
	free(s->buffer);
	free(s);
}

int scanWords(struct Scanner *s, char 