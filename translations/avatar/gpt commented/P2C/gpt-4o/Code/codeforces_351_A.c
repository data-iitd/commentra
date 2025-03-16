#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    // Read an integer input for the number of elements
    int n;
    scanf("%d", &n);

    // Read a line of space-separated floats and convert them to an array of floats
    double *arr = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    // Calculate the fractional parts of the elements, excluding whole numbers
    double *frac_parts = (double *)malloc(n * sizeof(double));
    int frac_count = 0;
    for (int i = 0; i < n; i++) {
        double frac = arr[i] - (int)arr[i];
        if (frac != 0) {
            frac_parts[frac_count++] = frac;
        }
    }

    // Sort the fractional parts
    qsort(frac_parts, frac_count, sizeof(double), compare);

    // Calculate the number of whole numbers that can be added to the fractional parts
    int o = 2 * n - frac_count;

    // Calculate the sum of the fractional parts
    double arr_sum = 0;
    for (int i = 0; i < frac_count; i++) {
        arr_sum += frac_parts[i];
    }

    // Initialize the result with a large number
    double res = 2e9;

    // Iterate through possible counts of fractional parts used
    for (int i = 0; i <= n; i++) {
        // Check if the current count of fractional parts plus whole numbers is sufficient
        if (i + o >= n) {
            // Update the result with the minimum difference found
            res = fmin(res, fabs(i - arr_sum));
        }
    }

    // Print the result formatted to three decimal places
    printf("%.3f\n", res);

    // Free allocated memory
    free(arr);
    free(frac_parts);

    return 0;
}

// <END-OF-CODE>
