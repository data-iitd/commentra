#include <stdio.h>

int main() {
    // Read the number of iterations or elements
    int n;
    scanf("%d", &n);

    // Initialize a counter for odd indices
    int t = 0;

    // Loop through the range of n
    for (int i = 0; i < n; i++) {
        // Check if the current index (i + 1) is odd
        if ((i + 1) & 1) {
            t++;  // Increment the counter for odd indices
        }
    }

    // Calculate and print the ratio of odd indices to total elements
    printf("%f\n", (double)t / n);

    return 0;
}

// <END-OF-CODE>
