#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper functions to find the minimum and maximum of two integers.
int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

// Function to read an integer from standard input.
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a slice of integers from standard input.
int* readIntSlice(int n) {
    int* slice = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &slice[i]);
    }
    return slice;
}

// Main logic of the program.
void mainFn() {
    // Get the number of elements in the slice.
    int n = readInt();
    // Get the slice of integers.
    int* ls = readIntSlice(n);
    // Create a reversed version of the slice.
    int* lsRev = (int*)malloc(n * sizeof(int));
    memcpy(lsRev, ls, n * sizeof(int));
    // Sort the original slice in ascending order.
    qsort(ls, n, sizeof(int), (int (*)(const void*, const void*))compare);
    // Sort the reversed slice in descending order.
    qsort(lsRev, n, sizeof(int), (int (*)(const void*, const void*))reverseCompare);

    // Initialize the answer variable.
    int ans = 0;
    // Loop through the slice to calculate the answer.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate p and q based on the current elements.
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate x and y based on p and q.
            int x = q - p;
            int y = q + p;

            // Find the left boundary using binary search.
            int l = binarySearch(ls, n, x);
            // Find the right boundary using binary search.
            int r = n - binarySearch(lsRev, n, y);

            // Calculate the sum of valid pairs.
            int sum = r - l;
            // Adjust the sum if the current indices are within the range.
            if ((i >= l) && (i <= r)) {
                sum--;
            }
            if ((j >= l) && (j <= r)) {
                sum--;
            }
            // Ensure the sum is not negative.
            sum = sum > 0 ? sum : 0;
            // Add the sum to the answer.
            ans += sum;
        }
    }

    // Divide the answer by 3 to get the final result.
    ans /= 3;
    // Print the final answer.
    printf("%d\n", ans);

    // Free allocated memory.
    free(ls);
    free(lsRev);
}

// Comparator function for ascending order.
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Comparator function for descending order.
int reverseCompare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

// Binary search function.
int binarySearch(int* arr, int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// Main function to initialize the program.
int main() {
    mainFn();
    return 0;
}
