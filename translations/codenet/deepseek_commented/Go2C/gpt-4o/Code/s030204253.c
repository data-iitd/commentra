#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    int n; // Declare an integer variable to store the number of elements
    scanf("%d", &n); // Read the value of n from the standard input
    double *a = (double *)malloc(n * sizeof(double)); // Create a dynamic array of double with n elements
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]); // Read n floating-point numbers from the standard input to populate the array a
    }
    
<<<<<<< HEAD
    while (n > 1) { // Enter a loop that continues until only one element remains in the array a
=======
    while (n > 1) { // Continue until only one element remains in the array a
>>>>>>> 98c87cb78a (data updated)
        qsort(a, n, sizeof(double), compare); // Sort the array a in ascending order
        double *na = (double *)malloc((n - 1) * sizeof(double)); // Create a new array na to store the updated elements
        for (int j = 2; j < n; j++) { // Iterate over the array a starting from the third element
            na[j - 2] = a[j]; // Copy the elements from a to na, excluding the first two
        }
        na[n - 3] = (a[0] + a[1]) / 2; // Append the average of the first two elements to na
        free(a); // Free the old array a
        a = na; // Update the array a with the new array na
        n--; // Decrease the size of the array
    }
    
    printf("%lf\n", a[0]); // Print the single remaining element in the array a
<<<<<<< HEAD
    free(a); // Free the final array a
=======
    free(a); // Free the final array
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
