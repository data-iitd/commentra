#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
typedef struct {
	FILE *r;
	char *buf;
	int i;
} bufReader;

// bufReader initialization
bufReader reader = {
	stdin,
	NULL,
	0,
};

// readLine reads a line from the input and stores it in the buffer.
void readLine(bufReader *r) {
	if (r->i < strlen(r->buf)) {
		return;
	}
	free(r->buf);
	r->buf = NULL;
	r->i = 0;
	for (;;) {
		char *line = NULL;
		size_t size = 0;
		getline(&line, &size, r->r);
		if (line == NULL) {
			panic("Error reading from standard input.");
		}
		r->buf = line;
		if (strchr(line, '\n') == NULL) {
			break;
		}
	}
}

// next returns the next space-separated word from the buffer.
char *next(bufReader *r) {
	readLine(r);
	char *from = r->buf + r->i;
	for (; r->i < strlen(r->buf); r->i++) {
		if (r->buf[r->i] == ' ') {
			break;
		}
	}
	char *s = malloc(r->i - from + 1);
	strncpy(s, from, r->i - from);
	s[r->i - from] = '\0';
	r->i++;
	return s;
}

// nextLine returns the entire next line from the buffer.
char *nextLine(bufReader *r) {
	readLine(r);
	char *s = malloc(strlen(r->buf) - r->i + 1);
	strncpy(s, r->buf + r->i, strlen(r->buf) - r->i);
	s[strlen(r->buf) - r->i] = '\0';
	r->i = strlen(r->buf);
	return s;
}

// bufio Writer initialization
FILE *writer = stdout;

// next wraps the reader.next() function.
char *next() {
	return next(&reader);
}

// nextInt reads the next token as an integer.
long long nextInt() {
	char *s = next();
	long long i = strtoll(s, NULL, 10);
	free(s);
	return i;
}

// nextLine wraps the reader.nextLine() function.
char *nextLine() {
	return nextLine(&reader);
}

// out prints the arguments to the output with a newline.
void out(char *s, ...) {
	va_list args;
	va_start(args, s);
	vfprintf(writer, s, args);
	va_end(args);
	fprintf(writer, "\n");
}

// max returns the maximum of two integers.
long long max(long long x, long long y) {
	if (x > y) {
		return x;
	}
	return y;
}

// min returns the minimum of two integers.
long long min(long long x, long long y) {
	if (x < y) {
		return x;
	}
	return y;
}

// joinInts joins an array of integers into a string with a separator.
char *joinInts(long long *a, int n, char *sep) {
	char *s = malloc(n * 20 + strlen(sep) * (n - 1));
	s[0] = '\0';
	for (int i = 0; i < n; i++) {
		char *t = malloc(20);
		sprintf(t, "%lld", a[i]);
		strcat(s, t);
		if (i < n - 1) {
			strcat(s, sep);
		}
		free(t);
	}
	return s;
}

// divUp returns the ceiling of the division of x by y.
long long divUp(long long x, long long y) {
	return (x + y - 1) / y;
}

// Solve function
// Reads the number of elements N.
// Reads N pairs of integers T and A.
// Iteratively adjusts t and a to ensure the ratios are maintained.
// Outputs the sum of t and a after all adjustments.
void solve() {
	long long N = nextInt();
	long long *T, *A;
	T = malloc(N * sizeof(long long));
	A = malloc(N * sizeof(long long));
	for (int i = 0; i < N; i++) {
		T[i] = nextInt();
		A[i] = nextInt();
	}
	long long t, a;
	t = T[0];
	a = A[0];
	for (int i = 1; i < N; i++) {
		long long r = max(divUp(t, T[i]), divUp(a, A[i]));
		t = T[i] * r;
		a = A[i] * r;
	}
	out("%lld %lld", t, a);
}

