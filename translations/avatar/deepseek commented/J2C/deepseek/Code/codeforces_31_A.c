#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, f = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];

    // Read the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k = 0, j = 0, i = 0; // Initialize indices

    // Outer loop to iterate over each element as a potential a[k]
    for (k = 0; k < n; k++) {
        int t = a[k]; // Current element as t

        // Inner loops to find two indices i and j such that a[i] + a[j] = t
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                if (i != j && t == (a[i] + a[j])) {
                    f = 1; // Set flag to 1 if triplet is found
                    break; // Break out of the inner loop
                }
            }
            if (f == 1) break; // Break out of the outer loop if triplet is found
        }
        if (f == 1) break; // Break out of the main loop if triplet is found
    }

    // Check if a triplet was found and print the result
    if (f == 1)
        printf("%d %d %d\n", k + 1, j + 1, i + 1);
    else
        printf("-1\n");

    return 0;
}
