

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

// -----------------------------------------------------------------------------

// IO helper functions

// nextToken and nextLine are function variables that will be initialized 
// by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
static char *nextToken = NULL;
static char *nextLine = NULL;

// OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
static FILE *OutputBuffer = NULL;

// OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
static FILE *OutputWriter = NULL;

// SetInteractive configures the IO functions for interactive input/output.
void SetInteractive(FILE *w, FILE *r) {
	SetUnbufferedInput(r); // Set unbuffered input for reading
	OutputBuffer = NULL;     // No output buffer for interactive mode
	OutputWriter = w;       // Set the output writer
}

// Setup OutputBuffer and OutputWriter for buffered output.
void SetOutput(FILE *w) {
	OutputBuffer = w; // Initialize the output buffer
	OutputWriter = w; // Set the output writer to the buffer
}

// Flushes OutputBuffer to ensure all buffered data is written out.
void Flush() {
	if (OutputBuffer!= NULL) {
		fflush(OutputBuffer); // Flush the buffer if it is initialized
	}
}

// IsSpace checks if a byte is a whitespace character.
bool IsSpace(char c) {
	switch (c) {
	case '\t', '\n', '\v', '\f', '\r','':
		return true;
	}
	return false;
}

// IsNewLine checks if a byte is a newline character.
bool IsNewLine(char c) {
	switch (c) {
	case '\n', '\r':
		return true;
	}
	return false;
}

// SetInput initializes the nextToken function with an input buffer.
void SetInput(FILE *r) {
	char *buf = malloc(BUFSIZ); // Create a new buffer
	char *p = buf;                // Pointer into the buffer
	size_t n = 0;                 // Number of bytes read
	ssize_t rc = 0;               // Return code from fread
	// Function to read the next token from the input
	char *rest() {
		while (IsSpace(*p)) {
			p++; // Skip whitespace
		}
		if (*p == '\0') {
			return NULL; // Return NULL if end of buffer is reached
		}
		char *q = p;
		while (!IsSpace(*p)) {
			p++; // Read until whitespace is found
		}
		*p = '\0'; // Terminate token
		char *r = q;
		p++; // Move to next token
		return r; // Return the token
	}
	// Function to initialize reading from the input
	char *initial() {
		rc = fread(buf, 1, BUFSIZ, r); // Read input to buffer
		if (rc < 0) {
			return NULL; // Return NULL if an error occurs
		}
		n = rc;
		nextToken = rest; // Set nextToken to the rest function
		return rest();    // Read the first token
	}
	nextToken = initial; // Initialize nextToken

	// Function to read the next line from the input
	char *restLn() {
		while (IsNewLine(*p)) {
			p++; // Skip new line characters
		}
		if (*p == '\0') {
			return NULL; // Return NULL if end of buffer is reached
		}
		char *q = p;
		while (!IsNewLine(*p)) {
			p++; // Read until new line is found
		}
		*p = '\0'; // Terminate line
		char *r = q;
		p++; // Move to next line
		return r; // Return the line
	}

	// Function to initialize reading lines from the input
	char *initialLn() {
		rc = fread(buf, 1, BUFSIZ, r); // Read input to buffer
		if (rc < 0) {
			return NULL; // Return NULL if an error occurs
		}
		n = rc;
		nextLine = restLn; // Set nextLine to the restLn function
		return restLn();    // Read the first line
	}
	nextLine = initialLn; // Initialize nextLine
}

// SetUnbufferedInput configures the nextToken function for unbuffered input.
void SetUnbufferedInput(FILE *r) {
	char *buf = malloc(BUFSIZ); // Create a new buffer
	char *p = buf;                // Pointer into the buffer
	size_t n = 0;                 // Number of bytes read
	ssize_t rc = 0;               // Return code from fread
	// Function to read the next token from the input
	char *rest() {
		while (IsSpace(*p)) {
			p++; // Skip whitespace
		}
		if (*p == '\0') {
			return NULL; // Return NULL if end of buffer is reached
		}
		char *q = p;
		while (!IsSpace(*p)) {
			p++; // Read until whitespace is found
		}
		*p = '\0'; // Terminate token
		char *r = q;
		p++; // Move to next token
		return r; // Return the token
	}
	nextToken = rest; // Initialize nextToken

	// Function to read the next line from the input
	char *restLn() {
		while (IsNewLine(*p)) {
			p++; // Skip new line characters
		}
		if (*p == '\0') {
			return NULL; // Return NULL if end of buffer is reached
		}
		char *q = p;
		while (!IsNewLine(*p)) {
			p++; // Read until new line is found
		}
		*p = '\0'; // Terminate line
		char *r = q;
		p++; // Move to next line
		return r; // Return the line
	}

	// Function to initialize reading lines from the input
	char *initialLn() {
		rc = fread(buf, 1, BUFSIZ, r); // Read input to buffer
		if (rc < 0) {
			return NULL; // Return NULL if an error occurs
		}
		n = rc;
		nextLine = restLn; // Set nextLine to the restLn function
		return restLn();    // Read the first line
	}
	nextLine = initialLn; // Initialize nextLine
}

