
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function for finding the maximum and minimum values
int IntMax(int a, int b) {
	// Return the larger of the two integers
	if (a < b) {
		return b;
	}
	return a;
}

int IntMin(int a, int b) {
	// Return the smaller of the two integers
	if (a > b) {
		return b;
	}
	return a;
}

// Helper function for finding the greatest common divisor of two integers
int IntGcd(int a, int b) {
	// If b is 0, return a as the GCD
	if (b == 0) {
		return a;
	}

	// Recursively call IntGcd with b and the remainder of a divided by b
	return IntGcd(b, a % b);
}

// Helper function for finding the absolute value of an integer
int IntAbs(int a) {
	// If a is negative, return the negative of a
	if (a < 0) {
		return -a;
	}
	// Otherwise, return a as is
	return a;
}

// FastScanner struct and methods for reading input efficiently
typedef struct FastScanner {
	FILE *in;
	char *buffer;
	int len;
	int pos;
} FastScanner;

FastScanner *NewFastScanner() {
	// Allocate a new FastScanner object
	FastScanner *fsc = malloc(sizeof(FastScanner));

	// Read the first line of the input into the buffer
	fsc->in = fopen("input.txt", "r");
	fsc->buffer = malloc(1024);
	fsc->len = fread(fsc->buffer, 1, 1024, fsc->in);
	fsc->pos = 0;

	// Return the new FastScanner object
	return fsc;
}

void DeleteFastScanner(FastScanner *fsc) {
	// Close the input file
	fclose(fsc->in);
	// Free the FastScanner object
	free(fsc->buffer);
	free(fsc);
}

char *Next(FastScanner *fsc) {
	// If the position is at the end of the buffer, read a new line
	if (fsc->pos >= fsc->len) {
		fsc->pos = 0;
		fsc->len = fread(fsc->buffer, 1, 1024, fsc->in);
	}

	// Find the start index of the next token
	int start = fsc->pos;
	// Find the end index of the next token (space or newline character)
	while (fsc->pos < fsc->len) {
		if (fsc->buffer[fsc->pos] =='') {
			break;
		}
		fsc->pos++;
	}

	// Allocate a new string to hold the token
	char *result = malloc(fsc->pos - start + 1);
	// Copy the token from the buffer to the string
	for (int i = start; i < fsc->pos; i++) {
		result[i - start] = fsc->buffer[i];
	}
	// Terminate the string
	result[fsc->pos - start] = '\0';
	// Move the position index to the next character
	fsc->pos++;

	// Return the result
	return result;
}

int NextInt(FastScanner *fsc) {
	// Read a string token as an integer
	char *token = Next(fsc);
	// Convert the string token to an integer and return it
	int num = atoi(token);
	return num;
}

int main() {
	// Initialize a new FastScanner object called fsc
	FastScanner *fsc = NewFastScanner();

	// Read the first three integers A, B, and C from the standard input
	int A = NextInt(fsc);
	int B = NextInt(fsc);
	int C = NextInt(fsc);

	// Check if the difference between B and A is equal to the difference between C and B
	if (B - A == C - B) {
		// If it is, print "YES"
		printf("YES");
	} else {
		// Otherwise, print "NO"
		printf("NO");
	}

	// Delete the FastScanner object
	DeleteFastScanner(fsc);
}

