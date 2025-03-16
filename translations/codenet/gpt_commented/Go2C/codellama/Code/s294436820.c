
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0 // Define DEBUG as 0

// Simple math functions

const int INF = 1000000007; // Define large prime constants for calculations
const int INF2 = 1000000009;
const int INF3 = 998244353;

// min returns the smaller of two integers.
int min(int a, int b) {
	if (a < b) {
		return a; // Return a if it is smaller
	}
	return b; // Otherwise return b
}

// minll returns the smaller of two int64 values.
long long minll(long long a, long long b) {
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
long long maxll(long long a, long long b) {
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

// abs returns the absolute value of an integer.
int abs(int a) {
	if (a < 0) {
		return -a; // Return negative if a is less than zero
	}
	return a; // Otherwise return a
}

// absll returns the absolute value of an int64.
long long absll(long long a) {
	if (a < 0) {
		return -a; // Return negative if a is less than zero
	}
	return a; // Otherwise return a
}

// absf returns the absolute value of a float64.
double absf(double a) {
	if (a < 0) {
		return -a; // Return negative if a is less than zero
	}
	return a; // Otherwise return a
}

// egcd computes the extended GCD of a and b, returning d, x, y.
void egcd(int a, int b, int *d, int *x, int *y) {
	if (b == 0) {
		*d = a;
		*x = 1;
		*y = 0;
		return; // Base case: return a, x=1, y=0
	}
	egcd(b, a % b, d, y, x); // Recursive call
	*y -= a / b * *x; // Return GCD and coefficients
}

// egcdll computes the extended GCD of a and b for int64 values.
void egcdll(long long a, long long b, long long *d, long long *x, long long *y) {
	if (b == 0) {
		*d = a;
		*x = 1;
		*y = 0;
		return; // Base case: return a, x=1, y=0
	}
	egcdll(b, a % b, d, y, x); // Recursive call
	*y -= a / b * *x; // Return GCD and coefficients
}

// gcd computes the GCD of a and b.
int gcd(int a, int b) {
	int d, x, y;
	egcd(a, b, &d, &x, &y); // Get GCD using extended GCD
	return d; // Return the GCD
}

// gcdll computes the GCD of a and b for int64 values.
long long gcdll(long long a, long long b) {
	long long d, x, y;
	egcdll(a, b, &d, &x, &y); // Get GCD using extended GCD
	return d; // Return the GCD
}

// IO helper functions

// nextToken and nextLine are function variables that will be initialized 
// by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
char *nextToken;
char *nextLine;

// OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
FILE *OutputBuffer;

// OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
FILE *OutputWriter;

// SetInteractive configures the IO functions for interactive input/output.
void SetInteractive(FILE *w, FILE *r) {
	SetUnbufferedInput(r); // Set unbuffered input for reading
	OutputBuffer = NULL; // No output buffer for interactive mode
	OutputWriter = w; // Set the output writer
}

// Setup OutputBuffer and OutputWriter for buffered output.
void SetOutput(FILE *w) {
	OutputBuffer = w; // Initialize the output buffer
	OutputWriter = OutputBuffer; // Set the output writer to the buffer
}

// Flushes OutputBuffer to ensure all buffered data is written out.
void Flush() {
	if (OutputBuffer != NULL) {
		fflush(OutputBuffer); // Flush the buffer if it is initialized
	}
}

// IsSpace checks if a byte is a whitespace character.
int IsSpace(char c) {
	switch (c) {
	case '\t':
	case '\n':
	case '\v':
	case '\f':
	case '\r':
	case ' ':
		return 1;
	}
	return 0;
}

// IsNewLine checks if a byte is a newline character.
int IsNewLine(char c) {
	switch (c) {
	case '\n':
	case '\r':
		return 1;
	}
	return 0;
}

// SetInput initializes the nextToken function with an input buffer.
void SetInput(FILE *r) {
	char *buf = malloc(1 << 16); // Create a new bytes buffer
	char *b = buf; // Buffer to hold input bytes

	int i = 0; // Index for reading from buffer
	// Function to read the next token from the input
	void nextToken() {
		while (i < strlen(b) && IsSpace(b[i])) {
			i++; // Skip whitespace
		}
		if (i == strlen(b)) {
			return; // Return error if end of buffer is reached
		}
		int j = i;
		while (i < strlen(b) && !IsSpace(b[i])) {
			i++; // Read until whitespace is found
		}
		if (i == j) {
			return; // Return error if no token found
		}
		nextToken = b[j:i]; // Return the token
	}
	// Function to initialize reading from the input
	void initial() {
		fread(buf, 1, 1 << 16, r); // Copy input to buffer
		b = buf; // Get bytes from the buffer
		nextToken = nextToken; // Set nextToken to the rest function
		nextToken(); // Read the first token
	}
	nextToken = initial; // Initialize nextToken

	// Function to read the next line from the input
	void nextLine() {
		while (i < strlen(b) && IsNewLine(b[i])) {
			i++; // Skip new line characters
		}
		if (i == strlen(b)) {
			return; // Return error if end of buffer is reached
		}
		int j = i;
		while (i < strlen(b) && !IsNewLine(b[i])) {
			i++; // Read until new line is found
		}
		nextLine = b[j:i]; // Return the line
	}

	// Function to initialize reading lines from the input
	void initialLn() {
		fread(buf, 1, 1 << 16, r); // Copy input to buffer
		b = buf; // Get bytes from the buffer
		nextLine = nextLine; // Set nextLine to the restLn function
		nextLine(); // Read the first line
	}
	nextLine = initialLn; // Initialize nextLine
}

// SetUnbufferedInput configures the nextToken function for unbuffered input.
void SetUnbufferedInput(FILE *r) {
	char *buf = malloc(1 << 16); // Create a new buffered reader
	char *b = buf; // Buffer to hold input bytes

	int i = 0; // Index for reading from buffer
	// Function to read the next token from the input
	void nextToken() {
		if (i == strlen(b)) { // If the buffer is empty
			fread(buf, 1, 1 << 16, r); // Read until newline
			if (feof(r)) {
				return; // Return error if reading fails
			}
			i = 0; // Reset index
			int j = strlen(b) - 1;
			while (0 <= j && IsSpace(b[j])) {
				j--; // Trim trailing whitespace
			}
			b = b[0:j+1]; // Resize buffer to remove whitespace
		}
		while (i < strlen(b) && IsSpace(b[i])) {
			i++; // Skip whitespace
		}
		int j = i;
		while (i < strlen(b) && !IsSpace(b[i])) {
			i++; // Read until whitespace is found
		}
		if (i == j) {
			return; // Return error if no token found
		}
		nextToken = b[j:i]; // Return the token
	}
}

// IO functions

// readb reads the next token and returns it as a byte slice.
char *readb() {
	char *b = nextToken(); // Read the next token
	if (feof(stdin)) {
		panic(0); // Panic if an error occurs
	}
	return b; // Return the token
}

// reads reads the next token and returns it as a string.
char *reads() {
	return readb(); // Convert byte slice to string
}

// readbln reads the next line as a byte slice, excluding the trailing newline.
char *readbln() {
	char *b = nextLine(); // Read the next line
	if (feof(stdin)) {
		panic(0); // Panic if an error occurs
	}
	return b; // Return the line
}

// readsln reads the next line and returns it as a string.
char *readsln() {
	return readbln(); // Convert byte slice to string
}

// readll reads the next token and returns it as an int64.
long long readll() {
	long long i;
	char *b = readb(); // Read the next token
	if (sscanf(b, "%lld", &i) != 1) {
		panic(0); // Panic if parsing fails
	}
	return i; // Return the parsed int64
}

// readi reads the next token and returns it as an int.
int readi() {
	return (int)readll(); // Convert int64 to int
}

// readf reads the next token and returns it as a float64.
double readf() {
	double f;
	char *b = readb(); // Read the next token
	if (sscanf(b, "%lf", &f) != 1) {
		panic(0); // Panic if parsing fails
	}
	return f; // Return the parsed float64
}

// printf writes formatted output to OutputWriter.
int printf(char *f, ...) {
	va_list args;
	va_start(args, f);
	int res = vfprintf(OutputWriter, f, args); // Write formatted output
	va_end(args);
	return res;
}

// println writes output to OutputWriter without formatting.
int println(char