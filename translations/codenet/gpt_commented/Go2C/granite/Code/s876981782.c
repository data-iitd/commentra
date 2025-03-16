
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of values to be processed
    int N;
    scanf("%d", &N);

    // Initialize an array to hold the float values
    float *values = (float *)malloc(N * sizeof(float));

    // Read N float values from standard input
    for (int i = 0; i < N; i++) {
        scanf("%f", &values[i]);
    }

    // Sort the array of float values in ascending order
    qsort(values, N, sizeof(float), cmpfunc);

    // Variable to hold the generated average value
    float generated;

    // Calculate the average of each pair of adjacent values
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2;
        // Update the next value in the array with the generated average
        values[i + 1] = generated;
    }

    // Print the last generated average value
    printf("%f\n", generated);

    // Free the allocated memory
    free(values);

    return 0;
}

// Function to compare two float values for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(float *)a - *(float *)b);
}

