
#include <stdio.h>

int main() {
    // Read input values for n and k
    int n, k;
    scanf("%d %d", &n, &k);

    // Read the list of integers M from input
    int M[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &M[i]);
    }

    // Initialize a variable m to zero (not used in the current logic)
    int m = 0;

    // Outer loop to iterate over each index j in the range of n
    for (int j = 0; j < n; j++) {
        // Inner loop to find the first index p where M[p] is zero
        int p;
        for (p = 0; p < n; p++) {
            if (0 == M[p]) {
                // Print the index (1-based) where M[p] is zero
                printf("%d ", p + 1);
                break;
            }
        }
        
        // Decrease the values in M from the start up to p + 1 - k
        for (int l = 0; l < p + 1 - k; l++) {
            M[l] -= 1;
        }
        
        // Decrease the value at index p in M
        M[p] -= 1;
    }

    return 0;
}
