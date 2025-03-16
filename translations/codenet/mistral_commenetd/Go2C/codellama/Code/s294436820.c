
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Constants for large prime numbers used in modular arithmetic.
const int INF = 1000000007;
const int INF2 = 1000000009;
const int INF3 = 998244353;

// Global variable for debug mode.
bool DEBUG = false;

// -----------------------------------------------------------------------------
// IO helper functions

// Returns next token from input. It must be initialized by SetInput() before the first call.
char *nextToken();

// Holds a buffer for output. It must be initialized by SetOutput().
// All IO functions (read*() and [e]print*()) should write to OutputWriter instead of this.
FILE *OutputBuffer;

// Holds an io.Writer. It must be initialized by SetOutput()
FILE *OutputWriter;

// Set IO functions for interactive input/output.
void SetInteractive(FILE *w, FILE *r) {
	SetUnbufferedInput(r);
	OutputBuffer = NULL;
	OutputWriter = w;
}

// Setup OutputBuffer and OutputWriter.
void SetOutput(FILE *w) {
	OutputBuffer = fopen("output.txt", "w");
	OutputWriter = OutputBuffer;
}

// Flushes OutputBuffer
void Flush() {
	if (OutputBuffer != NULL) {
		fflush(OutputBuffer);
	}
}

// Returns true if c is a white space
bool IsSpace(char c) {
	switch (c) {
	case '\t':
	case '\n':
	case '\v':
	case '\f':
	case '\r':
	case ' ':
		return true;
	}
	return false;
}

bool IsNewLine(char c) {
	switch (c) {
	case '\n':
	case '\r':
		return true;
	}
	return false;
}

// Setup nextToken with input buffer.
void SetInput(FILE *r) {
	char *b;
	int i;
	int j;
	int len;
	int err;

	char *rest() {
		for (i = 0; i < len && IsSpace(b[i]); i++);
		if (i == len) {
			return NULL;
		}
		j = i;
		for (i = 0; i < len && !IsSpace(b[i]); i++);
		if (i == j) {
			return NULL;
		}
		return b + j;
	}

	char *initial() {
		b = (char *)malloc(1024 * sizeof(char));
		len = fread(b, sizeof(char), 1024, r);
		nextToken = rest;
		return rest();
	}

	nextToken = initial;

	char *restLn() {
		for (i = 0; i < len && IsNewLine(b[i]); i++);
		if (i == len) {
			return NULL;
		}
		j = i;
		for (i = 0; i < len && !IsNewLine(b[i]); i++);
		if (i == j) {
			return NULL;
		}
		return b + j;
	}

	char *initialLn() {
		b = (char *)malloc(1024 * sizeof(char));
		len = fread(b, sizeof(char), 1024, r);
		nextLine = restLn;
		return restLn();
	}

	nextLine = initialLn;
}

// Setup nextToken without input buffer.
void SetUnbufferedInput(FILE *r) {
	char *b;
	int i;
	int j;
	int len;
	int err;

	char *nextToken() {
		if (i == len) {
			b = (char *)malloc(1024 * sizeof(char));
			len = fread(b, sizeof(char), 1024, r);
			i = 0;
			j = len - 1;
			for (; 0 <= j && IsSpace(b[j]); j--);
			b = (char *)realloc(b, (j + 1) * sizeof(char));
		}
		for (; i < len && IsSpace(b[i]); i++);
		if (i == len) {
			return NULL;
		}
		j = i;
		for (; i < len && !IsSpace(b[i]); i++);
		if (i == j) {
			return NULL;
		}
		return b + j;
	}
}

// -----------------------------------------------------------------------------
// IO functions

// Reads next token and return it as []byte
char *readb() {
	char *b = nextToken();
	if (b == NULL) {
		return NULL;
	}
	return b;
}

// Reads next token and return it as string
char *reads() {
	char *b = readb();
	if (b == NULL) {
		return NULL;
	}
	return b;
}

// Read next line as []byte. Trailing '\n' will not be included.
// See also comments on readb()
char *readbln() {
	char *b = nextLine();
	if (b == NULL) {
		return NULL;
	}
	return b;
}

// Read next line as string
char *readsln() {
	char *b = readbln();
	if (b == NULL) {
		return NULL;
	}
	return b;
}

// Reads next token and return it as int64
int64_t readll() {
	char *b = readb();
	if (b == NULL) {
		return 0;
	}
	return strtoll(b, NULL, 10);
}

// Reads next token and return it as int
int readi() {
	return (int)readll();
}

// Reads next token and return it as float64
double readf() {
	char *b = readb();
	if (b == NULL) {
		return 0;
	}
	return strtod(b, NULL);
}

// Write args to OutputWriter with the format f
int printf(char *f, ...) {
	va_list args;
	va_start(args, f);
	int res = vfprintf(OutputWriter, f, args);
	va_end(args);
	return res;
}

// Write args to OutputWriter without format
int println(char *s) {
	return fprintf(OutputWriter, "%s\n", s);
}

// Write args to stderr with the format f
int eprintf(char *f, ...) {
	va_list args;
	va_start(args, f);
	int res = vfprintf(stderr, f, args);
	va_end(args);
	return res;
}

// Write args to stderr without format
int eprintln(char *s) {
	return fprintf(stderr, "%s\n", s);
}

void debugf(char *f, ...) {
	if (!DEBUG) {
		return;
	}
	va_list args;
	va_start(args, f);
	vfprintf(stderr, f, args);
	va_end(args);
}

