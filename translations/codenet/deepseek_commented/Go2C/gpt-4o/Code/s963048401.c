#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from input
int intScanner() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to perform binary search to find the position to insert an element
int binarySearch(int *arr, int size, int key) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
<<<<<<< HEAD
    int mod = 1000000007; // Modulus value
    int n = intScanner(); // Read number of elements
    int *as = (int *)malloc(n * sizeof(int)); // Allocate memory for the array

    for (int i = 0; i < n; i++) {
        as[i] = intScanner(); // Read each element
=======
    int mod = 1000000007; // Modulus value (not used in this code)
    int n = intScanner(); // Read the number of elements
    int *as = (int *)malloc(n * sizeof(int)); // Allocate memory for the array

    for (int i = 0; i < n; i++) {
        as[i] = intScanner(); // Read each element into the array
>>>>>>> 98c87cb78a (data updated)
    }

    // Initialize xs with a maximum possible size
    int *xs = (int *)malloc(n * sizeof(int));
    int length = 0; // Length of the longest increasing subsequence

    for (int j = 0; j < n; j++) {
        // Use binary search to find the position to insert the current element
        int idx = binarySearch(xs, length, as[j]);
        if (idx == length) {
            // If the element is larger than all elements in xs, append it
            xs[length++] = as[j];
        } else {
            // Otherwise, replace the existing element at the found position
            xs[idx] = as[j];
        }
    }

    // Print the length of the longest increasing subsequence found
    printf("%d\n", length);

    // Free allocated memory
    free(as);
    free(xs);

    return 0;
}

// <END-OF-CODE>
