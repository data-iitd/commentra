#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Read the number of elements in the array
    int N;
    scanf("%d", &N);

    // Allocate memory for two arrays X and Y of size N
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));

    // Read N integers from the input and store them in X and Y arrays
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i]; // Store the current element of X in Y array for sorting
    }

    // Sort the Y array in ascending order
    qsort(Y, N, sizeof(int), compare);

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

    // Free allocated memory
    free(X);
    free(Y);

    return 0;
}

// Function to find the maximum of two integers
int Max(int a, int b) {
    return (a < b) ? b : a;
}

// Function to find the minimum of two integers
int Min(int a, int b) {
    return (a > b) ? b : a;
}

// Function to find the absolute value of an integer
int Abs(int a) {
    return (a < 0) ? -a : a;
}

// Function to read an integer from the input
int ScanInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read a float from the input
double ScanFloat64() {
    double f;
    scanf("%lf", &f);
    return f;
}

// Function to read a text from the input
char* ScanText() {
    char *text = (char *)malloc(100 * sizeof(char)); // Assuming max length of text is 99
    scanf("%s", text);
    return text;
}
