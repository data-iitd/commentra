#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m, x;
    // Read the number of books (n), the number of skills (m), and the minimum skill level required (x)
    scanf("%d %d %d", &n, &m, &x);

    // Allocate memory for the cost matrix
    int **c = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        c[i] = (int *)malloc((m + 1) * sizeof(int)); // m + 1 to include cost and skills
        for (int j = 0; j <= m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    // Initialize variables
    int *combination = (int *)malloc(n * sizeof(int));
    int ans = INT_MAX;

    // Generate all possible combinations of books
    for (int i = 1; i < (1 << n); i++) {
        int total_cost = 0;
        int skill_levels[m];
        for (int j = 0; j < m; j++) {
            skill_levels[j] = 0; // Initialize skill levels
        }

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // If the j-th book is included in the combination
                total_cost += c[j][0]; // Add cost
                for (int k = 1; k <= m; k++) {
                    skill_levels[k - 1] += c[j][k]; // Add skill levels
                }
            }
        }

        // Check if the combination meets the skill requirement
        int meets_requirement = 1;
        for (int j = 0; j < m; j++) {
            if (skill_levels[j] < x) {
                meets_requirement = 0;
                break;
            }
        }

        // If it meets the requirement, check for minimum cost
        if (meets_requirement) {
            if (total_cost < ans) {
                ans = total_cost;
            }
        }
    }

    // Output the result
    if (ans == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(c[i]);
    }
    free(c);
    free(combination);

    return 0;
}
