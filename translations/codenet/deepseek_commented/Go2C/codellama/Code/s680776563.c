
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function: Entry point of the program.
// Initializes a FastScanner, reads three integers A, B, and C,
// and checks if the difference between consecutive integers is the same.
// If the difference is the same, it prints "YES"; otherwise, it prints "NO".
int main() {
	FastScanner fsc = newFastScanner();
	int A, B, C;
	A = fsc.nextInt();
	B = fsc.nextInt();
	C = fsc.nextInt();
	if (B - A == C - B) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}

// FastScanner struct: Efficiently reads input.
typedef struct {
	char *buf;
	int p;
} FastScanner;

// newFastScanner: Initializes a new FastScanner with a buffered reader.
FastScanner newFastScanner() {
	FastScanner fsc;
	fsc.buf = (char *)malloc(1024 * sizeof(char));
	fsc.p = 0;
	return fsc;
}

// next: Reads the next token from the input.
char *next(FastScanner *fsc) {
	if (fsc->p >= strlen(fsc->buf)) {
		fsc->p = 0;
		fread(fsc->buf, 1, 1024, stdin);
	}
	int start = fsc->p;
	while (fsc->buf[fsc->p] != ' ') {
		fsc->p++;
	}
	char *result = (char *)malloc((fsc->p - start + 1) * sizeof(char));
	strncpy(result, fsc->buf + start, fsc->p - start);
	result[fsc->p - start] = '\0';
	fsc->p++;
	return result;
}

// nextLine: Reads the next line from the input.
char *nextLine(FastScanner *fsc) {
	if (fsc->p >= strlen(fsc->buf)) {
		fsc->p = 0;
		fread(fsc->buf, 1, 1024, stdin);
	}
	int start = fsc->p;
	fsc->p = strlen(fsc->buf);
	char *result = (char *)malloc((fsc->p - start + 1) * sizeof(char));
	strncpy(result, fsc->buf + start, fsc->p - start);
	result[fsc->p - start] = '\0';
	return result;
}

// nextInt: Reads the next integer from the input.
int nextInt(FastScanner *fsc) {
	char *str = next(fsc);
	int result = atoi(str);
	free(str);
	return result;
}

// nextInt64: Reads the next 64-bit integer from the input.
int64_t nextInt64(FastScanner *fsc) {
	char *str = next(fsc);
	int64_t result = atoll(str);
	free(str);
	return result;
}

// pre: Ensures that the buffer has data to read.
void pre(FastScanner *fsc) {
	if (fsc->p >= strlen(fsc->buf)) {
		fsc->p = 0;
		fread(fsc->buf, 1, 1024, stdin);
	}
}

// readLine: Reads the entire line from the input and stores it in the buffer.
void readLine(FastScanner *fsc) {
	fsc->p = 0;
	fread(fsc->buf, 1, 1024, stdin);
}

// Max, Min, Gcd, Abs functions: Utility functions for various operations.
int intMax(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

int64_t int64Max(int64_t a, int64_t b) {
	if (a < b) {
		return b;
	}
	return a;
}

double float64Max(double a, double b) {
	if (a < b) {
		return b;
	}
	return a;
}

int intMin(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int64_t int64Min(int64_t a, int64_t b) {
	if (a > b) {
		return b;
	}
	return a;
}

double float64Min(double a, double b) {
	if (a > b) {
		return b;
	}
	return a;
}

int intGcd(int a, int b) {
	if (a < b) {
		b = a;
	}
	if (b == 0) {
		return a;
	}
	return intGcd(b, a % b);
}

int64_t int64Gcd(int64_t a, int64_t b) {
	if (a < b) {
		b = a;
	}
	if (b == 0) {
		return a;
	}
	return int64Gcd(b, a % b);
}

int intAbs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

int64_t int64Abs(int64_t a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

