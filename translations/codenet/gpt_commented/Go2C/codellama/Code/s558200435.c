#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the number of elements from standard input
    int n;
    scanf("%d", &n);

    // Initialize a slice to hold the input integers
    int *a = (int *)malloc(n * sizeof(int));
    // Read n integers from standard input into the slice a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize a slice b to hold the longest increasing subsequence
    int *b = (int *)malloc(n * sizeof(int));
    // Iterate over each value in the input slice a
    for (int i = 0; i < n; i++) {
        // Use binary search to find the index where v can be placed in b
        int x = 0;
        while (x < n && b[x] < a[i]) {
            x++;
        }
        // If v is greater than all elements in b, append it to b
        if (x == n) {
            b[n] = a[i];
        } else {
            // Otherwise, replace the existing value at index x with v
            b[x] = a[i];
        }
    }

    // Output the length of the longest increasing subsequence
    printf("%d\n", n);

    // Free the memory allocated for the slices
    free(a);
    free(b);

    return 0;
}

