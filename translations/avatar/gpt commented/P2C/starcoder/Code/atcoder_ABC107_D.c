#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a certain value X can be achieved
bool check(int *a, int n, int X) {
    // Create a new list b where each element indicates if the corresponding a[i] is >= X
    int *b = (int *) malloc(sizeof(int) * (n + 1));
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + ((a[i] >= X) * 2 - 1);
    }
    int c = b[0];  // Find the minimum value in b
    for (int i = 0; i < n + 1; i++) {
        b[i] -= c;  // Normalize b by subtracting the minimum value
    }
    int *bit = (int *) malloc(sizeof(int) * (b[n] + 2));  // Initialize a BIT for the range of b
    memset(bit, 0, sizeof(int) * (b[n] + 2));
    int ans = 0;  // Initialize the answer counter
    // Count the number of valid pairs using the BIT
    for (int i = 0; i < n + 1; i++) {
        ans += bit[b[i] + 1];  // Count how many indices have been added that are less than b[i]
        bit[b[i]]++;  // Add the current index to the BIT
    }
    return ans >= X * (n - 1) / 2;  // Return whether the count is at least X * (n - 1) / 2
}

// Function to perform binary search to find the maximum value that satisfies the condition
int binary_search(int *a, int n) {
    int t[2] = {n, 0};  // Initialize the binary search bounds
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;  // Calculate the midpoint
        t[check(a, n, mid)] = mid;  // Update the bounds based on the check function
    }
    return a[t[1]];  // Return the found index
}

// Main function
int main() {
    int n;  // Read the number of elements
    scanf("%d", &n);
    int m = n * (n + 1) / 4;  // Calculate the target value m based on the number of elements
    int *a = (int *) malloc(sizeof(int) * n);  // Read the input array and convert it to a list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int *d = (int *) malloc(sizeof(int) * (n + 1));  // Dictionary to hold the mapping of values to their indices
    // Create a sorted list of unique values from a, including 0
    int _a[n + 1];
    _a[0] = 0;
    for (int i = 0; i < n; i++) {
        _a[i + 1] = a[i];
    }
    qsort(_a, n + 1, sizeof(int), (int (*)(const void *, const void *)) & (int (*)(int, int)) (lambda(int, int) {
        return (a > b) - (a < b);
    }));
    // Map original values to their indices in the sorted list
    for (int i = 0; i < n + 1; i++) {
        d[i] = bsearch(_a, n + 1, _a[i], sizeof(int), (int (*)(const void *, const void *)) & (int (*)(int, int)) (lambda(int, int) {
            return (a > b) - (a < b);
        }));
    }
    // Replace original values in a with their corresponding indices
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }
    printf("%d\n", binary_search(a, n));  // Print the result corresponding to the found index
    return 0;
}

