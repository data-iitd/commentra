
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

// Define an infinite value for comparison
int inf = 2147483647;

// Initialize a new scanner for input
struct scanner {
	FILE *r; // Buffered reader
	char *buf; // Buffer to hold input
	int p; // Current position in the buffer
};

// Create a new scanner instance
struct scanner newScanner() {
	FILE *rdr = fopen("input.txt", "r"); // Initialize with a buffer size
	struct scanner s = {r: rdr};
	return s;
}

// Read the next token from the input
char *next(struct scanner *s) {
	s->pre(); // Ensure the buffer is filled
	int start = s->p; // Mark the start of the token
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] == ' ') { // Stop at space
			break;
		}
	}
	char *result = malloc(s->p - start + 1); // Extract the token
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++; // Move past the space
	return result;
}

// Read the entire line from the input
char *line(struct scanner *s) {
	s->pre(); // Ensure the buffer is filled
	int start = s->p; // Mark the start of the line
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = malloc(s->p - start + 1); // Return the line
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}

// Read the next string from the input
char *string(struct scanner *s) {
	return next(s); // Call next to get the next token
}

// Read the next integer from the input
int int_(struct scanner *s) {
	char *token = next(s); // Convert the next token to an integer
	int v = atoi(token);
	free(token);
	return v;
}

// Read multiple integers from the input
int *ints(struct scanner *s, int n) {
	int *r = malloc(n * sizeof(int)); // Create a slice to hold the integers
	for (int i = 0; i < n; i++) {
		r[i] = int_(s); // Read each integer
	}
	return r; // Return the slice of integers
}

// Read the next int64 from the input
int64_t int64(struct scanner *s) {
	char *token = next(s); // Convert the next token to int64
	int64_t v = strtoll(token, NULL, 10);
	free(token);
	return v;
}

// Read the next uint64 from the input
uint64_t uint64(struct scanner *s) {
	char *token = next(s); // Convert the next token to uint64
	uint64_t v = strtoull(token, NULL, 10);
	free(token);
	return v;
}

// Read the next float64 from the input
double float64(struct scanner *s) {
	char *token = next(s); // Convert the next token to float64
	double v = strtod(token, NULL);
	free(token);
	return v;
}

// Pre-read to ensure there is data in the buffer
void pre(struct scanner *s) {
	if (s->p >= strlen(s->buf)) { // If current position is at the end of the buffer
		s->readLine(); // Read a new line
		s->p = 0; // Reset position to the start of the new buffer
	}
}

// Read a line from the input and fill the buffer
void readLine(struct scanner *s) {
	s->buf = malloc(10000); // Reset the buffer
	for (;;) {
		char *l = fgets(s->buf, 10000, s->r); // Read a line
		if (feof(s->r)) { // If the line is complete
			break;
		}
	}
}

// Utility functions for various operations

// Check if a value is within a range
int in(int c, int a, int z) {
	return c >= a && c < z;
}

// Check if a value is outside a range
int out(int c, int a, int z) {
	return !in(c, a, z);
}

// Convert boolean to integer (1 for true, 0 for false)
int btoi(int b) {
	if (b) {
		return 1;
	}
	return 0;
}

// Convert integer to boolean (non-zero to true, zero to false)
int itob(int a) {
	return a != 0;
}

// Return the maximum value from a list of integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Return the minimum value from a list of integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Calculate the sum of a slice of integers
int sum(int *a, int n) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		r += a[i];
	}
	return r;
}

// Calculate the product of a slice of integers
int pro(int *a, int n) {
	int r = a[0];
	for (int i = 1; i < n; i++) {
		r *= a[i];
	}
	return r;
}

// Fill a slice with a specified value
void fill(int *a, int n, int v) {
	for (int i = 0; i < n; i++) {
		a[i] = v;
	}
}

// Return the minimum and maximum of two integers
int minmax(int a, int b) {
	if (a > b) {
		return b, a;
	}
	return a, b;
}

// Return the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Calculate the ceiling of a division of two integers
int ceil(int a, int b) {
	if (a % b != 0) {
		return 1;
	}
	return 0;
}

// Print a slice of strings with space separation
void printStrings(char **out, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s", out[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

// Print a slice of integers with space separation
void printInts(int *out, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", out[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
	// Read input as a string
	char *N = next(&next);
	char *b = malloc(strlen(N) + 1); // Convert string to byte slice
	strcpy(b, N);
	int n = 0; // Initialize sum of digits

	// Calculate the sum of digits in the input number
	for (int i = 0; i < strlen(b); i++) {
		n += b[i] - '0'; // Convert byte to int and accumulate
	}

	// Convert the string input to an integer
	int m = atoi(N);
	// Check if the number is divisible by the sum of its digits
	if (m % n == 0) {
		printf("Yes\n"); // Print "Yes" if divisible
	} else {
		printf("No\n"); // Print "No" if not divisible
	}
}

