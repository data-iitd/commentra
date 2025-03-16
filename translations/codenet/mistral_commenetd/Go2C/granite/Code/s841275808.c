

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize a scanner to read input from standard input
    FILE *fp = stdin;
    char buf[1024];
    int N;
    fgets(buf, sizeof(buf), fp);
    sscanf(buf, "%d", &N);

    // Allocate memory for two arrays X and Y of size N
    int *X = (int *)malloc(sizeof(int) * N);
    int *Y = (int *)malloc(sizeof(int) * N);

    // Read N integers from the input and store them in X and Y arrays
    for (int i = 0; i < N; i++) {
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "%d", &X[i]);
        // Store the current element of X in Y array for sorting
        Y[i] = X[i];
    }

    // Sort the Y array in ascending order
    qsort(Y, N, sizeof(int), compare);

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

    // Free the allocated memory
    free(X);
    free(Y);

    return 0;
}

// Function to compare two integers for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to read an integer from the input
int ScanInt(FILE *fp) {
    char buf[1024];
    int i;
    fgets(buf, sizeof(buf), fp);
    sscanf(buf, "%d", &i);
    return i;
}

// Function to read a float64 from the input
double ScanFloat64(FILE *fp) {
    char buf[1024];
    double f;
    fgets(buf, sizeof(buf), fp);
    sscanf(buf, "%lf", &f);
    return f;
}

// Function to read a text from the input
char *ScanText(FILE *fp) {
    char buf[1024];
    fgets(buf, sizeof(buf), fp);
    char *text = (char *)malloc(strlen(buf) + 1);
    strcpy(text, buf);
    return text;
}

// Function to find the maximum of two integers
int Max(int a, int b) {
    return (a > b)? a : b;
}

// Function to find the minimum of two integers
int Min(int a, int b) {
    return (a < b)? a : b;
}

// Function to find the absolute value of an integer
int Abs(int a) {
    return (a < 0)? -a : a;
}

// Translate the above C code to Python and end with comment "