#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, ans; // Declare variables for iteration, size of vector, and answer count
    scanf("%d", &n); // Input the size of the vector
    int *p = (int *)malloc(n * sizeof(int)); // Initialize a vector of size n

    // Input the elements of the vector
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]); // Read each element into the vector
    }

    ans = 0; // Initialize the answer counter to zero

    // Loop through the vector to check for specific conditions
    for (i = 0; i < n - 1; i++) {
        // Check if the current element matches its expected position (1-based index)
        if (p[i] == i + 1) {
            p[i + 1] = p[i]; // Set the next element to the current element
            ans += 1; // Increment the answer counter
        }
    }

    // Check if the last element matches its expected position
    if (p[n - 1] == n) {
        ans += 1; // Increment the answer counter if the condition is met
    }

    printf("%d\n", ans); // Output the final count of matches

    free(p); // Free the memory allocated for the vector

    return 0;
}

