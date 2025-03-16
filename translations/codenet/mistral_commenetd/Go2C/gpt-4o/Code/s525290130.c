// Importing necessary libraries
#include <stdio.h>
#include <stdlib.h>

// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
void reva(int *b, int length) {
    // Reverse the subarray using a simple method of swapping elements
    for (int i = 0; i < length / 2; i++) {
        int temp = b[i];
        b[i] = b[length - 1 - i];
        b[length - 1 - i] = temp;
    }
}

// Main function
int main() {
    // Read the number of elements in the array 'a'
    int n;
    scanf("%d", &n);
    
    // Allocate memory for the array 'a' of size 'n'
    int *a = (int *)malloc(n * sizeof(int));

    // Read 'n' integers from the standard input and store them in the array 'a'
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read the number of queries 'q'
    int q;
    scanf("%d", &q);

    // Process each query by reversing the subarray of 'a'
    for (int i = 0; i < q; i++) {
        // Read the starting and ending indices of the subarray to be reversed
        int b, e;
        scanf("%d %d", &b, &e);

        // Reverse the subarray 'a[b:e]'
        reva(&a[b], e - b + 1);
    }

    // Write the reversed array 'a' to the standard output
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(a);

    return 0;
}

// <END-OF-CODE>
