
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define input variables
int n, k, t;
int *vec;
int ans = 1000000001;

int main() {
    // Read input values for n and k
    scanf("%d %d", &n, &k);

    // Initialize vector 'vec' with size 'n'
    vec = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        // Read input value for 't' and add it to the vector
        scanf("%d", &t);
        vec[i] = t;
    }

    // Sort the vector 'vec' in ascending order
    qsort(vec, n, sizeof(int), compare);

    // Iterate through the vector with a sliding window of size 'k'
    for (int i = 0; i + k -1 < n; i++) {
        // Calculate the difference between the last and first element of the current window
        int diff = vec[i+k-1] - vec[i];

        // Update the answer if the current difference is smaller than the previous one
        if (diff < ans) {
            ans = diff;
        }
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

