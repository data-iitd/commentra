#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100

int c[MAX_N][MAX_M];
int l[MAX_N][MAX_N]; // To store combinations
int pre[MAX_N]; // To store indices for combinations
int rem[MAX_N]; // To store indices to remove
int n, m, x;
int ans = 0;

void generate_combinations(int *arr, int n, int r, int index, int *data, int i) {
    if (index == r) {
        for (int j = 0; j < r; j++) {
            l[i][j] = data[j];
        }
        return;
    }
    if (i >= n) return;

    data[index] = arr[i];
    generate_combinations(arr, n, r, index + 1, data, i + 1);
    generate_combinations(arr, n, r, index, data, i + 1);
}

int main() {
    // Take input dimensions and threshold from user
    scanf("%d %d %d", &n, &m, &x);

    // Initialize the array 'c' with dimensions (n, m)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    // Initialize 'pre' array with indices
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }

    // Initialize variable for storing combinations
    int total_combinations = 0;

    // Loop through all possible combinations of 'pre' indices
    for (int i = 0; i <= n; i++) {
        int data[MAX_N];
        generate_combinations(pre, n, i, 0, data, 0);
        total_combinations++;
    }

    // Loop through each iteration 'i' of test cases
    for (int i = 0; i < m; i++) {
        int ca = 0;

        // Loop through each index 'j' in current combination
        for (int j = 0; j < total_combinations; j++) {
            ca = 0;
            for (int k = 0; k < n; k++) {
                ca += c[l[j][k]][i];
            }

            // If the sum of tests in current combination is less than threshold 'x'
            if (ca < x) {
                rem[i] = j; // Store index to remove
            }
        }

        // If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
        if (rem[i] >= 0) {
            for (int j = rem[i]; j < total_combinations - 1; j++) {
                l[j] = l[j + 1];
            }
            total_combinations--;
        }

        // If 'l' list is empty, print -1 and break the loop
        if (total_combinations == 0) {
            printf("-1\n");
            return 0;
        }
    }

    // If the loop completes without finding a valid combination,
    // calculate the minimum number of tests in all valid combinations
    for (int i = 0; i < total_combinations; i++) {
        int ca = 0;
        for (int j = 0; j < n; j++) {
            ca += c[l[i][j]][0];
        }

        // Update 'ans' with minimum number of tests among all valid combinations
        if (ans == 0) {
            ans = ca;
        } else {
            ans = (ans < ca) ? ans : ca;
        }
    }

    // Print the minimum number of tests required
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
