#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int n, k, t; // n: number of elements, k: size of the subset, t: temporary variable for input
int* vec; // Vector to store the input elements
int ans = 1000000001; // Initialize ans to a large value to find the minimum difference

int main() {
    // Read the number of elements (n) and the size of the subset (k)
    scanf("%d %d", &n, &k);

    // Allocate memory for the vector
    vec = (int*)malloc(n * sizeof(int));

    // Read n integers from input and store them in the vector
    for (int i = 0; i < n; i++) {
        scanf("%d", &t); // Read each integer
        vec[i] = t; // Add the integer to the vector
    }

    // Sort the vector in non-decreasing order
    qsort(vec, n, sizeof(int), (int (*)(const void*, const void*))compare);

    // Iterate through the sorted vector to find the minimum difference
    for (int i = 0; i + k - 1 < n; i++) {
        // Calculate the difference between the maximum and minimum of the current subset of size k
        int diff = vec[i + k - 1] - vec[i];
        
        // Update the minimum difference found so far
        if (diff < ans) {
            ans = diff; // Update ans if a smaller difference is found
        }
    }

    // Output the minimum difference found
    printf("%d\n", ans);

    // Free the allocated memory
    free(vec);

    return 0; // Return 0 to indicate successful completion
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
