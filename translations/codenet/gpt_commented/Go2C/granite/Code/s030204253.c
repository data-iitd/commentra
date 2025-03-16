
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Read the number of elements from standard input
    int n;
    scanf("%d", &n);

    // Initialize a dynamic array to hold the float64 numbers
    double *a = (double *)malloc(n * sizeof(double));

    // Read n float64 numbers from standard input into the dynamic array
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    // Perform a series of operations to reduce the dynamic array
    for (int i = 0; i + 1 < n; i++) {
        // Sort the dynamic array in ascending order
        qsort(a, n, sizeof(double), cmpfunc);

        // Create a new dynamic array to hold the modified values
        double *na = (double *)malloc((n - 1) * sizeof(double));

        // Copy all elements from the third element onward to the new dynamic array
        for (int j = 2; j < n; j++) {
            na[j - 2] = a[j];
        }

        // Calculate the average of the first two elements and append it to the new dynamic array
        na[n - 2] = (a[0] + a[1]) / 2;

        // Free the memory allocated for the original dynamic array
        free(a);

        // Update the original dynamic array to be the new dynamic array
        a = na;
        n = n - 1;
    }

    // Print the final remaining element in the dynamic array
    printf("%.1f\n", a[0]);

    // Free the memory allocated for the dynamic array
    free(a);

    return 0;
}

// Compare function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(double *)a - *(double *)b);
}

// Translate the above C code to Python and end with comment "