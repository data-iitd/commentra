
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

// Constants for large prime numbers used in modular arithmetic.
#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

// Global variable for debug mode.
bool DEBUG = false;

// -----------------------------------------------------------------------------
// IO helper functions

// Returns next token from input. It must be initialized by SetInput() before the first call.
char* nextToken;
char* nextLine;

// Holds a buffer for output. It must be initialized by SetOutput().
// All IO functions (read*() and [e]print*()) should write to OutputWriter instead of this.
FILE* OutputBuffer;

// Holds an io.Writer. It must be initialized by SetOutput()
FILE* OutputWriter;

// Set IO functions for interactive input/output.
void SetInteractive(FILE* w, FILE* r) {
	SetUnbufferedInput(r);
	OutputBuffer = NULL;
	OutputWriter = w;
}

// Setup OutputBuffer and OutputWriter.
void SetOutput(FILE* w) {
	OutputBuffer = NULL;
	OutputWriter = w;
}

// Flushes OutputBuffer
void Flush() {
	if (OutputBuffer!= NULL) {
		fflush(OutputBuffer);
	}
}

// Returns true if c is a white space
bool IsSpace(char c) {
	switch (c) {
	case '\t', '\n', '\v', '\f', '\r','':
		return true;
	}
	return false;
}

bool IsNewLine(char c) {
	switch (c) {
	case '\n', '\r':
		return true;
	}
	return false;
}

// Setup nextToken with input buffer.
void SetInput(FILE* r) {
	char* buf = malloc(1024 * 1024);
	char* b;
	size_t len;
	ssize_t read;

	size_t i = 0;
	bool rest = true;
	rest = true;
	b = buf;
	len = 1024 * 1024;
	read = getline(&b, &len, r);
	if (read == -1) {
		free(buf);
		nextToken = NULL;
		return;
	}
	b[read - 1] = 0;
	nextToken = b;
	rest = false;
	free(buf);
}

// Setup nextToken without input buffer.
void SetUnbufferedInput(FILE* r) {
	char* buf = malloc(1024 * 1024);
	char* b;
	size_t len;
	ssize_t read;

	size_t i = 0;
	bool rest = true;
	rest = true;
	b = buf;
	len = 1024 * 1024;
	read = getline(&b, &len, r);
	if (read == -1) {
		free(buf);
		nextToken = NULL;
		return;
	}
	b[read - 1] = 0;
	nextToken = b;
	rest = false;
	free(buf);
}

// -----------------------------------------------------------------------------
// IO functions

// Reads next token and return it as []byte
char* readb() {
	char* b = nextToken;
	if (b == NULL) {
		return NULL;
	}
	nextToken = NULL;
	return b;
}

// Reads next token and return it as string
char* reads() {
	char* b = readb();
	if (b == NULL) {
		return NULL;
	}
	return b;
}

// Read next line as []byte. Trailing '\n' will not be included.
// See also comments on readb()
char* readbln() {
	char* b = nextLine;
	if (b == NULL) {
		return NULL;
	}
	nextLine = NULL;
	return b;
}

// Read next line as string
char* readsln() {
	char* b = readbln();
	if (b == NULL) {
		return NULL;
	}
	return b;
}

// Reads next token and return it as int64
int64_t readll() {
	char* b = reads();
	if (b == NULL) {
		return 0;
	}
	int64_t i = 0;
	int64_t sign = 1;
	if (b[0] == '-') {
		sign = -1;
		b++;
	}
	for (int j = 0; j < strlen(b); j++) {
		i = i * 10 + (b[j] - '0');
	}
	return i * sign;
}

// Reads next token and return it as int
int readi() {
	return (int) readll();
}

// Reads next token and return it as float64
double readf() {
	char* b = reads();
	if (b == NULL) {
		return 0;
	}
	double f = 0;
	double sign = 1;
	if (b[0] == '-') {
		sign = -1;
		b++;
	}
	for (int j = 0; j < strlen(b); j++) {
		f = f * 10 + (b[j] - '0');
	}
	return f * sign;
}

// Write args to OutputWriter with the format f
int printf(const char* f,...) {
	va_list args;
	va_start(args, f);
	int result = vfprintf(OutputWriter, f, args);
	va_end(args);
	return result;
}

// Write args to OutputWriter without format
int println(...) {
	va_list args;
	va_start(args, f);
	int result = vfprintf(OutputWriter, f, args);
	va_end(args);
	return result;
}

// Write args to stderr with the format f
int eprintf(const char* f,...) {
	va_list args;
	va_start(args, f);
	int result = vfprintf(stderr, f, args);
	va_end(args);
	return result;
}

// Write args to stderr without format
int eprintln(...) {
	va_list args;
	va_start(args, f);
	int result = vfprintf(stderr, f, args);
	va_end(args);
	return result;
}

void debugf(const char* f,...) {
	if (!DEBUG) {
		return;
	}
	va_list args;
	va_start(args, f);
	vfprintf(stderr, f, args);
	va_end(args);
}

void debug(...) {
	if (!DEBUG) {
		return;
	}
	va_list args;
	va_start(args, f);
	vfprintf(stderr, f, args);
	va_end(args);
}

// -----------------------------------------------------------------------------
// Utilities

int sumSlice(int* a, int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i];
	}
	return res;
}

int64_t sumSlicell(int64_t* a, int n) {
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
int egcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	int d = egcd(b, a % b);
	return d;
}

int64_t egcdll(int64_t a, int64_t b) {
	if (b == 0) {
		return a;
	}
	int64_t d = egcdll(b, a % b);
	return d;
}

// gcd returns the greatest common divisor of two integers.
int gcd(int a, int b) {
	int d = egcd(a, b);
	return d;
}

// gcdll returns the greatest common divisor of two int64.
int64_t gcdll(int64_t a, int64_t b) {
	int64_t d = egcdll(a, b);
	return d;
}

// -----------------------------------------------------------------------------
// Main function

int main() {
	// for non-interactive
	SetInput(stdin);
	SetOutput(stdout);

	// Enable below when interactive. Its ok to leave above intact.
	// SetInteractive(stdout, stdin);

	// Read input
	int h = readi();
	int w = readi();
	int a = readi();
	int** m = malloc(sizeof(int*) * h);
	for (int i = 0; i < h; i++) {
		m[i] = malloc(sizeof(int) * w);
		char* s = reads();
		for (int j = 0; j < w; j++) {
			m[i][j] = (int) s[j];
		}
	}

	// Solve the problem
	int answer = solve(h, w, a, m);

	// Print the result
	printf("%d\n", answer);
}

// Function to count the number of black cells in a grid.
int countBlack(int h, int w, int** m) {
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
int solve(int h, int w, int a, int** m) {
	int result = 0;
	for (int i = 0; i < 1 << h; i++) {
		for (int k = 0; k < 1 << w; k++) {
			int** tmp = malloc(sizeof(int*) * h);
			for (int j = 0; j < h; j++) {
				tmp[j] = malloc(sizeof(int) * w);
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
			debug("i", i);
			debug("k", k);
			if (countBlack(h, w, tmp) == a) {
				result++;
			}
		}
	}
	return result;
}

// Constants for black cell representation.
const int Black = 35;

