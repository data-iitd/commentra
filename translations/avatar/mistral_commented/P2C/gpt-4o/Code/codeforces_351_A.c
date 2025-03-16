#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    // Take an integer input 'n' from the user
    int n;
    scanf("%d", &n);

    // Take 'n' floating point numbers as input and store them in a list 'arr'
    double *arr = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    // Filter out the integers from the list 'arr' and store the remaining floating point numbers
    double *filtered = (double *)malloc(n * sizeof(double));
    int count = 0;
    for (int i = 0; i < n; i++) {
        double fractional_part = arr[i] - (int)arr[i];
        if (fractional_part != 0) {
            filtered[count++] = fractional_part;
        }
    }

    // Sort the filtered array
    qsort(filtered, count, sizeof(double), compare);

    // Calculate the length of the filtered list 'arr' and assign it to the variable 'o'
    int o = 2 * n - count;

    // Calculate the sum of all the floating point numbers in the list 'arr' and assign it to the variable 'arr_sum'
    double arr_sum = 0;
    for (int i = 0; i < count; i++) {
        arr_sum += filtered[i];
    }

    // Initialize the variable 'res' with a large integer value
    double res = 2e9;

    // Iterate through the range from 0 to n+1
    for (int i = 0; i <= n; i++) {
        // Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
        if (i + o >= n) {
            // Update the minimum value of 'res' with the absolute difference between 'i' and 'arr_sum'
            res = fmin(res, fabs(i - arr_sum));
        }
    }

    // Print the result with three decimal places
    printf("%.3f\n", res);

    // Free allocated memory
    free(arr);
    free(filtered);

    return 0;
}

// <END-OF-CODE>
