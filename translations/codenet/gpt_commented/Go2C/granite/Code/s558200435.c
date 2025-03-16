
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements from standard input
    int n;
    scanf("%d", &n);

    // Initialize a dynamically allocated array to hold the input integers
    int *a = (int *)malloc(n * sizeof(int));
    // Read n integers from standard input into the array a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize a dynamically allocated array b to hold the longest increasing subsequence
    int *b = (int *)malloc(n * sizeof(int));
    int b_size = 0;
    // Iterate over each value in the input array a
    for (int i = 0; i < n; i++) {
        // Use binary search to find the index where a[i] can be placed in b
        int x = 0;
        int y = b_size;
        while (x < y) {
            int m = (x + y) / 2;
            if (b[m] < a[i]) {
                x = m + 1;
            } else {
                y = m;
            }
        }
        // If a[i] is greater than all elements in b, append it to b
        if (x == b_size) {
            b = (int *)realloc(b, (b_size + 1) * sizeof(int));
            b[b_size] = a[i];
            b_size++;
        } else {
            // Otherwise, replace the existing value at index x with a[i]
            b[x] = a[i];
        }
    }

    // Output the length of the longest increasing subsequence
    printf("%d\n", b_size);

    // Free the dynamically allocated memory
    free(a);
    free(b);

    return 0;
}
