#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to read an integer from input
int getInt() {
<<<<<<< HEAD
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read an array of integers from input
int* getIntArray(int n) {
=======
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read an array of integers from input
int* getIntSlice(int n) {
>>>>>>> 98c87cb78a (data updated)
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = getInt();
    }
    return arr;
}

// Main function containing the core logic of the program
int main() {
    // Read the number of elements
    int n = getInt();
    // Read the integer array from input
<<<<<<< HEAD
    int *ls = getIntArray(n);
=======
    int *ls = getIntSlice(n);
>>>>>>> 98c87cb78a (data updated)
    // Create a reversed copy of the original array
    int *lsRev = (int *)malloc(n * sizeof(int));
    memcpy(lsRev, ls, n * sizeof(int));
    
    // Sort the original array in ascending order
    qsort(ls, n, sizeof(int), compare);
    // Sort the reversed array in descending order
    qsort(lsRev, n, sizeof(int), compare);
    for (int i = 0; i < n / 2; i++) {
        int temp = lsRev[i];
        lsRev[i] = lsRev[n - 1 - i];
        lsRev[n - 1 - i] = temp;
    }

    // Initialize the answer variable
    long long ans = 0;
    // Iterate through all pairs of elements in the sorted array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Determine the minimum and maximum of the two selected elements
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the differences and sums needed for searching
            int x = q - p;
            int y = q + p;

            // Find the left boundary for elements greater than x
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (ls[mid] > x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int leftBoundary = l;

            // Find the right boundary for elements less than y
            l = 0;
            r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (lsRev[mid] < y) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int rightBoundary = n - l;

            // Calculate the number of valid elements in the range
            int sum = rightBoundary - leftBoundary;
            // Adjust the count if the current indices are within the range
            if (i >= leftBoundary && i < rightBoundary) {
                sum--;
            }
            if (j >= leftBoundary && j < rightBoundary) {
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
    printf("%lld\n", ans);

    // Free allocated memory
    free(ls);
    free(lsRev);

    return 0;
}

// <END-OF-CODE>
