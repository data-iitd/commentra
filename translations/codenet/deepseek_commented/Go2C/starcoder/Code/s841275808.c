#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Initializes a scanner to read from standard input and sets the split function to scan words.
int main() {
	int N;
	scanf("%d", &N);
	
	int X[N], Y[N];
	
	// Reads N integers into slice X and copies them to slice Y.
	for (int i = 0; i < N; i++) {
	    scanf("%d", &X[i]);
	    Y[i] = X[i];
	}
	
	// Sorts slice Y in ascending order.
	qsort(Y, N, sizeof(int), compare);
	
	// Calculates the two middle values of the sorted slice Y.
	int m1 = Y[N / 2 - 1];
	int m2 = Y[N / 2];
	
	// For each element in slice X, prints the corresponding median value.
	for (int i = 0; i < N; i++) {
	    if (X[i] <= m1) {
	        printf("%d\n", m2);
	    } else {
	        printf("%d\n", m1);
	    }
	}
	
}

// Helper function to compare two integers.
int compare(const void *a, const void *b) {
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y) {
		return -1;
	} else if (x > y) {
		return 1;
	} else {
		return 0;
	}
}

// Helper function to scan and convert the next token from the scanner to an integer.
int ScanInt(int *i) {
	scanf("%d", i);
}

// Helper function to scan and convert the next token from the scanner to a float64.
float64 ScanFloat64(float64 *f) {
	scanf("%lf", f);
}

// Helper function to scan and return the next token from the scanner as a string.
char *ScanText(char *s) {
	scanf("%s", s);
}

// Helper function to return the maximum of two integers.
int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Helper function to return the minimum of two integers.
int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Helper function to return the absolute value of an integer.
int Abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

