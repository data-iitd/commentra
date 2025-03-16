#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, K;
    // Read two integers N and K from input
    scanf("%d %d", &N, &K);

    // Allocate memory for the list of integers
    int *lst = (int *)malloc(N * sizeof(int));
    // Read a list of integers from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
    }

    // Initialize arrays to hold positive and negative numbers
    int *lst_p = (int *)malloc(N * sizeof(int));
    int *lst_m = (int *)malloc(N * sizeof(int));
    int count_p = 0, count_m = 0;

    // Iterate through the list to categorize numbers
    for (int i = 0; i < N; i++) {
        // Decrease K for each zero encountered
        if (lst[i] == 0) {
            K--;
        }
        // Add positive numbers to lst_p
        if (lst[i] > 0) {
            lst_p[count_p++] = lst[i];
        }
        // Add negative numbers to lst_m
        else if (lst[i] < 0) {
            lst_m[count_m++] = lst[i];
        }
    }

    // Initialize variables to track the last indices of positive and negative lists
    int lastx = count_p;
    int lasty = count_m;

    // Define a function to check the minimum value based on K
    int check(int k) {
        int ans = INT_MAX;  // Initialize answer with a large number
        // Iterate through possible counts of positive numbers used
        for (int j = 0; j <= k; j++) {
            // Check if the current count of positives and negatives is valid
            if (j > lastx || k - j > lasty) {
                continue;  // Skip invalid combinations
            } else {
                // Determine the maximum positive number used
                int p = (j == 0) ? 0 : lst_p[j - 1];  // Get the largest positive number used

                // Determine the maximum negative number used
                int m = (k - j == 0) ? 0 : lst_m[lasty - (k - j)];  // Get the largest negative number used

                // Calculate the minimum value based on the current combination
                ans = (ans < (2 * p + abs(m))) ? ans : (2 * p + abs(m));
                ans = (ans < (p + 2 * abs(m))) ? ans : (p + 2 * abs(m));
            }
        }
        return ans;  // Return the minimum value found
    }

    // Print the result of the check function with K
    printf("%d\n", check(K));

    // Free allocated memory
    free(lst);
    free(lst_p);
    free(lst_m);

    return 0;
}

// <END-OF-CODE>
