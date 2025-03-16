#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
}

int main() {
    int N;

    // Read input: number of values
    scanf("%d", &N);

    // Allocate memory for N float64 values
    double *values = (double *)malloc(N * sizeof(double));
    if (values == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read input: N float64 values
    for (int i = 0; i < N; i++) {
        scanf("%lf", &values[i]);
    }

    // Sort the array in ascending order
    qsort(values, N, sizeof(double), compare);

    // Calculate the median value
    double generated;
    // Iterate through the array, excluding the last value (which is the maximum)
    for (int i = 0; i < N - 1; i++) {
        // Calculate the average of the current and next value
        generated = (values[i] + values[i + 1]) / 2;

        // Update the next value with the calculated average
        values[i + 1] = generated;
    }

    // Print the calculated median value
    printf("%lf\n", generated);

    // Free allocated memory
    free(values);

    return 0;
}
