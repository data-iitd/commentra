#include <stdio.h>
#include <stdlib.h>

// Function to compare two float values for qsort
int compare(const void *a, const void *b) {
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

int main() {
    // Initialize an integer variable 'n' and read its value from the standard input
    int n;
    scanf("%d", &n);

    // Create an array 'a' of 'n' float elements
    float *a = (float *)malloc(n * sizeof(float));

    // Read 'n' float values from the standard input and assign them to the array 'a'
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    // Sort the array 'a' using qsort
    qsort(a, n, sizeof(float), compare);

    // Initialize an empty array 'na' with a maximum size of 'n'
    float *na = (float *)malloc(n * sizeof(float));
    int na_size = 0;

    // Iterate through the array 'a' starting from index 2 and append its elements to the array 'na'
    for (int j = 2; j < n; j++) {
        na[na_size++] = a[j];
    }

    // Reassign the value of the array 'na' with the first two elements being the average of the first two elements of the original array 'a'
    na[na_size++] = (a[0] + a[1]) / 2;

    // Print the first element of the sorted array 'na' to the standard output
    printf("%f\n", na[0]);

    // Free allocated memory
    free(a);
    free(na);

    return 0;
}

// <END-OF-CODE>
