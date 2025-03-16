#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initializes a scanner to read from standard input and sets the split function to scan words.
int main() {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	int N;
	int i;
	int *X;
	int *Y;
	int m1;
	int m2;
	
	// Reads the number of elements N.
	read = getline(&line, &len, stdin);
	N = atoi(line);
	
	// Initializes slices X and Y to store N integers.
	X = (int *)malloc(N * sizeof(int));
	Y = (int *)malloc(N * sizeof(int));
	
	// Reads N integers into slice X and copies them to slice Y.
	for (i = 0; i < N; i++) {
	    read = getline(&line, &len, stdin);
	    X[i] = atoi(line);
	    Y[i] = X[i];
	}
	
	// Sorts slice Y in ascending order.
	qsort(Y, N, sizeof(int), compare);
	
	// Calculates the two middle values of the sorted slice Y.
	m1 = Y[N / 2 - 1];
	m2 = Y[N / 2];
	
	// For each element in slice X, prints the corresponding median value.
	for (i = 0; i < N; i++) {
	    if (X[i] <= m1) {
	        printf("%d\n", m2);
	    } else {
	        printf("%d\n", m1);
	    }
	}
	
	// Frees the memory allocated for slices X and Y.
	free(X);
	free(Y);
	
	// Frees the memory allocated for the line buffer.
	free(line);
	
	return 0;
}

// Helper function to compare two integers.
int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

// Helper function to scan and convert the next token from the scanner to an integer.
int ScanInt(char **line) {
	int i;
	
	// Scans the next token from the scanner.
	i = atoi(*line);
	
	// Advances the line buffer to the next token.
	*line = strchr(*line, ' ') + 1;
	
	return i;
}

// Helper function to scan and convert the next token from the scanner to a float64.
float ScanFloat64(char **line) {
	float f;
	
	// Scans the next token from the scanner.
	f = atof(*line);
	
	// Advances the line buffer to the next token.
	*line = strchr(*line, ' ') + 1;
	
	return f;
}

// Helper function to scan and return the next token from the scanner as a string.
char *ScanText(char **line) {
	char *token;
	
	// Scans the next token from the scanner.
	token = *line;
	
	// Advances the line buffer to the next token.
	*line = strchr(*line, ' ') + 1;
	
	return token;
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

