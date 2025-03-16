#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Main function
int main() {
    // Read the number of elements n and the number of queries m from standard input
    int n = readInt();
    int m = readInt();
    
    // Allocate an array a of size m
    int *a = (int *)malloc(m * sizeof(int));
    // Initialize a variable sum to keep track of the sum of elements in the array
    int sum = 0;

    // Process each query
    for (int i = 0; i < m; i++) {
        // Read an integer from standard input and add it to the array a
        a[i] = readInt();
        // Add the current element to the sum
        sum += a[i];
        // Check if the sum is greater than the size of the array
        if (sum > n) {
            // If so, print -1 and exit the program
            printf("-1\n");
            free(a); // Free allocated memory before exiting
            return 0;
        }
    }
    
    // Print the result, which is the difference between the size of the array and the sum of its elements
    printf("%d\n", n - sum);
    
    free(a); // Free allocated memory
    return 0;
}

// <END-OF-CODE>
