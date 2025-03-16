/*
 * 2415.c: Sashimi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Define constants
#define MAX_N 4000
#define LINF (1LL << 60)

// Define types and aliases (if any)
typedef long long ll;

// Initialize global variables
ll wis[MAX_N], wsums[MAX_N + 1], dp[MAX_N][MAX_N + 1];
int ks[MAX_N][MAX_N + 1];

// Define subroutines (if any)

// main
int main() {
    // Read input
    int n;
    scanf("%d", &n);

    // Initialize arrays
    memset(wsums, 0, sizeof(wsums));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &wis[i]);
        wsums[i + 1] = wsums[i] + wis[i];
    }

    // Initialize 2D array dp and 2D array ks with default values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = LINF;
            ks[i][j] = -1;
        }
        dp[i][i + 1] = 0;
        ks[i][i + 1] = i;
    }

    // Calculate dp and ks for all subarrays of size 2 to n
    for (int l = 2; l <= n; l++) {
        for (int i = 0, j = l; j <= n; i++, j++) {
            // Initialize variables for current subarray
            ll mind = LINF;
            ll wsum = wsums[j] - wsums[i];
            int mink = -1;

            // Find the minimum cost and index of the previous subarray that can be combined with the current subarray
            for (int k = ks[i][j - 1]; k <= ks[i + 1][j]; k++) {
                // Calculate the cost of combining the current subarray with the previous subarray
                ll d = dp[i][k] + dp[k][j] + wsum;

                // Update minimum cost and index if found a better combination
                if (mind > d) {
                    mind = d;
                    mink = k;
                }
            }

            // Update dp and ks for the current subarray
            dp[i][j] = mind;
            ks[i][j] = mink;
        }
    }

    // Print the result
    printf("%lld\n", dp[0][n]);

    // Terminate the program
    return 0;
}

// <END-OF-CODE>
