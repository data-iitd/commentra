
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// FastScanner struct and methods for reading input efficiently
typedef struct FastScanner {
	char *buf;
	int p;
	int len;
} FastScanner;

FastScanner *NewFastScanner() {
	// Initialize a new FastScanner object
	FastScanner *fsc = (FastScanner *)malloc(sizeof(FastScanner));
	// Initialize the buffer with a size of 1024 bytes
	fsc->buf = (char *)malloc(1024 * sizeof(char));
	// Initialize the position index to 0
	fsc->p = 0;
	// Initialize the length of the buffer to 0
	fsc->len = 0;
	// Return the new FastScanner object
	return fsc;
}

void readLine(FastScanner *fsc) {
	// Read a line from the input buffer into the buffer
	fgets(fsc->buf, 1024, stdin);
	// Update the length of the buffer
	fsc->len = strlen(fsc->buf);
}

char *next(FastScanner *fsc) {
	// Preprocess the input buffer if necessary
	if (fsc->p >= fsc->len) {
		readLine(fsc);
		fsc->p = 0;
	}

	// Find the start index of the next token
	int start = fsc->p;
	// Find the end index of the next token (space or newline character)
	while (fsc->p < fsc->len) {
		if (fsc->buf[fsc->p] == ' ') {
			break;
		}
		fsc->p++;
	}

	// Return the substring of the input buffer from the start index to the current position
	char *result = (char *)malloc((fsc->p - start + 1) * sizeof(char));
	strncpy(result, fsc->buf + start, fsc->p - start);
	result[fsc->p - start] = '\0';
	// Move the position index to the next character
	fsc->p++;

	// Return the result
	return result;
}

char *nextLine(FastScanner *fsc) {
	// Preprocess the input buffer if necessary
	if (fsc->p >= fsc->len) {
		readLine(fsc);
		fsc->p = 0;
	}

	// Find the start index of the next line
	int start = fsc->p;
	// Read the rest of the line into the buffer
	fsc->p = fsc->len;

	// Return the substring of the input buffer from the start index to the end of the line
	char *result = (char *)malloc((fsc->len - start + 1) * sizeof(char));
	strncpy(result, fsc->buf + start, fsc->len - start);
	result[fsc->len - start] = '\0';

	// Return the result
	return result;
}

int nextInt(FastScanner *fsc) {
	// Read a string token as an integer
	char *token = next(fsc);
	// Convert the string token to an integer and return it
	int num = atoi(token);
	free(token);
	return num;
}

int64_t nextInt64(FastScanner *fsc) {
	// Read a string token as an integer
	char *token = next(fsc);
	// Convert the string token to an integer and return it
	int64_t num = atoll(token);
	free(token);
	return num;
}

double nextDouble(FastScanner *fsc) {
	// Read a string token as a floating-point number
	char *token = next(fsc);
	// Convert the string token to a floating-point number and return it
	double num = atof(token);
	free(token);
	return num;
}

// Helper functions for finding the maximum and minimum values
int intMax(int a, int b) {
	// Return the larger of the two integers
	if (a < b) {
		return b;
	}
	return a;
}

int64_t int64Max(int64_t a, int64_t b) {
	// Return the larger of the two integers
	if (a < b) {
		return b;
	}
	return a;
}

double doubleMax(double a, double b) {
	// Return the larger of the two floating-point numbers
	if (a < b) {
		return b;
	}
	return a;
}

int intMin(int a, int b) {
	// Return the smaller of the two integers
	if (a > b) {
		return b;
	}
	return a;
}

int64_t int64Min(int64_t a, int64_t b) {
	// Return the smaller of the two integers
	if (a > b) {
		return b;
	}
	return a;
}

double doubleMin(double a, double b) {
	// Return the smaller of the two floating-point numbers
	if (a > b) {
		return b;
	}
	return a;
}

// Helper function for finding the greatest common divisor of two integers
int intGcd(int a, int b) {
	// If b is 0, return a as the GCD
	if (b == 0) {
		return a;
	}

	// Recursively call intGcd with b and the remainder of a divided by b
	return intGcd(b, a % b);
}

int64_t int64Gcd(int64_t a, int64_t b) {
	// If b is 0, return a as the GCD
	if (b == 0) {
		return a;
	}

	// Recursively call int64Gcd with b and the remainder of a divided by b
	return int64Gcd(b, a % b);
}

// Helper function for finding the absolute value of an integer
int intAbs(int a) {
	// If a is negative, return the negative of a
	if (a < 0) {
		return -a;
	}
	// Otherwise, return a as is
	return a;
}

int64_t int64Abs(int64_t a) {
	// If a is negative, return the negative of a
	if (a < 0) {
		return -a;
	}
	// Otherwise, return a as is
	return a;
}

// main function is the entry point of our program
int main() {
	// Initialize a new FastScanner object called fsc
	FastScanner *fsc = NewFastScanner();

	// Read the first three integers A, B, and C from the standard input
	int A = nextInt(fsc);
	int B = nextInt(fsc);
	int C = nextInt(fsc);

	// Check if the difference between B and A is equal to the difference between C and B
	if (B - A == C - B) {
		// If it is, print "YES"
		printf("YES\n");
	} else {
		// Otherwise, print "NO"
		printf("NO\n");
	}

	// Free the memory allocated for the FastScanner object
	free(fsc->buf);
	free(fsc);

	return 0;
}

