
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define a large constant for infinity
    #define INF 1000000000
    int A, B, Q, x, b, d, res, S, T, d1, d2;

    // Read the number of elements in the first array A and initialize it
    scanf("%d", &A);
    int s[A+2] = {-INF, INF};
    // Populate the first array with input values
    for (int i = 1; i <= A; i++) {
        scanf("%d", &s[i]);
    }

    // Read the number of elements in the second array B
    scanf("%d", &B);
    int t[B+2] = {-INF, INF};
    // Populate the second array with input values
    for (int i = 1; i <= B; i++) {
        scanf("%d", &t[i]);
    }

    // Read the number of queries Q
    scanf("%d", &Q);

    // Process each query
    for (int i = 0; i < Q; i++) {
        // Read the query value x
        scanf("%d", &x);
        // Find the position in the first array where x would fit
        b = (int)(sqrt(2 * (double)x) + 0.5);
        d = (int)(sqrt(2 * (double)(INF - x)) + 0.5);
        // Initialize the result with infinity
        res = INF;

        // Check the closest values in the first array
        for (int j = 0; j < 2; j++) {
            // Check the closest values in the second array
            for (int k = 0; k < 2; k++) {
                // Calculate the distances for both possible paths
                S = s[b-j];
                T = t[d-k];
                d1 = abs(S-x) + abs(T-S);
                d2 = abs(T-x) + abs(S-T);
                // Update the result with the minimum distance found
                res = fmin(res, fmin(d1, d2));
            }
        }

        // Output the result for the current query
        printf("%d\n", res);
    }

    return 0;
}
// 