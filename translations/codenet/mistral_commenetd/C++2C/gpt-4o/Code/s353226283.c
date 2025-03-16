#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Define input variables
    int n, k, t;
    int *vec;
    int ans = 1000000001;

    // Read input values for n and k
    scanf("%d %d", &n, &k);

    // Allocate memory for the vector 'vec'
    vec = (int *)malloc(n * sizeof(int));

    // Read input values into the vector
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        vec[i] = t;
    }

    // Sort the vector 'vec' in ascending order
    qsort(vec, n, sizeof(int), compare);

    // Iterate through the vector with a sliding window of size 'k'
    for (int i = 0; i + k - 1 < n; i++) {
        // Calculate the difference between the last and first element of the current window
        int diff = vec[i + k - 1] - vec[i];

        // Update the answer if the current difference is smaller than the previous one
        if (diff < ans) {
            ans = diff;
        }
    }

    // Print the answer
    printf("%d\n", ans);

    // Free allocated memory
    free(vec);

    return 0;
}

// <END-OF-CODE>
