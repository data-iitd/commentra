

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

// bufReader struct to handle buffered reading from standard input
typedef struct {
	FILE *r; // Buffered reader
	char *buf; // Buffer to hold the read data
	size_t i; // Current index in the buffer
} bufReader;

// Initialize a global bufReader instance for reading input
bufReader reader = {
	.r = stdin, // Create a new buffered reader from standard input
	.buf = NULL, // Initialize an empty buffer
	0, // Start index at 0
};

// readLine reads a line from the buffered reader into the buffer
void readLine() {
	// If the current index is less than the buffer length, return (buffer already filled)
	if (reader.i < strlen(reader.buf)) {
		return;
	}
	free(reader.buf); // Free the buffer
	reader.buf = NULL; // Reset the buffer
	reader.i = 0; // Reset the index
	for {
		// Read a line from the reader
		char *line = NULL;
		size_t len = 0;
		getline(&line, &len, reader.r);
		if (line == NULL) {
			break; // Break on EOF
		}
		reader.buf = realloc(reader.buf, len + 1); // Reallocate the buffer
		if (reader.buf == NULL) {
			free(line); // Free the line
			break; // Break on error
		}
		strcpy(reader.buf, line); // Copy the line to the buffer
		free(line); // Free the line
		if (len == 0) { // If the line is empty, break the loop
			break;
		}
	}
}

// next retrieves the next token from the buffer
char *next() {
	readLine(); // Ensure the buffer is filled
	char *from = reader.buf + reader.i; // Store the starting index of the token
	// Iterate through the buffer until a space is found
	while (reader.buf[reader.i]!='') {
		reader.i++; // Move the index forward
	}
	char *s = strndup(from, reader.i - reader.i); // Extract the token from the buffer
	reader.i++; // Move the index forward
	return s; // Return the token
}

// nextLine retrieves the next line from the buffer
char *nextLine() {
	readLine(); // Ensure the buffer is filled
	char *s = strdup(reader.buf + reader.i); // Get the remaining part of the buffer as a string
	reader.i = strlen(reader.buf); // Set index to the end of the buffer
	return s; // Return the line
}

// Initialize a global buffered writer for output
FILE *writer = stdout;

// next is a wrapper to get the next token as a string
char *next() {
	return reader.next(); // Call the next method of bufReader
}

// nextInt retrieves the next token and converts it to an int64
int64_t nextInt() {
	int64_t i;
	sscanf(reader.next(), "%" PRId64, &i); // Parse the next token as int64
	return i; // Return the parsed integer
}

// nextLine is a wrapper to get the next line as a string
char *nextLine() {
	return reader.nextLine(); // Call the nextLine method of bufReader
}

// out prints the output to the buffered writer
void out(const char *format,...) {
	va_list args;
	va_start(args, format);
	vfprintf(writer, format, args);
	va_end(args);
	fprintf(writer, "\n");
}

// max returns the maximum of two int64 values
int64_t max(int64_t x, int64_t y) {
	if (x > y) {
		return x; // Return x if it is greater
	}
	return y; // Otherwise return y
}

// min returns the minimum of two int64 values
int64_t min(int64_t x, int64_t y) {
	if (x < y) {
		return x; // Return x if it is lesser
	}
	return y; // Otherwise return y
}

// joinInts converts a slice of int64 to a string with a separator
char *joinInts(int64_t *a, size_t n, char *sep) {
	char *b = malloc(n * 20); // Create a string slice to hold the converted integers
	char *p = b; // Initialize the pointer to the beginning of the slice
	for (size_t i = 0; i < n; i++) {
		p += sprintf(p, "%" PRId64, a[i]); // Convert each int64 to string
		if (i < n - 1) {
			p += sprintf(p, "%s", sep); // Add the separator
		}
	}
	return b; // Return the string slice
}

// divUp performs ceiling division of x by y
int64_t divUp(int64_t x, int64_t y) {
	return (x + y - 1) / y; // Return the result of ceiling division
}

// main function where the program execution starts
int main() {
	solve(); // Call the solve function to execute the main logic
	fflush(writer); // Flush the buffered writer to output
}

