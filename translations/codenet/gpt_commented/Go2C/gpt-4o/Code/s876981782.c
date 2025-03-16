#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    // Read the number of values to be processed
    int N;
    scanf("%d", &N);

    // Initialize an array to hold the float64 values
    double *values = (double *)malloc(N * sizeof(double));

    // Read N float64 values from standard input
    for (int i = 0; i < N; i++) {
        scanf("%lf", &values[i]);
    }

    // Sort the array of float64 values in ascending order
    qsort(values, N, sizeof(double), compare);

    // Variable to hold the generated average value
    double generated;

    // Calculate the average of each pair of adjacent values
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2;
        // Update the next value in the array with the generated average
        values[i + 1] = generated;
    }

    // Print the last generated average value
    printf("%lf\n", generated);

    // Free the allocated memory
    free(values);

    return 0;
}

// <END-OF-CODE>
