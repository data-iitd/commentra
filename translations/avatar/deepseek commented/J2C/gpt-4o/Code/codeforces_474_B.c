#include <stdio.h>

int fun(int arr[], int q, int n) {
    int res = 0;
    int i = 0, j = n - 1; // Adjusted j to n - 1 for zero-based indexing
    while (i <= j) {
        int md = i + (j - i) / 2;
        if (arr[md] == q) return md;
        else if (arr[md] > q) {
            res = md;
            j = md - 1;
        } else {
            i = md + 1;
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n); // Read the size of the array
    int arr[n]; // Declare the array

    scanf("%d", &arr[0]); // Initialize the first element of the array

    // Read the rest of the elements and calculate the prefix sum
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr[i] = x + arr[i - 1];
    }

    int m;
    scanf("%d", &m); // Read the number of queries
    int q[m]; // Declare the queries array

    // Read the queries
    for (int i = 0; i < m; i++) {
        scanf("%d", &q[i]);
    }

    // Perform binary search for each query and print the result adjusted by +1
    for (int k = 0; k < m; k++) {
        printf("%d\n", fun(arr, q[k], n) + 1);
    }

    return 0;
}

// <END-OF-CODE>
