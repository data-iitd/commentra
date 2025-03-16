#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from the input
int ScanInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read a float64 from the input
double ScanFloat64() {
    double f;
    scanf("%lf", &f);
    return f;
}

// Function to read a text from the input
char* ScanText() {
    char* text = (char*)malloc(100 * sizeof(char));
    scanf("%s", text);
    return text;
}

// Function to find the maximum of two integers
int Max(int a, int b) {
    return a < b ? b : a;
}

// Function to find the minimum of two integers
int Min(int a, int b) {
    return a > b ? b : a;
}

// Function to find the absolute value of an integer
int Abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    // Initialize a scanner to read input from standard input
    int N = ScanInt();
    int X[N], Y[N];

    // Read N integers from the input and store them in X and Y arrays
    for (int i = 0; i < N; i++) {
        X[i] = ScanInt();
        // Store the current element of X in Y array for sorting
        Y[i] = X[i];
    }

    // Sort the Y array in ascending order
    qsort(Y, N, sizeof(int), (int (*)(const void*, const void*))compare);

    // Find the median of Y array
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];

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

    return 0;
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
