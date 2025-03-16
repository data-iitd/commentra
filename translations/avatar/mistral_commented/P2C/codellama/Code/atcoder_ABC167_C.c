#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum number of tests required
int min_tests(int n, int m, int x, int c[][m]) {
    // Initialize empty lists 'l' for storing combinations and 'rem' for storing indices
    int l[n][m], rem[m];
    int l_size = 0, rem_size = 0;

    // Initialize variable 'ans' for storing minimum number of tests
    int ans = 0;

    // Loop through all possible combinations of 'pre' indices
    for (int i = 0; i <= n; i++) {
        // Generate all combinations of 'pre' indices of size 'i'
        for (int j = 0; j < n; j++) {
            // Append the combination to list 'l'
            l[l_size][j] = c[j][i];
        }
        l_size++;
    }

    // Loop through each iteration 'i' of test cases
    for (int i = 1; i <= m; i++) {
        // Initialize variable 'ca' to 0 for sum of tests in current combination
        int ca = 0;

        // Loop through each index 'j' in current combination
        for (int j = 0; j < l_size; j++) {
            // Add the test result at index 'j' and test case 'i' to 'ca'
            ca += l[j][i];
        }

        // If the sum of tests in current combination is less than threshold 'x',
        // add the index of the current combination to 'rem' list
        if (ca < x) {
            rem[rem_size] = i;
            rem_size++;
        }
        // If the sum of tests in current combination is greater than or equal to threshold 'x',
        // continue to next combination
        else {
            continue;
        }

        // If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
        if (rem_size > 0) {
            for (int j = 0; j < rem_size; j++) {
                for (int k = 0; k < l_size; k++) {
                    if (l[k][rem[j]] == 1) {
                        l[k][rem[j]] = 0;
                    }
                }
            }
            rem_size = 0;
        }

        // If 'l' list is empty, print -1 and break the loop
        if (l_size == 0) {
            printf("-1\n");
            break;
        }
    }

    // If the loop completes without finding a valid combination,
    // calculate the minimum number of tests in all valid combinations
    if (l_size > 0) {
        // Initialize variable 'ca' to 0 for sum of tests in current combination
        int ca = 0;

        // Loop through each valid combination and calculate the sum of tests
        for (int i = 0; i < l_size; i++) {
            ca = 0;
            for (int j = 0; j < m; j++) {
                ca += l[i][j];
            }

            // Update 'ans' with minimum number of tests among all valid combinations
            if (ans == 0) {
                ans = ca;
            } else {
                ans = min(ans, ca);
            }
        }

        // Print the minimum number of tests required
        printf("%d\n", ans);
    }

    return 0;
}

// Main function
int main() {
    // Take input dimensions and threshold from user
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    // Initialize numpy array 'c' with dimensions (n, m)
    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    // Call function 'min_tests' to calculate the minimum number of tests required
    min_tests(n, m, x, c);

    return 0;
}

