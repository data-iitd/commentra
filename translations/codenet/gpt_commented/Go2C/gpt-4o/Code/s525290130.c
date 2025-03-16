#include <stdio.h>
#include <stdlib.h>

// Function to reverse a segment of an array in place
void reva(int *b, int start, int end) {
    for (int i = 0; i < (end - start) / 2; i++) {
        // Swap the elements at positions start + i and end - 1 - i
        int temp = b[start + i];
        b[start + i] = b[end - 1 - i];
        b[end - 1 - i] = temp;
    }
}

int main() {
    int n, q;

    // Read the number of elements in the array
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int)); // Allocate memory for the array

    // Populate the array with integers from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read each integer and store it in the array
    }

    // Read the number of queries
    scanf("%d", &q);
    // Process each query
    for (int i = 0; i < q; i++) {
        int b, e;
        scanf("%d %d", &b, &e); // Read the starting and ending indices for the reversal
        reva(a, b, e); // Reverse the segment of the array from index b to e
    }

    // Output the modified array
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" "); // Print a space before each element except the first
        }
        printf("%d", a[i]); // Print the current element
    }
    printf("\n"); // Print a newline after the output

    free(a); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
