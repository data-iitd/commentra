#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(int* a, int n) {
    // Allocate memory for the longest increasing subsequence
    int* b = (int*)malloc(n * sizeof(int));
    if (b == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize the length of the longest increasing subsequence
    int length = 0;

    // Iterate over each value in the input array a
    for (int i = 0; i < n; i++) {
        // Use binary search to find the index where a[i] can be placed in b
        int low = 0, high = length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (b[mid] < a[i]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        // If a[i] is greater than all elements in b, append it to b
        if (low == length) {
            b[length++] = a[i];
        } else {
            // Otherwise, replace the existing value at index low with a[i]
            b[low] = a[i];
        }
    }

    // Free the allocated memory for b
    free(b);

    // Return the length of the longest increasing subsequence
    return length;
}

int main() {
    // Read the number of elements from standard input
    int n;
    scanf("%d", &n);

    // Allocate memory for the input array a
    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Read n integers from standard input into the array a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the input array a using qsort
    qsort(a, n, sizeof(int), compare);

    // Find the length of the longest increasing subsequence
    int result = longestIncreasingSubsequence(a, n);

    // Output the length of the longest increasing subsequence
    printf("%d\n", result);

    // Free the allocated memory for a
    free(a);

    return 0;
}