void debug(char *s) {
	if (!DEBUG) {
		return;
	}
	fprintf(stderr, "%s\n", s);
}

// -----------------------------------------------------------------------------
// Utilities

// sumSlice returns the sum of elements in a slice.
int sumSlice(int *a, int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i];
	}
	return res;
}

// sumSlicell returns the sum of elements in a slice.
int64_t sumSlicell(int64_t *a, int n) {
	int64_t res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i];
	}
	return res;
}

// -----------------------------------------------------------------------------
// Simple math functions

// min returns the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// minll returns the minimum of two int64.
int64_t minll(int64_t a, int64_t b) {
	if (a < b) {
		return a;
	}
	return b;
}

// minf returns the minimum of two float64.
double minf(double a, double b) {
	if (a < b) {
		return a;
	}
	return b;
}

// max returns the maximum of two integers.
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// maxll returns the maximum of two int64.
int64_t maxll(int64_t a, int64_t b) {
	if (a < b) {
		return b;
	}
	return a;
}

// maxf returns the maximum of two float64.
double maxf(double a, double b) {
	if (a < b) {
		return b;
	}
	return a;
}

// abs returns the absolute value of an integer.
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// absll returns the absolute value of an int64.
int64_t absll(int64_t a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// absf returns the absolute value of a float64.
double absf(double a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// egcd returns the greatest common divisor of a and b, along with x and y such that a*x + b*y = gcd.
int egcd(int a, int b, int *x, int *y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	int d = egcd(b, a % b, y, x);
	*y -= a / b * *x;
	return d;
}

int64_t egcdll(int64_t a, int64_t b, int64_t *x, int64_t *y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	int64_t d = egcdll(b, a % b, y, x);
	*y -= a / b * *x;
	return d;
}

// gcd returns the greatest common divisor of two integers.
int gcd(int a, int b) {
	int x, y;
	int d = egcd(a, b, &x, &y);
	return d;
}

// gcdll returns the greatest common divisor of two int64.
int64_t gcdll(int64_t a, int64_t b) {
	int64_t x, y;
	int64_t d = egcdll(a, b, &x, &y);
	return d;
}

// -----------------------------------------------------------------------------
// Main function

int main() {
	// for non-interactive
	SetInput(stdin);
	SetOutput(stdout);

	// Enable below when interactive. Its ok to leave above intact.
	SetInteractive(stdout, stdin);

	// Read input
	int h = readi();
	int w = readi();
	int a = readi();
	int **m = (int **)malloc(h * sizeof(int *));
	for (int i = 0; i < h; i++) {
		m[i] = (int *)malloc(w * sizeof(int));
		char *s = reads();
		for (int j = 0; j < w; j++) {
			m[i][j] = s[j];
		}
	}

	// Solve the problem
	int answer = solve(h, w, a, m);

	// Print the result
	printf("%d\n", answer);

	return 0;
}

// Function to count the number of black cells in a grid.
int countBlack(int h, int w, int **m) {
	int count = 0;
	debug("new table");
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m[i][j] == Black) {
				count++;
			}
		}
		debug(m[i]);
	}
	debug("result : ", count);
	return count;
}

// Function to solve the problem.
int solve(int h, int w, int a, int **m) {
	int result = 0;
	for (int i = 0; i < (1 << h); i++) {
		for (int k = 0; k < (1 << w); k++) {
			int **tmp = (int **)malloc(h * sizeof(int *));
			for (int j = 0; j < h; j++) {
				tmp[j] = (int *)malloc(w * sizeof(int));
				for (int l = 0; l < w; l++) {
					tmp[j][l] = m[j][l];
				}
			}
			for (int j = 0; j < h; j++) {
				int hPainted = (1 << j & i);
				if (hPainted > 0) {
					debug("painted ", j, 1 << j, i, hPainted);
					for (int l = 0; l < w; l++) {
						tmp[j][l] = 1;
					}
				}
			}
			for (int j = 0; j < w; j++) {
				int wPainted = (1 << j & k);
				if (wPainted > 0) {
					for (int l = 0; l < h; l++) {
						tmp[l][j] = 1;
					}
				}
			}
			debug("i", itoa(i, 2));
			debug("k", itoa(k, 2));
			if (countBlack(h, w, tmp) == a) {
				result++;
			}
		}
	}
	return result;
}

// Constants for black cell representation.
const int Black = 35;

// -----------------------------------------------------------------------------
// Utilities

// itoa converts an integer to a string.
char *itoa(int i, int base) {
	char *s = (char *)malloc(1024 * sizeof(char));
	int j = 0;
	if (i == 0) {
		s[j++] = '0';
	} else {
		if (i < 0) {
			s[j++] = '-';
			i = -i;
		}
		while (i > 0) {
			s[j++] = "0123456789abcdefghijklmnopqrstuvwxyz"[i % base];
			i /= base;
		}
	}
	s[j] = '\0';
	return strrev(s);
}

// strrev reverses a string.
char *strrev(char *s) {
	int i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	return s;
}

// -----------------------------------------------------------------------------
// Main function

int main() {
	// for non-interactive
	SetInput(stdin);
	SetOutput(stdout);

	// Enable below when interactive. Its ok to leave above intact.
	SetInteractive(stdout, stdin);

	// Read input
	int h = readi();
	int w = readi();
	int a = readi();
	int **m = (int **)malloc(h * size