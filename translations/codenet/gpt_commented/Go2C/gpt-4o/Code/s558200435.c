#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
int binary_search(int *b, int len, int v) {
    int left = 0, right = len;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (b[mid] < v) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

=======
>>>>>>> 98c87cb78a (data updated)
int main() {
    // Read the number of elements from standard input
    int n;
    scanf("%d", &n);

    // Initialize an array to hold the input integers
    int *a = (int *)malloc(n * sizeof(int));
    // Read n integers from standard input into the array a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

<<<<<<< HEAD
    // Initialize an array b to hold the longest increasing subsequence
=======
    // Initialize an array to hold the longest increasing subsequence
>>>>>>> 98c87cb78a (data updated)
    int *b = (int *)malloc(n * sizeof(int));
    int b_len = 0;

    // Iterate over each value in the input array a
    for (int i = 0; i < n; i++) {
        int v = a[i];
        // Use binary search to find the index where v can be placed in b
<<<<<<< HEAD
        int x = binary_search(b, b_len, v);
        // If v is greater than all elements in b, append it to b
        if (x == b_len) {
            b[b_len++] = v;
        } else {
            // Otherwise, replace the existing value at index x with v
            b[x] = v;
=======
        int left = 0, right = b_len;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (b[mid] < v) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // If v is greater than all elements in b, append it to b
        if (left == b_len) {
            b[b_len++] = v;
        } else {
            // Otherwise, replace the existing value at index left with v
            b[left] = v;
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Output the length of the longest increasing subsequence
    printf("%d\n", b_len);

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}

// <END-OF-CODE>
