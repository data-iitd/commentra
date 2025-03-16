#include <stdio.h>

int fun(int arr[], int q, int n) {
    int res = 0; // Variable to store the result index
    int i = 0, j = n - 1; // Initialize pointers for binary search

    // Perform binary search to find the appropriate index
    while (i <= j) {
        int md = i + (j - i) / 2; // Calculate the mid index

        // If the middle element is equal to the query, return the index
        if (arr[md] == q)
            return md;
        // If the middle element is greater than the query, adjust the search range
        else if (arr[md] > q) {
            res = md; // Update result to the current mid index
            j = md - 1; // Move the end pointer left
        } else
            i = md + 1; // Move the start pointer right
    }

    // Return the last found index where the cumulative sum is less than the query
    return res;
}

int main() {
    // Create a variable to read the number of elements in the array
    int n;
    scanf("%d", &n);

    // Initialize the array to store cumulative sums
    int arr[n];

    // Read the first element and assign it to the first index of the array
    scanf("%d", &arr[0]);

    // Populate the array with cumulative sums
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr[i] = x + arr[i - 1];
    }

    // Read the number of queries
    int m;
    scanf("%d", &m);

    // Process each query and print the result
    for (int k = 0; k < m; k++) {
        int q;
        scanf("%d", &q);
        printf("%d\n", fun(arr, q, n) + 1);
    }

    return 0;
}

// <END-OF-CODE>
