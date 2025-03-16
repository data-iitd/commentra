

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

// Define input variables
int n, k, t;
int vec[100000];
int ans = 1000000001;

int main() {
    // Read input values for n and k
    scanf("%d %d", &n, &k);

    // Initialize array'vec' with size 'n'
    for (int i = 0; i < n; i++) {
        // Read input value for 't' and add it to the array
        scanf("%d", &t);
        vec[i] = t;
    }

    // Sort the array'vec' in ascending order
    std::sort(vec, vec + n);

    // Iterate through the array with a sliding window of size 'k'
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