// solve contains the main logic for processing input and producing output
void solve() {
	int64_t N = nextInt(); // Read the number of pairs
	int64_t *T = malloc(N * sizeof(int64_t)); // Initialize slices for T and A
	int64_t *A = malloc(N * sizeof(int64_t));
	// Read pairs of integers into T and A
	for (int64_t i = 0; i < N; i++) {
		T[i] = nextInt();
		A[i] = nextInt();
	}
	int64_t t = T[0], a = A[0]; // Initialize t and a with the first pair
	// Iterate through the remaining pairs to compute the required values
	for (int64_t i = 1; i < N; i++) {
		int64_t r = max(divUp(t, T[i]), divUp(a, A[i])); // Calculate the required multiplier
		t = T[i] * r; // Update t based on the multiplier
		a = A[i] * r; // Update a based on the multiplier
	}
	out("%" PRId64, t + a); // Output the final result
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

// bufReader struct to handle buffered reading from standard input
typedef struct {
	FILE *r; // Buffered reader
	char *buf; // Buffer to hold the read data
	size_t i; // Current index in the buffer
} bufReader;

// Initialize a global bufReader instance for reading input
bufReader reader = {
	.r = stdin, // Create a new buffered reader from standard input
	.buf = NULL, // Initialize an empty buffer
	0, // Start index at 0
};

// readLine reads a line from the buffered reader into the buffer
void readLine() {
	// If the current index is less than the buffer length, return (buffer already filled)
	if (reader.i < strlen(reader.buf)) {
		return;
	}
	free(reader.buf); // Free the buffer
	reader.buf = NULL; // Reset the buffer
	reader.i = 0; // Reset the index
	for {
		// Read a line from the reader
		char *line = NULL;
		size_t len = 0;
		getline(&line, &len, reader.r);
		if (line == NULL) {
			break; // Break on EOF
		}
		reader.buf = realloc(reader.buf, len + 1); // Reallocate the buffer
		if (reader.buf == NULL) {
			free(line); // Free the line
			break; // Break on error
		}
		strcpy(reader.buf, line); // Copy the line to the buffer
		free(line); // Free the line
		if (len == 0) { // If the line is empty, break the loop
			break;
		}
	}
}

// next retrieves the next token from the buffer
char *next() {
	readLine(); // Ensure the buffer is filled
	char *from = reader.buf + reader.i; // Store the starting index of the token
	// Iterate through the buffer until a space is found
	while (reader.buf[reader.i]!='') {
		reader.i++; // Move the index forward
	}
	char *s = strndup(from, reader.i - reader.i); // Extract the token from the buffer
	reader.i++; // Move the index forward
	return s; // Return the token
}

// nextLine retrieves the next line from the buffer
char *nextLine() {
	readLine(); // Ensure the buffer is filled
	char *s = strdup(reader.buf + reader.i); // Get the remaining part of the buffer as a string
	reader.i = strlen(reader.buf); // Set index to the end of the buffer
	return s; // Return the line
}

// Initialize a global buffered writer for output
FILE *writer = stdout;

// next is a wrapper to get the next token as a string
char *next() {
	return reader.next(); // Call the next method of bufReader
}

// nextInt retrieves the next token and converts it to an int64
int64_t nextInt() {
	int64_t i;
	sscanf(reader.next(), "%" PRId64, &i); // Parse the next token as int64
	return i; // Return the parsed integer
}

// nextLine is a wrapper to get the next line as a string
char *nextLine() {
	return reader.nextLine(); // Call the nextLine method of bufReader
}

// out prints the output to the buffered writer
void out(const char *format,...) {
	va_list args;
	va_start(args, format);
	vfprintf(writer, format, args);
	va_end(args);
	fprintf(writer, "\n");
}

// max returns the maximum of two int64 values
int64_t max(int64_t x, int64_t y) {
	if (x > y) {
		return x; // Return x if it is greater
	}
	return y; // Otherwise return y
}

// min returns the minimum of two int64 values
int64_t min(int64_t x, int64_t y) {
	if (x < y) {
		return x; // Return x if it is lesser
	}
	return y; // Otherwise return y
}

// joinInts converts a slice of int64 to a string with a separator
char *joinInts(int64_t *a, size_t n, char *sep) {
	char *b = malloc(n * 20); // Create a string slice to hold the converted integers
	char *p = b; // Initialize the pointer to the beginning of the slice
	for (size_t i = 0; i < n; i++) {
		p += sprintf(p, "%" PRId64, a[i]); // Convert each int64 to string
		if (i < n - 1) {
			p += sprintf(p, "%s", sep); // Add the separator
		}
	}
	return b; // Return the string slice
}

// divUp performs ceiling division of x by y
int64_t divUp(int64_t x, int64_t y) {
	return (x + y - 1) / y; // Return the result of ceiling division
}

// main function where the program execution starts
int main() {
	solve(); // Call the solve function to execute the main logic
	fflush(writer); // Flush the buffered writer to output
}

// solve contains the main logic for processing input and producing output
void solve() {
	int64_t N = nextInt(); // Read the number of pairs
	int64_t *T = malloc(N * sizeof(int64_t)); // Initialize slices for T and A
	int64_t *A = malloc(N * sizeof(int64_t));
	// Read pairs of integers into T and A
	for (int64_t i = 0; i < N; i++) {
		T[i] = nextInt();
		A[i] = nextInt();
	}
	int64_t t = T[0], a = A[0]; // Initialize t and a with the first pair
	// Iterate through the remaining pairs to compute the required values
	for (int64_t i = 1; i < N; i++) {
		int64_t r = max(divUp(t, T[i]), divUp(a, A[i])); // Calculate the required multiplier
		t = T[i] * r; // Update t based on the multiplier
		a = A[i] * r; // Update a based on the multiplier
	}
	out("%" PRId64, t + a); // Output the final result
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.