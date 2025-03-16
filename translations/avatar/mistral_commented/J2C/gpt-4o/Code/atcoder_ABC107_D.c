#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to solve the problem
int solve(int *arr, int n) {
    // Create a copy of the array for sorting
    int *sorted = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }

    // Sort the copy in ascending order
    qsort(sorted, n, sizeof(int), compare);

    long total = (long)n * (n + 1) / 2; // Calculate the total sum of elements from 1 to n^2

    int l = 0, r = n - 1; // Initialize left and right pointers for binary search

    while (l < r) {
        int mid = l + (r - l) / 2; // Calculate the middle index
        int target = sorted[mid]; // The middle element is the target for this iteration

        int cur = 0; // Initialize current sum
        long cnt = 0; // Initialize count of elements less than or equal to target

        long *bit = (long *)calloc(2 * n + 2, sizeof(long)); // Bitmap array for fast counting

        // Initialize the bitmap array
        for (int x = n + 1; x < 2 * n + 2; x += x & -x) {
            bit[x]++; // Increment the count for the current position
        }

        // Process each element in the original array
        for (int i = 0; i < n; i++) {
            cur += arr[i] <= target ? 1 : -1; // Increment the current sum if the element is less than or equal to target
            for (int x = cur + n + 1; x < 2 * n + 2; x += x & -x) {
                bit[x]++; // Increment the count for the current position
            }
            for (int x = cur + n; x > 0; x -= x & -x) {
                cnt += bit[x]; // Add the count of elements with sum less than or equal to current sum
            }
        }

        if (cnt >= total / 2 + 1) { // If the count is greater than half the total sum
            r = mid; // Narrow the search range to the left
        } else {
            l = mid + 1; // Narrow the search range to the right
        }
    }

    free(sorted); // Free the allocated memory for sorted array
    free(bit); // Free the allocated memory for bitmap array

    // Return the middle element as the answer
    return sorted[l];
}

int main() {
    // Read the number of elements in the array
    int N;
    scanf("%d", &N);

    // Allocate memory for the array
    int *arr = (int *)malloc(N * sizeof(int));

    // Read the elements of the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]); // Read an element
    }

    // Call the solve function and print the result
    printf("%d\n", solve(arr, N)); // Print the result

    free(arr); // Free the allocated memory for the array
    return 0;
}

// <END-OF-CODE>
