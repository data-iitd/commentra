

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Initialize variables
    int N;

    // Read input: number of values
    scanf("%d", &N);

    // Allocate memory for N float values
    float *values = (float *)malloc(N * sizeof(float));

    // Read input: N float values
    for (int i = 0; i < N; i++) {
        scanf("%f", &values[i]);
    }

    // Sort the array in ascending order
    qsort(values, N, sizeof(float), cmpfunc);

    // Calculate the median value
    float generated = 0;
    // Iterate through the array, excluding the last value (which is the maximum)
    for (int i = 0; i < N - 1; i++) {
        // Calculate the average of the current and next value
        generated = (values[i] + values[i + 1]) / 2;

        // Update the next value with the calculated average
        values[i + 1] = generated;
    }

    // Print the calculated median value
    printf("%f\n", generated);

    // Free the allocated memory
    free(values);

    return 0;
}

// Function to compare two float values for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(float *)a - *(float *)b);
}

