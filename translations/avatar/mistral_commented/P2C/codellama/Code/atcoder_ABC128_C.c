#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the main function
int main() {
    // Read input: number of test cases, number of lists, and the lists themselves
    int n, m;
    scanf("%d %d", &n, &m);
    int li[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &li[i][j]);
        }
    }

    // Read input: pattern
    int p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Create a set of all elements in the lists
    int q[n];
    int q_size = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool found = false;
            for (int k = 0; k < q_size; k++) {
                if (q[k] == li[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                q[q_size++] = li[i][j];
            }
        }
    }

    // Create a set of numbers from 1 to n (excluding n)
    int r[n-1];
    int r_size = 0;
    for (int i = 1; i < n; i++) {
        r[r_size++] = i;
    }

    // Find the set of numbers in r that are not in q
    int v[n-1];
    int v_size = 0;
    for (int i = 0; i < r_size; i++) {
        bool found = false;
        for (int j = 0; j < q_size; j++) {
            if (r[i] == q[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            v[v_size++] = r[i];
        }
    }

    // Initialize answer to 0
    int ans = 0;

    // Iterate through all possible subsets of q, from empty to the full set
    for (int i = 0; i < q_size+1; i++) {
        // Iterate through all combinations of i elements from q
        for (int j = 0; j < q_size; j++) {
            // Iterate through each list and pattern
            for (int k = 0; k < m; k++) {
                // Convert s to a set
                int s[i];
                for (int l = 0; l < i; l++) {
                    s[l] = q[j+l];
                }
                // Check if the current combination of lists and pattern match the current subset of q
                int found = 0;
                for (int l = 0; l < n; l++) {
                    bool found_in_s = false;
                    for (int m = 0; m < i; m++) {
                        if (s[m] == li[k][l]) {
                            found_in_s = true;
                            break;
                        }
                    }
                    if (found_in_s) {
                        found++;
                    }
                }
                if (found % 2 != p[k]) {
                    // If not, break out of the inner loop and move on to the next combination
                    break;
                }
            }
            // If all combinations of lists and pattern match the current subset of q, increment the answer
            if (j == q_size-1) {
                ans += pow(2, v_size);
            }
        }
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

// 