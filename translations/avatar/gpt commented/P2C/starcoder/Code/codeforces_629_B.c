#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum of two values
int min(int a, int b) {
    return a < b? a : b;
}

// Function to find the minimum value of the cumulative sum of 'M' and 'F'
int main() {
    // Initialize a constant N for the size of the arrays
    const int N = 368;

    // Create two lists to track the values for 'M' and 'F'
    int *m = (int *) malloc(N * sizeof(int));  // List to track 'M' values
    int *f = (int *) malloc(N * sizeof(int));  // List to track 'F' values

    // Read the number of operations from input
    int n;
    scanf("%d", &n);

    // Read the operations from input
    for (int i = 0; i < n; i++) {
        // Read the operation type and the indices a and b
        char x;
        int a, b;
        scanf(" %c %d %d", &x, &a, &b);

        // Update the corresponding list based on the operation type
        if (x == 'M') {
            m[a]++;  // Increment the value at index a in the 'M' list
            m[b]--;  // Decrement the value at index b in the 'M' list
        } else {
            f[a]++;  // Increment the value at index a in the 'F' list
            f[b]--;  // Decrement the value at index b in the 'F' list
        }
    }

    // Initialize variables to track cumulative sums and the minimum value
    int a = 0, b = 0, c = 0;

    // Iterate through the range of N to calculate cumulative sums and find the minimum
    for (int i = 0; i < N; i++) {
        a += m[i];  // Update cumulative sum for 'M'
        b += f[i];  // Update cumulative sum for 'F'

        // Update the minimum value if the current minimum of a and b is greater than c
        if (min(a, b) > c) {
            c = min(a, b);  // Set c to the new minimum value
    }

    // Print the final minimum value found
    printf("%d\n", c);

    // Free the memory allocated to the lists
    free(m);
    free(f);

    return 0;
}

