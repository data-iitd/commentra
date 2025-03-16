#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Declare variables for the number of participants (n), number of skills (m), and the minimum skill level required (x)
    int n, m, x;
    // Read input values for n, m, and x
    scanf("%d %d %d", &n, &m, &x);

    // Initialize a 2D array to hold skill levels and an array for participant points
    int **a = (int **)malloc(n * sizeof(int *));
    int *p = (int *)malloc(n * sizeof(int));
    
    // Read participant points and their respective skill levels
    for (int i = 0; i < n; i++) {
        // Read the points for participant i
        scanf("%d", &p[i]);
        // Allocate memory for the skill level array for participant i
        a[i] = (int *)malloc(m * sizeof(int));
        // Read the skill levels for participant i
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Initialize the answer to a large number and other variables for tracking total points and skill validation
    int ans = INT_MAX;
    int tot;
    int ok;

    // Iterate through all possible combinations of participants using bit manipulation
    for (int bits = 0; bits < (1 << n); bits++) {
        // Reset total points and skill validation flag for the current combination
        tot = 0;
        ok = 1; // Assume valid until proven otherwise
        // Initialize an array to accumulate skill levels for the current combination
        int *skill = (int *)calloc(m, sizeof(int));

        // Check each participant to see if they are included in the current combination
        for (int i = 0; i < n; i++) {
            if ((bits >> i) & 1) {
                // Add the points of the selected participant to the total
                tot += p[i];
                // Accumulate the skill levels of the selected participant
                for (int j = 0; j < m; j++) {
                    skill[j] += a[i][j];
                }
            }
        }

        // Check if the accumulated skill levels meet the minimum requirement
        for (int j = 0; j < m; j++) {
            if (skill[j] < x) {
                ok = 0; // If any skill level is below x, mark as not okay
                break;
            }
        }

        // If the combination is valid (all skills meet the requirement), update the answer if the total points are lower
        if (ok) {
            if (ans > tot) {
                ans = tot;
            }
        }

        // Free the skill array for the current combination
        free(skill);
    }

    // Output the result: the minimum points needed or -1 if no valid combination was found
    if (ans != INT_MAX) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(p);

    return 0;
}

// <END-OF-CODE>
