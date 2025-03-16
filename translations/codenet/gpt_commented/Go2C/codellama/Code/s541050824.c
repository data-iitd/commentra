
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// bufReader struct to handle buffered reading from standard input
typedef struct {
	char *buf; // Buffer to hold the read data
	int i; // Current index in the buffer
} bufReader;

// Initialize a global bufReader instance for reading input
bufReader reader = {
	NULL, // Initialize the buffer to NULL
	0 // Initialize the index to 0
};

// readLine reads a line from the buffered reader into the buffer
void readLine(bufReader *r) {
	// If the current index is less than the buffer length, return (buffer already filled)
	if (r->i < strlen(r->buf)) {
		return;
	}
	r->buf = realloc(r->buf, 0); // Reset the buffer
	r->i = 0; // Reset the index
	char *line = NULL; // Initialize a line pointer
	size_t len = 0; // Initialize the length of the line
	while (getline(&line, &len, stdin) != -1) {
		r->buf = realloc(r->buf, strlen(r->buf) + strlen(line) + 1); // Append the line to the buffer
		strcat(r->buf, line); // Append the line to the buffer
		if (strchr(line, '\n') != NULL) { // If the line contains a newline character
			break; // Break the loop
		}
	}
	free(line); // Free the line pointer
}

// next retrieves the next token from the buffer
char *next(bufReader *r) {
	readLine(r); // Ensure the buffer is filled
	char *from = r->buf + r->i; // Store the starting index of the token
	// Iterate through the buffer until a space is found
	while (r->buf[r->i] != ' ') {
		r->i++; // Move the index forward
	}
	r->buf[r->i] = '\0'; // Terminate the token
	char *s = malloc(strlen(from) + 1); // Allocate memory for the token
	strcpy(s, from); // Copy the token to the allocated memory
	r->i++; // Move the index forward
	return s; // Return the token
}

// nextInt retrieves the next token and converts it to an int64
long long nextInt() {
	char *s = next(&reader); // Get the next token
	long long i = strtoll(s, NULL, 10); // Parse the token as int64
	free(s); // Free the token
	return i; // Return the parsed integer
}

// nextLine is a wrapper to get the next line as a string
char *nextLine() {
	readLine(&reader); // Ensure the buffer is filled
	char *s = malloc(strlen(reader.buf + reader.i) + 1); // Allocate memory for the line
	strcpy(s, reader.buf + reader.i); // Copy the line to the allocated memory
	reader.i = strlen(reader.buf); // Set index to the end of the buffer
	return s; // Return the line
}

// out prints the output to the buffered writer
void out(char *a, ...) {
	va_list args; // Initialize a variable argument list
	va_start(args, a); // Start the variable argument list
	vprintf(a, args); // Print the arguments to the writer
	va_end(args); // End the variable argument list
	printf("\n"); // Print a newline
}

// max returns the maximum of two int64 values
long long max(long long x, long long y) {
	if (x > y) {
		return x; // Return x if it is greater
	}
	return y; // Otherwise return y
}

// min returns the minimum of two int64 values
long long min(long long x, long long y) {
	if (x < y) {
		return x; // Return x if it is lesser
	}
	return y; // Otherwise return y
}

// joinInts converts a slice of int64 to a string with a separator
char *joinInts(long long *a, int n, char *sep) {
	char *b = malloc(n * 20); // Allocate memory for the string
	int i; // Initialize an index
	for (i = 0; i < n; i++) { // Iterate through the slice
		sprintf(b + strlen(b), "%lld%s", a[i], (i == n - 1) ? "" : sep); // Append the integer to the string
	}
	return b; // Return the string
}

// divUp performs ceiling division of x by y
long long divUp(long long x, long long y) {
	return (x + y - 1) / y; // Return the result of ceiling division
}

// main function where the program execution starts
int main() {
	solve(); // Call the solve function to execute the main logic
	return 0; // Return 0 to indicate success
}

// solve contains the main logic for processing input and producing output
void solve() {
	long long N = nextInt(); // Read the number of pairs
	long long *T, *A; // Initialize slices for T and A
	T = malloc(N * sizeof(long long)); // Allocate memory for T
	A = malloc(N * sizeof(long long)); // Allocate memory for A
	// Read pairs of integers into T and A
	int i; // Initialize an index
	for (i = 0; i < N; i++) {
		T[i] = nextInt(); // Read each pair
		A[i] = nextInt(); // Read each pair
	}
	long long t, a; // Initialize t and a with the first pair
	// Iterate through the remaining pairs to compute the required values
	for (i = 1; i < N; i++) {
		long long r = max(divUp(t, T[i]), divUp(a, A[i])); // Calculate the required multiplier
		t, a = T[i] * r, A[i] * r; // Update t and a based on the multiplier
	}
	out("%lld %lld", t + a); // Output the final result
}

