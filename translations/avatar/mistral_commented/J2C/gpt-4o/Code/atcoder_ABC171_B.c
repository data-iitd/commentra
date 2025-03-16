#include <stdio.h>      // Include standard input/output library
#include <stdlib.h>     // Include standard library for memory allocation and sorting
#include <string.h>     // Include string library for string manipulation

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Main function to start the program
int main() {
    int n, k; // Variables for number of elements and number of summands

    // Read input: number of elements n and the number of summands k
    scanf("%d %d", &n, &k);

    // Allocate memory for the array a
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Read input array a of size n
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); // Read next element of array a
    }

    // Sort the array a using qsort
    qsort(a, n, sizeof(int), compare);

    // Calculate the answer: sum of first k elements of sorted array a
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }

    // Write the answer to the output
    printf("%d\n", ans);

    // Free allocated memory
    free(a);

    return 0; // Return success
}

// <END-OF-CODE>
