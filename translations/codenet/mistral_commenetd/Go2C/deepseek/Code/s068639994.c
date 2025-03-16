#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read an array of integers from standard input
int* getIntSlice(int n) {
    int* is = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &is[i]);
    }
    return is;
}

// Function to write an integer to standard output
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

// Main function to execute the program
void mainFn() {
    // Get the number of elements in the input array
    int n = getInt();
    // Get the input array
    int* ls = getIntSlice(n);
    // Create a reversed copy of the input array
    int* lsRev = (int*)malloc(n * sizeof(int));
    memcpy(lsRev, ls, n * sizeof(int));
    // Sort the input array in ascending order
    qsort(ls, n, sizeof(int), (int (*)(const void*, const void*))compareAsc);
    // Sort the reversed copy of the array in descending order
    qsort(lsRev, n, sizeof(int), (int (*)(const void*, const void*))compareDesc);

    // Initialize the answer variable
    int ans = 0;
    // Iterate through all pairs of elements in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Find the minimum and maximum elements of the current pair
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the difference between the maximum and minimum elements
            int x = q - p;
            int y = q + p;
            // Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
            int l = binarySearch(ls, n, x, compareAsc);
            int r = n - binarySearch(lsRev, n, y, compareDesc);
            // Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
            int sum = r - l;
            // Check if the current pair lies within the range [l, r]
            if (i >= l && i <= r) {
                sum--;
            }
            if (j >= l && j <= r) {
                sum--;
            }
            // Ensure that the sum is not negative
            sum = max(0, sum);
            // Add the sum to the answer variable
            ans += sum;
        }
    }
    // Divide the answer by 3 and print it
    ans /= 3;
    puts(ans);
    // Free allocated memory
    free(ls);
    free(lsRev);
}

// Comparator function for ascending order
int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Comparator function for descending order
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
    mainFn();
    return 0;
}
