#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
<<<<<<< HEAD
=======
#define INF (int)2e9
>>>>>>> 98c87cb78a (data updated)

int main() {
    // Read the number of elements
    int N;
    scanf("%d", &N);

    // Initialize an array to store the elements
    int *a = (int *)malloc(N * sizeof(int));
    // Read the elements into the array
    REP(i, N) scanf("%d", &a[i]);

    // Initialize index and answer counter
    int idx = 1;
    int ans = 0;

    // Iterate through the array to count mismatches
    REP(i, N) {
        // If the current element matches the expected index
        if (a[i] == idx) {
            // Move to the next expected index
            idx++;
        } else {
            // Count the mismatch
            ans++;
        }
    }

    // If no elements matched the expected index
    if (idx == 1) {
        printf("-1\n"); // Output -1 to indicate no matches
    } else {
        // Output the count of mismatches
        printf("%d\n", ans);
    }

    // Free the allocated memory
    free(a);

    return 0; // End of the program
}

// <END-OF-CODE>
