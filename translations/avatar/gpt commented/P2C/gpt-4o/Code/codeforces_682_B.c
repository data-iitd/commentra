#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);  // Number of elements in the list

    // Allocate memory for the list of integers
    int *l = (int *)malloc(n * sizeof(int));

    // Read the list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);  // List of integers from input
    }

    // Sort the list to facilitate counting unique elements
    qsort(l, n, sizeof(int), compare);

    // Initialize a counter for unique elements
    int c = 0;  // Counter for unique elements

    // Iterate through the sorted list to count unique elements
    for (int i = 0; i < n; i++) {
        if (i == 0 || l[i] != l[i - 1]) {  // Check if the current element is different from the previous one
            c++;  // Increment the counter for unique elements
        }
    }

    // Output the total count of unique elements
    printf("%d\n", c);  // Print the count of unique elements

    // Free allocated memory
    free(l);

    return 0;
}

// <END-OF-CODE>
