#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from input
int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a slice of integers from input
int* getIntSlice(int n) {
    int* is = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &is[i]);
    }
    return is;
}

// Function to print an integer
void puts(int a) {
    printf("%d\n", a);
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Main function to execute the core logic
void mainFn() {
    // Read the number of elements
    int n = getInt();
    // Read the integer slice from input
    int* ls = getIntSlice(n);
    // Create a reversed copy of the original slice
    int* lsRev = (int*)malloc(n * sizeof(int));
    memcpy(lsRev, ls, n * sizeof(int));
    // Sort the original slice in ascending order
    qsort(ls, n, sizeof(int), (int (*)(const void*, const void*))compareAsc);
    // Sort the reversed slice in descending order
    qsort(lsRev, n, sizeof(int), (int (*)(const void*, const void*))compareDesc);

    // Initialize the answer variable
    int ans = 0;
    // Iterate through all pairs of elements in the sorted slice
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Determine the minimum and maximum of the two selected elements
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the differences and sums needed for searching
            int x = q - p;
            int y = q + p;

            // Find the left boundary for elements greater than x
            int l = binarySearch(ls, n, x, compareAsc);
            // Find the right boundary for elements less than y
            int r = n - binarySearch(lsRev, n, y, compareDesc);

            // Calculate the number of valid elements in the range
            int sum = r - l;
            // Adjust the count if the current indices are within the range
            if ((i >= l) && (i <= r)) {
                sum--;
            }
            if ((j >= l) && (j <= r)) {
                sum--;
            }
            // Ensure the sum is non-negative
            sum = max(0, sum);
            // Accumulate the result
            ans += sum;
        }
    }

    // Divide the final answer by 3 as per the problem requirements
    ans /= 3;
    // Output the result
    puts(ans);

    // Free allocated memory
    free(ls);
    free(lsRev);
}

// Comparison function for ascending order
int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Comparison function for descending order
int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

// Binary search function
int binarySearch(int* arr, int n, int target, int (*compare)(const void*, const void*)) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (compare(&arr[mid], &target) < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// Main function to run the program
int main() {
    // Call the main function to execute the logic
    mainFn();
    return 0;
}
