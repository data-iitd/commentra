
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Go:
// package main

int main() {
	// Initialize a new scanner for reading input
	Scanner sc = NewScanner();

	// Read two integers n and k from input
	int n = sc.ReadInt();
	int k = sc.ReadInt();

	// Initialize a variable to hold the total count
	long long total = 0;

	// Calculate the total combinations from k to n+1
	for (int i = k; i <= n+1; i++) {
		total += combi(n, i); // Add combinations for the current i
		total = total % (Pow64(10, 9) + 7); // Apply modulo to prevent overflow
	}

	// Print the final total
	printf("%lld\n", total);
}

// combi calculates the number of combinations based on the given n and k
long long combi(int n, int k) {
	// Calculate the minimum and maximum possible values for combinations
	long long min = (k-1) * (k) / 2;
	long long max = (2*n-k+1) * (k) / 2;
	// Return the count of combinations
	return max - min + 1;
}

// util
// *   math/simple

// Abs returns the absolute value of an integer
int Abs(int x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min returns the minimum value from a list of integers
int Min(int values[], int length) {
	if (length == 0) {
		panic("no values");
	}
	int min = values[0];
	for (int i = 1; i < length; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max returns the maximum value from a list of integers
int Max(int values[], int length) {
	if (length == 0) {
		panic("no values");
	}
	int max = values[0];
	for (int i = 1; i < length; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow calculates the power of a base raised to an exponent
int Pow(int base, unsigned int exponent) {
	int answer = 1;
	for (unsigned int i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// Abs64 returns the absolute value of an int64
long long Abs64(long long x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min64 returns the minimum value from a list of int64 values
long long Min64(long long values[], int length) {
	if (length == 0) {
		panic("no values");
	}
	long long min = values[0];
	for (int i = 1; i < length; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max64 returns the maximum value from a list of int64 values
long long Max64(long long values[], int length) {
	if (length == 0) {
		panic("no values");
	}
	long long max = values[0];
	for (int i = 1; i < length; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow64 calculates the power of a base (int64) raised to an exponent
long long Pow64(long long base, unsigned int exponent) {
	long long answer = 1;
	for (unsigned int i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// *   io

// Scanner is a custom input scanner that reads words from standard input
typedef struct {
	char* buf;
	int bufSize;
	int bufPos;
} Scanner;

// NewScanner initializes a new Scanner instance
Scanner NewScanner() {
	Scanner sc;
	sc.bufSize = 1024;
	sc.buf = (char*)malloc(sc.bufSize * sizeof(char));
	sc.bufPos = 0;
	return sc;
}

// ReadString reads a single string from input
char* ReadString(Scanner* sc) {
	char* buf = sc->buf;
	int bufSize = sc->bufSize;
	int bufPos = sc->bufPos;

	// Read the next word from input
	int c = getchar();
	while (c != EOF && c != ' ' && c != '\n') {
		// If the buffer is full, double its size
		if (bufPos == bufSize) {
			bufSize *= 2;
			buf = (char*)realloc(buf, bufSize * sizeof(char));
		}
		// Add the character to the buffer
		buf[bufPos++] = c;
		// Read the next character
		c = getchar();
	}
	// Add a null terminator to the buffer
	buf[bufPos] = '\0';

	// Update the scanner's buffer and position
	sc->buf = buf;
	sc->bufSize = bufSize;
	sc->bufPos = bufPos;

	// Return the scanned text
	return buf;
}

// ReadInt reads a single integer from input
int ReadInt(Scanner* sc) {
	char* buf = ReadString(sc);
	int num = atoi(buf);
	return num;
}

// ReadInt64 reads a single int64 from input
long long ReadInt64(Scanner* sc) {
	char* buf = ReadString(sc);
	long long num = atoll(buf);
	return num;
}

