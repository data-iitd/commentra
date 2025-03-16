#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    int n;
    scanf("%d", &n);  // Input the number of elements (n)
    
    double *arr = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);  // Input the array elements
    }

    // Extract fractional parts
    double *frac_parts = (double *)malloc(n * sizeof(double));
    int count = 0;
    for (int i = 0; i < n; i++) {
        double frac = arr[i] - (int)arr[i];
        if (frac != 0) {
            frac_parts[count++] = frac;  // Store non-zero fractional parts
        }
    }

    // Sort the fractional parts
    qsort(frac_parts, count, sizeof(double), compare);

    // Calculate the number of elements to be added
    int o = 2 * n - count;

    // Sum of the sorted fractional parts
    double arr_sum = 0;
    for (int i = 0; i < count; i++) {
        arr_sum += frac_parts[i];
    }

    // Initialize the result variable to a very large number
    double res = 2e9;

    // Iterate to find the best position
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = fmin(res, fabs(i - arr_sum));
        }
    }

    // Print the result with three decimal places
    printf("%.3f\n", res);

    // Free allocated memory
    free(arr);
    free(frac_parts);

    return 0;
}

// <END-OF-CODE>
