#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Define a constant for infinity
    const int INF = INT_MAX;

    // Create a Scanner object for input
    int n;
    scanf("%d", &n);

    // Initialize two arrays to store the pairs
    int a[n], b[n];

    // Initialize left to infinity and right to zero
    int left = INF, right = 0;

    // Read the pairs and determine the minimum and maximum values
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]); // Read the first and second elements of the pair

        // Update left to the minimum value found in a
        if (a[i] < left) {
            left = a[i];
        }
        // Update right to the maximum value found in b
        if (b[i] > right) {
            right = b[i];
        }
    }

    // Check for a pair that matches the left and right bounds
    for (int i = 0; i < n; i++) {
        // If the current pair matches the min and max values
        if (left == a[i] && right == b[i]) {
            // Print the index (1-based) and exit
            printf("%d\n", i + 1);
            return 0;
        }
    }

    // If no matching pair is found, print -1
    printf("-1\n");

    return 0;
}
