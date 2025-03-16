#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    // Taking input from the user and splitting it into two integers
    // Assigning the values to variables `n` and `k`

    int M[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &M[i]);
    }
    // Taking another input from the user, which is supposed to be a list of integers
    // Storing them in the array `M`

    for (int j = 0; j < n; j++) {
        // Starting a loop that will iterate `n` times
        int p;
        for (p = 0; p < n; p++) {
            // Starting another loop that will iterate `n` times
            if (M[p] == 0) {
                // Checking if the element at position `p` in the array `M` is 0
                printf("%d ", p + 1);
                // If the condition is true, print the position `p + 1`
                break;
                // Break out of the loop after printing the position
            }
        }
        for (int l = 0; l < p + 1 - k; l++) {
            M[l] -= 1;
        }
        // Decreasing the elements in the array `M` from position 0 to `p - k` by 1
        M[p] -= 1;
        // Decreasing the element at position `p` by 1
    }

    return 0;
}
// <END-OF-CODE>
