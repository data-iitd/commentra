#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    // Read the number of elements from standard input
    int n;
    scanf("%d", &n);

    // Initialize an array to hold the float64 numbers
    double *a = (double *)malloc(n * sizeof(double));

    // Read n float64 numbers from standard input into the array
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    // Perform a series of operations to reduce the array
    for (int i = 0; i + 1 < n; i++) {
        // Sort the array in ascending order
        qsort(a, n, sizeof(double), compare);

        // Create a new array to hold the modified values
        double *na = (double *)malloc((n - 1) * sizeof(double));

        // Append all elements from the third element onward to the new array
        for (int j = 2; j < n; j++) {
            na[j - 2] = a[j];
        }

        // Calculate the average of the first two elements and append it to the new array
        na[n - 3] = (a[0] + a[1]) / 2;

        // Update the original array to be the new array
        free(a);
        a = na;
        n--; // Reduce the size of the array
    }

    // Print the final remaining element in the array
    printf("%lf\n", a[0]);

    // Free the allocated memory
    free(a);
    return 0;
}

// <END-OF-CODE>
