#include <stdio.h>  // For input and output functions
#include <stdlib.h> // For qsort function

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

int main() {
    int n; // Number of elements in the array
    scanf("%d", &n); // Reading the number of elements from the user

    // Allocating memory for the array
    long long *ans = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ans[i]); // Reading each element of the array
    }

    // Sorting the array in ascending order
    qsort(ans, n, sizeof(long long), compare);

    // Initializing a variable to keep track of the count
    long long count = ans[n - 1]; // The last element of the sorted array is the maximum element

    // Iterating through the array from the second last element to the first
    for (int i = n - 2; i >= 0; i--) {
        // If the current element is less than the next element, add it to the count
        if (ans[i] < ans[i + 1]) {
            count += ans[i];
        } else { // If the current element is greater than or equal to the next element
            // Decrement the current element until it becomes less than the next element
            while (ans[i] >= ans[i + 1]) {
                ans[i]--;
            }

            // If the current element is still greater than or equal to the next element, add it to the count
            if (ans[i] > 0) {
                count += ans[i];
            }
        }
    }

    // Printing the final count
    printf("%lld\n", count);

    // Freeing the allocated memory
    free(ans);

    return 0;
}
