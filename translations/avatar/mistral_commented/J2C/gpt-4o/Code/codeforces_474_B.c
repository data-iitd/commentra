#include <stdio.h>  // Including standard I/O library
#include <stdlib.h> // Including standard library for dynamic memory allocation

// Function prototype for the binary search function
int fun(int arr[], int q, int n);

int main() {
    int n; // Number of elements in the array
    scanf("%d", &n); // Reading the number of elements from input
    int *arr = (int *)malloc(n * sizeof(int)); // Dynamically allocating memory for the array
    scanf("%d", &arr[0]); // Reading the first element of the array

    // Loop to read and store the remaining elements of the array
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x); // Reading an element from input
        arr[i] = x + arr[i - 1]; // Storing the cumulative sum in the array
    }

    int m; // Number of queries
    scanf("%d", &m); // Reading the number of queries from input
    int *q = (int *)malloc(m * sizeof(int)); // Dynamically allocating memory for the queries

    // Loop to read and store the queries
    for (int i = 0; i < m; i++) {
        scanf("%d", &q[i]); // Reading a query from input
    }

    // Loop to process each query and print the result
    for (int k = 0; k < m; k++) {
        printf("%d\n", fun(arr, q[k], n) + 1); // Calling the fun function and printing the result with an offset of 1
    }

    // Freeing the allocated memory
    free(arr);
    free(q);

    return 0; // Returning 0 to indicate successful execution
}

// Function to perform binary search on the array
int fun(int arr[], int q, int n) {
    int res = 0; // Variable to store the result
    int i = 0, j = n - 1; // Initializing left and right indices

    // While loop to perform binary search
    while (i <= j) {
        int md = i + (j - i) / 2; // Calculating the middle index
        if (arr[md] == q) { // If the middle element is equal to the query
            return md; // Return the middle index
        } else if (arr[md] > q) { // If the middle element is greater than the query
            res = md; // Update the result
            j = md - 1; // Shift the right index
        } else { // If the middle element is less than the query
            i = md + 1; // Shift the left index
        }
    }

    // If the query is not present, return the index where it should be inserted
    return res;
}