// -----------------------------------------------------------------------------

// IO functions

// readb reads the next token and returns it as a byte slice.
char *readb() {
	char *b = nextToken(); // Read the next token
	if (b == NULL) {
		panic("unexpected end of input"); // Panic if an error occurs
	}
	return b; // Return the token
}

// reads reads the next token and returns it as a string.
char *reads() {
	return strdup(readb()); // Return a copy of the token
}

// readbln reads the next line as a byte slice, excluding the trailing newline.
char *readbln() {
	char *b = nextLine(); // Read the next line
	if (b == NULL) {
		panic("unexpected end of input"); // Panic if an error occurs
	}
	return b; // Return the line
}

// readsln reads the next line and returns it as a string.
char *readsln() {
	return strdup(readbln()); // Return a copy of the line
}

// readll reads the next token and returns it as an int64.
int64_t readll() {
	char *b = reads(); // Read the next token
	int64_t i = strtoll(b, NULL, 10); // Parse the token as an int64
	free(b); // Free the token
	return i; // Return the parsed int64
}

// readi reads the next token and returns it as an int.
int readi() {
	return (int) readll(); // Convert int64 to int
}

// readf reads the next token and returns it as a float64.
double readf() {
	char *b = reads(); // Read the next token
	double f = strtod(b, NULL); // Parse the token as a float64
	free(b); // Free the token
	return f; // Return the parsed float64
}

// printf writes formatted output to OutputWriter.
int printf(const char *f,...) {
	va_list args;
	va_start(args, f);
	int rc = vfprintf(OutputWriter, f, args);
	va_end(args);
	return rc;
}

// println writes output to OutputWriter without formatting.
int println(const char *s) {
	return fprintf(OutputWriter, "%s\n", s);
}

// eprintf writes formatted output to stderr.
int eprintf(const char *f,...) {
	va_list args;
	va_start(args, f);
	int rc = vfprintf(stderr, f, args);
	va_end(args);
	return rc;
}

// eprintln writes output to stderr without formatting.
int eprintln(const char *s) {
	return fprintf(stderr, "%s\n", s);
}

// debugf writes formatted debug output to stderr if DEBUG is enabled.
void debugf(const char *f,...) {
	if (!DEBUG) {
		return; // Do nothing if DEBUG is not enabled
	}
	va_list args;
	va_start(args, f);
	vfprintf(stderr, f, args);
	va_end(args);
}

// debug writes debug output to stderr if DEBUG is enabled.
void debug(const char *s) {
	if (!DEBUG) {
		return; // Do nothing if DEBUG is not enabled
	}
	fprintf(stderr, "%s\n", s);
}

// -----------------------------------------------------------------------------

// Utilities

// sumSlice calculates the sum of a slice of integers.
int sumSlice(int *a, int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i]; // Accumulate the sum
	}
	return res; // Return the total sum
}

// sumSlicell calculates the sum of a slice of int64.
int64_t sumSlicell(int64_t *a, int n) {
	int64_t res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i]; // Accumulate the sum
	}
	return res; // Return the total sum
}

// readInts reads N integers from input and returns the count and the slice.
int readInts(int N, int *a) {
	if (N == 0) {
		N = readi(); // Read N if it is zero
	}
	for (int i = 0; i < N; i++) {
		a[i] = readi(); // Read each integer
	}
	return N; // Return the count
}

// readIntsll reads N int64 values from input and returns the count and the slice.
int readIntsll(int N, int64_t *a) {
	if (N == 0) {
		N = readi(); // Read N if it is zero
	}
	for (int i = 0; i < N; i++) {
		a[i] = readll(); // Read each int64 value
	}
	return N; // Return the count
}

// -----------------------------------------------------------------------------

// Simple math functions

#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

// min returns the smaller of two integers.
int min(int a, int b) {
	if (a < b) {
		return a; // Return a if it is smaller
	}
	return b; // Otherwise return b
}

// minll returns the smaller of two int64 values.
int64_t minll(int64_t a, int64_t b) {
	if (a < b) {
		return a; // Return a if it is smaller
	}
	return b; // Otherwise return b
}

// minf returns the smaller of two float64 values.
double minf(double a, double b) {
	if (a < b) {
		return a; // Return a if it is smaller
	}
	return b; // Otherwise return b
}

// max returns the larger of two integers.
int max(int a, int b) {
	if (a < b) {
		return b; // Return b if it is larger
	}
	return a; // Otherwise return a
}

// maxll returns the larger of two int64 values.
int64_t maxll(int64_t a, int64_t b) {
	if (a < b) {
		return b; // Return b if it is larger
	}
	return a; // Otherwise return a
}

// maxf returns the larger of two float64 values.
double maxf(double a, double b) {
	if (a < b) {
		return b; // Return b if it is larger
	}
	return a; // Otherwise return a
}

// abs returns the