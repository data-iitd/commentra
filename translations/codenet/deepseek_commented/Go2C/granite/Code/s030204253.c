
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // Declare an integer variable to store the number of elements
    scanf("%d", &n); // Read the value of n from the standard input
    double *a = (double *)malloc(n * sizeof(double)); // Allocate memory for a slice of double with n elements
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]); // Read n floating-point numbers from the standard input to populate the slice a
    }
    for (int i = 0; i + 1 < n; i++) { // Enter a loop that continues until only one element remains in the slice a
        qsort(a, n, sizeof(double), cmpfunc); // Sort the slice a in ascending order using the qsort function
        double *na = (double *)malloc((n - 2) * sizeof(double)); // Allocate memory for a new slice na to store the updated elements
        int j = 2; // Initialize the index j to 2
        while (j < n) { // Iterate over the slice a starting from the third element
            na[j - 2] = a[j]; // Copy the elements from a to na, excluding the first two
            j++;
        }
        na[n - 3] = (a[0] + a[1]) / 2; // Calculate the average of the first two elements and store it in na
        free(a); // Free the memory allocated for the original slice a
        a = na; // Update the slice a with the new slice na
        n = n - 2; // Update the number of elements in the slice a
    }
    printf("%.1lf\n", a[0]); // Print the single remaining element in the slice a
    free(a); // Free the memory allocated for the final slice a
    return 0;
}

int cmpfunc(const void *a, const void *b) { // Define a comparison function for sorting the slice a
    if (*(double *)a < *(double *)b) {
        return -1;
    } else if (*(double *)a > *(double *)b) {
        return 1;
    } else {
        return 0;
    }
}

