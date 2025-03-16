#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Create a new scanner to read input from standard input
    int N;
    scanf("%d", &N);
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));

    // Read N integers into slice X and copy them to slice Y
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i];
    }

    // Sort the slice Y to find the median values
    qsort(Y, N, sizeof(int), compare);
    // Calculate the two middle values (medians) for even-sized arrays
    int m1 = Y[N / 2 - 1]; // First median
    int m2 = Y[N / 2];     // Second median

    // For each element in X, print the appropriate median based on its value
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            printf("%d\n", m2); // If X[i] is less than or equal to m1, print m2
        } else {
            printf("%d\n", m1); // Otherwise, print m1
        }
    }
    free(X);
    free(Y);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// ScanInt reads an integer from the scanner and returns it
int ScanInt(int *scanner) {
    scanf("%d", scanner); // Read the next token
    return *scanner; // Return the integer
}

// ScanFloat64 reads a float64 from the scanner and returns it
float ScanFloat64(float *scanner) {
    scanf("%f", scanner); // Read the next token
    return *scanner; // Return the float64
}

// ScanText reads a string from the scanner and returns it
char *ScanText(char *scanner) {
    scanf("%s", scanner); // Read the next token
    return scanner; // Return the string
}

// Max returns the maximum of two integers
int Max(int a, int b) {
    if (a < b) {
        return b; // Return b if a is less than b
    }
    return a; // Otherwise, return a
}

// Min returns the minimum of two integers
int Min(int a, int b) {
    if (a > b) {
        return b; // Return b if a is greater than b
    }
    return a; // Otherwise, return a
}

// Abs returns the absolute value of an integer
int Abs(int a) {
    if (a < 0) {
        a *= -1; // If a is negative, multiply by -1 to make it positive
    }
    return a; // Return the absolute value
}

