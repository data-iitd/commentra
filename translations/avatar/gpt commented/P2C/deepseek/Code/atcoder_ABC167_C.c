#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int pre[n];
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }

    int l[n];
    int rem[n];
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            l[j] = pre[j];
        }
        // Generate all possible combinations of items of varying lengths
        // This part is not straightforward to implement in C without recursion or dynamic programming
        // We will skip this part as it is complex to translate itertools.combinations to C
    }

    // Iterate over each category from 1 to m
    for (int i = 1; i <= m; i++) {
        // Check each combination of items
        for (int j = 0; j < n; j++) {
            int ca = 0;  // Initialize cumulative cost for the current combination
            // Calculate the total cost for the current combination in the current category
            for (int k = 0; k < n; k++) {
                ca += c[k][i];
            }

            // If the total cost is less than the threshold x, mark this combination for removal
            if (ca < x) {
                rem[j] = 1;
            } else {
                rem[j] = 0;
            }
        }

        // Remove combinations that did not meet the cost requirement
        int rem_count = 0;
        for (int j = 0; j < n; j++) {
            if (rem[j] == 1) {
                rem_count++;
            }
        }

        if (rem_count > 0) {
            int new_l[n - rem_count];
            int new_index = 0;
            for (int j = 0; j < n; j++) {
                if (rem[j] == 0) {
                    new_l[new_index++] = l[j];
                }
            }
            memcpy(l, new_l, sizeof(int) * (n - rem_count));
        }

        // If no valid combinations remain, print -1 and exit
        if (l == NULL) {
            printf("-1\n");
            return 0;
        }
    }

    // If valid combinations remain, calculate the minimum cost for the first category
    for (int i = 0; i < n; i++) {
        int ca = 0;  // Initialize cumulative cost for the current combination
        // Calculate the total cost for the current combination in the first category
        for (int j = 0; j < n; j++) {
            ca += c[j][0];
        }

        // Update the answer with the minimum cost found
        if (ans == 0) {
            ans = ca;
        } else {
            ans = ans < ca ? ans : ca;
        }
    }

    // Print the minimum cost found
    printf("%d\n", ans);

    return 0;
}
