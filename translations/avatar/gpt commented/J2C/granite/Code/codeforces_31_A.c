
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int n;
    scanf("%d", &n);

    // Initialize a flag to indicate if a valid triplet is found
    int f = 0;

    // Create an array to store the input integers
    int a[n];

    // Read n integers from the input and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize variables for indexing
    int k = 0, j = 0, i = 0;

    // Iterate through each element in the array
    for (k = 0; k < n; k++) {
        // Store the current element to check against pairs
        int t = a[k];

        // Check for pairs in the array that sum up to the current element
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                // Ensure we are not using the same element twice
                if (i!= j && t == (a[i] + a[j])) {
                    // Set the flag to indicate a valid triplet is found
                    f = 1;
                    break;
                }
            }
            // Break out of the loop if a valid pair is found
            if (f == 1) break;
        }
        // Break out of the outer loop if a valid triplet is found
        if (f == 1) break;
    }

    // Output the result: indices of the triplet or -1 if not found
    if (f == 1)
        printf("%d %d %d\n", (k + 1), (j + 1), (i + 1));
    else
        printf("-1\n");

    return 0;
}
