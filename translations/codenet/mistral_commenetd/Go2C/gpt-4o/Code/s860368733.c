#include <stdio.h>
#include <stdlib.h>

// Function to check if an integer is in the array
int contains(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

int main() {
    // Initialize variables
    int n, m;
    // Read input from standard input
    scanf("%d %d", &n, &m);
    // Allocate memory for h array
    int *h = (int *)malloc(n * sizeof(int));
    // Read h array elements from standard input
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        // Comment for the loop that reads h array elements
        // from standard input and stores them in the h array
    }
    
    // Initialize counter array
    int *counter = (int *)malloc(n * sizeof(int));
    int counter_size = 0;

    // Read m query pairs from standard input
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // Check the condition for a and b
        if (h[a - 1] < h[b - 1]) {
            // Add a to the counter array if h[a-1] is smaller than h[b-1]
            if (!contains(counter, counter_size, a)) {
                counter[counter_size++] = a;
            }
        } else if (h[a - 1] > h[b - 1]) {
            // Add b to the counter array if h[a-1] is greater than h[b-1]
            if (!contains(counter, counter_size, b)) {
                counter[counter_size++] = b;
            }
        } else {
            // Add both a and b to the counter array if h[a-1] is equal to h[b-1]
            if (!contains(counter, counter_size, a)) {
                counter[counter_size++] = a;
            }
            if (!contains(counter, counter_size, b)) {
                counter[counter_size++] = b;
            }
        }
        // Comment for the loop that processes m query pairs
    }
    
    // Print the result
    printf("%d\n", n - counter_size);
    // Comment for the final print statement

    // Free allocated memory
    free(h);
    free(counter);
    
    return 0;
}
// <END-OF-CODE>
