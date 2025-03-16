#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastScanner is a structure for efficient input reading
typedef struct FastScanner {
	char *buf; // Buffer to hold the input data
	int p; // Current position in the buffer
	int len; // Length of the buffer
} FastScanner;

// NewFastScanner initializes and returns a new FastScanner
FastScanner NewFastScanner() {
	FastScanner fsc;
	fsc.buf = (char *)malloc(1024 * sizeof(char));
	fsc.p = 0;
	fsc.len = 0;
	return fsc;
}

// Next reads the next token from the input
char *Next(FastScanner *fsc) {
	fsc->pre(); // Ensure there is data to read
	int start = fsc->p; // Mark the start position
	// Iterate through the buffer until a space is found
	while (fsc->p < fsc->len) {
		if (fsc->buf[fsc->p] == ' ') {
			break;
		}
		fsc->p++;
	}
	char *result = (char *)malloc((fsc->p - start + 1) * sizeof(char));
	strncpy(result, fsc->buf + start, fsc->p - start);
	result[fsc->p - start] = '\0';
	fsc->p++; // Move past the space
	return result;
}

// NextLine reads the next line from the input
char *NextLine(FastScanner *fsc) {
	fsc->pre(); // Ensure there is data to read
	int start = fsc->p; // Mark the start position
	fsc->p = fsc->len; // Move to the end of the buffer
	char *result = (char *)malloc((fsc->p - start + 1) * sizeof(char));
	strncpy(result, fsc->buf + start, fsc->p - start);
	result[fsc->p - start] = '\0';
	return result;
}

// NextInt reads the next integer from the input
int NextInt(FastScanner *fsc) {
	char *token = Next(fsc);
	int result = atoi(token);
	free(token);
	return result;
}

// NextInt64 reads the next int64 from the input
int64_t NextInt64(FastScanner *fsc) {
	char *token = Next(fsc);
	int64_t result = atoll(token);
	free(token);
	return result;
}

// pre checks if the buffer needs to be filled with new data
void pre(FastScanner *fsc) {
	if (fsc->p >= fsc->len) { // If the current position is at or beyond the buffer length
		fsc->readLine(); // Read a new line into the buffer
		fsc->p = 0; // Reset the position to the start of the buffer
	}
}

// readLine reads a line from the input and fills the buffer
void readLine(FastScanner *fsc) {
	fsc->buf = (char *)realloc(fsc->buf, 1024 * sizeof(char));
	fsc->len = 0;
	while (1) {
		fsc->buf[fsc->len] = getchar();
		if (fsc->buf[fsc->len] == '\n') {
			fsc->buf[fsc->len] = '\0';
			break;
		}
		fsc->len++;
	}
}

// IntMax returns the maximum of two integers
int IntMax(int a, int b) {
	if (a < b) {
		return b; // Return b if it is greater
	}
	return a; // Otherwise, return a
}

// Int64Max returns the maximum of two int64 values
int64_t Int64Max(int64_t a, int64_t b) {
	if (a < b) {
		return b; // Return b if it is greater
	}
	return a; // Otherwise, return a
}

// Float64Max returns the maximum of two float64 values
double Float64Max(double a, double b) {
	if (a < b) {
		return b; // Return b if it is greater
	}
	return a; // Otherwise, return a
}

// IntMin returns the minimum of two integers
int IntMin(int a, int b) {
	if (a > b) {
		return b; // Return b if it is smaller
	}
	return a; // Otherwise, return a
}

// Int64Min returns the minimum of two int64 values
int64_t Int64Min(int64_t a, int64_t b) {
	if (a > b) {
		return b; // Return b if it is smaller
	}
	return a; // Otherwise, return a
}

// Float64Min returns the minimum of two float64 values
double Float64Min(double a, double b) {
	if (a > b) {
		return b; // Return b if it is smaller
	}
	return a; // Otherwise, return a
}

// IntGcd computes the greatest common divisor of two integers
int IntGcd(int a, int b) {
	if (a < b) {
		b = a; // Ensure a is the larger number
	}
	if (b == 0) {
		return a; // If b is zero, return a
	}
	return IntGcd(b, a % b); // Recursive call to find GCD
}

// Int64Gcd computes the greatest common divisor of two int64 values
int64_t Int64Gcd(int64_t a, int64_t b) {
	if (a < b) {
		b = a; // Ensure a is the larger number
	}
	if (b == 0) {
		return a; // If b is zero, return a
	}
	return Int64Gcd(b, a % b); // Recursive call to find GCD
}

// IntAbs returns the absolute value of an integer
int IntAbs(int a) {
	if (a < 0) {
		a *= -1; // Negate if a is negative
	}
	return a; // Return the absolute value
}

// Int64Abs returns the absolute value of an int64
int64_t Int64Abs(int64_t a) {
	if (a < 0) {
		a *= -1; // Negate if a is negative
	}
	return a; // Return the absolute value
}

int main() {
	// Initialize a new FastScanner to read input
	FastScanner fsc = NewFastScanner();
	// Read three integers A, B, and C from input
	int A = NextInt(&fsc);
	int B = NextInt(&fsc);
	int C = NextInt(&fsc);
	// Check if the difference between B and A is equal to the difference between C and B
	if (B - A == C - B) {
		// If the differences are equal, print "YES"
		printf("YES\n");
	} else {
		// Otherwise, print "NO"
		printf("NO\n");
	}
	return 0;
}

