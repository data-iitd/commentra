#include <stdio.h>
#include <stdlib.h>

int fun(int arr[], int q, int n, int m) {
    int res = 0;
    int i = 0, j = n;
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
    int n, m;
    scanf("%d", &n); // Read the size of the array
    int arr[n];
    arr[0] = 0; // Initialize the first element of the array

    // Read the rest of the elements and calculate the prefix sum
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr[i] = x + arr[i - 1];
    }

    scanf("%d", &m); // Read the number of queries
    int q[m];

    // Read the queries
    for (int i = 0; i < m; i++) {
        scanf("%d", &q[i]);
    }

    // Perform binary search for each query and print the result adjusted by +1
    for (int k = 0; k < m; k++) {
        printf("%d\n", fun(arr, q[k], n, m) + 1);
    }

    return 0;
}

