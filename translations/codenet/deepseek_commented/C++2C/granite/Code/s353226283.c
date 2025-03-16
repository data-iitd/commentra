
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main() {
    int n, k, t;
    int *vec = (int*)malloc(sizeof(int) * n); // Allocate memory for the vector
    int ans = 1000000001; // Initialize the answer with a large number
    scanf("%d %d", &n, &k); // Read the number of elements and the subarray size
    for (int i = 0; i < n; i++) {
        scanf("%d", &t); // Read each element and add it to the vector
        vec[i] = t;
    }
    std::sort(vec, vec + n); // Sort the vector in ascending order
    for (int i = 0; i + k - 1 < n; i++) { // Iterate through the sorted vector
        int diff = vec[i + k - 1] - vec[i]; // Calculate the difference between the max and min in the subarray
        if (diff < ans) { // Update the answer if the current difference is smaller
            ans = diff;
        }
    }
    printf("%d\n", ans); // Output the minimum difference
    free(vec); // Free the allocated memory
    return 0;
}

