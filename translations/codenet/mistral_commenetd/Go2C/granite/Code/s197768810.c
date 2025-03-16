

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the scanner to read words as input
    int n, m;
    scanf("%d %d", &n, &m);
    // Allocate an array a of size n
    int *a = (int *)malloc(n * sizeof(int));
    // Initialize a variable sum to keep track of the sum of elements in the array
    int sum = 0;
    // Process each query
    for (int i = 0; i < m; i++) {
        // Read an integer from standard input and add it to the array a
        scanf("%d", &a[i]);
        // Add the current element to the sum
        sum += a[i];
        // Check if the sum is greater than the size of the array
        if (sum > n) {
            // If so, print -1 and exit the program
            printf("-1\n");
            return 0;
        }
    }
    // Print the result, which is the difference between the size of the array and the sum of its elements
    printf("%d\n", n - sum);
    // Free the memory allocated for the array a
    free(a);
    return 0;
}
