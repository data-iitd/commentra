
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to read an integer from the input
int ScanInt(char *s) {
	// Read the next token from the input
	scanf("%d", s);
	// Return the scanned integer
	return *s;
}

// Function to read a float64 from the input
double ScanFloat64(char *s) {
	// Read the next token from the input
	scanf("%lf", s);
	// Return the scanned float64
	return *s;
}

// Function to read a text from the input
char *ScanText(char *s) {
	// Read the next token from the input
	scanf("%s", s);
	// Return the scanned text
	return s;
}

// Function to find the maximum of two integers
int Max(int a, int b) {
	// If a is smaller than b, return b
	if (a < b) {
		return b;
	}
	// Otherwise, return a
	return a;
}

// Function to find the minimum of two integers
int Min(int a, int b) {
	// If a is greater than b, return b
	if (a > b) {
		return b;
	}
	// Otherwise, return a
	return a;
}

// Function to find the absolute value of an integer
int Abs(int a) {
	// If a is negative, return the negative of a
	if (a < 0) {
		return -a;
	}
	// Otherwise, return a
	return a;
}

int main() {
	// Initialize a scanner to read input from standard input
	char s[100];
	scanf("%d", s);
	int N = atoi(s);
	// Allocate memory for two arrays X and Y of size N
	int *X = (int *) malloc(N * sizeof(int));
	int *Y = (int *) malloc(N * sizeof(int));
	// Read N integers from the input and store them in X and Y arrays
	for (int i = 0; i < N; i++) {
		scanf("%d", s);
		X[i] = atoi(s);
		// Store the current element of X in Y array for sorting
		Y[i] = X[i];
	}
	// Sort the Y array in ascending order
	qsort(Y, N, sizeof(int), (int (*)(const void *, const void *)) &strcmp);
	// Find the median of Y array
	int m1 = Y[N/2 - 1];
	int m2 = Y[N/2];
	// Iterate through each element of X array and print the corresponding median value
	for (int i = 0; i < N; i++) {
		if (X[i] <= m1) {
			// If X[i] is smaller than m1, print m2 as the answer
			printf("%d\n", m2);
		} else {
			// If X[i] is greater than m1, print m1 as the answer
			printf("%d\n", m1);
		}
	}
	// Free the memory allocated for X and Y arrays
	free(X);
	free(Y);
	return 0;
}

