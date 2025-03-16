#include <stdio.h>  // For standard I/O operations
#include <stdlib.h> // For memory allocation and conversion functions
#include <string.h> // For string manipulation functions

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n; // Number of elements
    scanf("%d", &n); // Read the number of elements
    int ar[3 * n]; // Create an array of size 3*n

    // Populate the array with integers from input
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &ar[i]);
    }

    // Sort the array
    qsort(ar, 3 * n, sizeof(int), compare);

    int sum = 0; // Initialize sum to 0
    for (int i = 0; i < n; i++) {
        sum += ar[3 * n - (i + 1) * 2]; // Calculate the sum of the last n elements, skipping every second element
    }

    printf("%d\n", sum); // Print the sum
    return 0; // Return success
}

// <END-OF-CODE>
