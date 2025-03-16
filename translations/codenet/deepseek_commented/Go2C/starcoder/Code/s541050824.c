#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
typedef struct {
	char *buf;
	size_t len;
	size_t pos;
} bufReader;

// bufReader initialization
bufReader reader;

// readLine reads a line from the input and stores it in the buffer.
void readLine() {
	if (reader.pos < reader.len) {
		return;
	}
	reader.buf = realloc(reader.buf, 0);
	reader.pos = 0;
	reader.len = 0;
	for (;;) {
		char *line = NULL;
		size_t len = 0;
		if (getline(&line, &len, stdin) == -1) {
			free(line);
			return;
		}
		reader.buf = realloc(reader.buf, reader.len + len + 1);
		assert(reader.buf!= NULL);
		memcpy(reader.buf + reader.len, line, len);
		reader.len += len;
		free(line);
		if (reader.buf[reader.len - 1] == '\n') {
			reader.buf[reader.len - 1] = '\0';
			return;
		}
	}
}

// next returns the next space-separated word from the buffer.
char *next() {
	readLine();
	char *s = reader.buf + reader.pos;
	while (reader.pos < reader.len && reader.buf[reader.pos]!='') {
		reader.pos++;
	}
	if (reader.pos == reader.len) {
		return NULL;
	}
	reader.buf[reader.pos] = '\0';
	reader.pos++;
	return s;
}

// nextInt reads the next token as an integer.
int64_t nextInt() {
	char *s = next();
	if (s == NULL) {
		return -1;
	}
	int64_t i = strtoll(s, NULL, 10);
	free(s);
	return i;
}

// nextLine wraps the reader.nextLine() function.
char *nextLine() {
	readLine();
	char *s = reader.buf + reader.pos;
	reader.pos = reader.len;
	return s;
}

// out prints the arguments to the output with a newline.
void out(int64_t a, int64_t b) {
	printf("%lld %lld\n", a, b);
}

// max returns the maximum of two integers.
int64_t max(int64_t x, int64_t y) {
	if (x > y) {
		return x;
	}
	return y;
}

// min returns the minimum of two integers.
int64_t min(int64_t x, int64_t y) {
	if (x < y) {
		return x;
	}
	return y;
}

// joinInts joins an array of integers into a string with a separator.
char *joinInts(int64_t *a, size_t n, char *sep) {
	char *b = malloc(n * 20);
	assert(b!= NULL);
	size_t i;
	for (i = 0; i < n; i++) {
		if (i > 0) {
			strcat(b, sep);
		}
		char *s = malloc(20);
		assert(s!= NULL);
		sprintf(s, "%lld", a[i]);
		strcat(b, s);
		free(s);
	}
	return b;
}

// divUp returns the ceiling of the division of x by y.
int64_t divUp(int64_t x, int64_t y) {
	return (x + y - 1) / y;
}

// Main function
int main() {
	solve();
}

// Solve function
// Reads the number of elements N.
// Reads N pairs of integers T and A.
// Iteratively adjusts t and a to ensure the ratios are maintained.
// Outputs the sum of t and a after all adjustments.
void solve() {
	int64_t N = nextInt();
	int64_t *T = malloc(N * sizeof(int64_t));
	assert(T!= NULL);
	int64_t *A = malloc(N * sizeof(int64_t));
	assert(A!= NULL);
	size_t i;
	for (i = 0; i < N; i++) {
		T[i] = nextInt();
		A[i] = nextInt();
	}
	int64_t t = T[0], a = A[0];
	for (i = 1; i < N; i++) {
		int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
		t = T[i] * r;
		a = A[i] * r;
	}
	out(t + a, 0);
}

