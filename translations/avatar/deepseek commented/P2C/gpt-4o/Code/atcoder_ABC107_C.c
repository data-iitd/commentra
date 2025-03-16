#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);  // Reading N and K from input
    int *lst = (int *)malloc(N * sizeof(int));  // Dynamic array for the list of integers
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);  // Reading the list of integers
    }

    int *lst_p = (int *)malloc(N * sizeof(int));  // List to store positive numbers
    int *lst_m = (int *)malloc(N * sizeof(int));  // List to store negative numbers
    int pos_count = 0, neg_count = 0;  // Counters for positive and negative numbers

    // Separating positive and negative numbers
    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;  // Decrement K if the number is 0
        }
        if (lst[i] > 0) {
            lst_p[pos_count++] = lst[i];  // Add positive numbers to lst_p
        } else if (lst[i] < 0) {
            lst_m[neg_count++] = lst[i];  // Add negative numbers to lst_m
        }
    }

    // Initialization of pointers and variables
    int lastx = pos_count;  // Last index of lst_p
    int lasty = neg_count;  // Last index of lst_m

    // Function to check the minimum possible value
    int check(int k) {
        int ans = INT_MAX;  // Initialize answer with a large number
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {  // Check if indices are out of bounds
                continue;
            }
            int p = (j == 0) ? 0 : lst_p[j - 1];  // Get the (j-1)th positive number
            int m = (k - j == 0) ? 0 : lst_m[lasty - (k - j)];  // Get the (lasty - (k - j))th negative number
            ans = (ans < (2 * p + abs(m))) ? ans : (2 * p + abs(m));  // Calculate the minimum value
            ans = (ans < (p + 2 * abs(m))) ? ans : (p + 2 * abs(m));  // Calculate the minimum value
        }
        return ans;
    }

    // Output the result of the check function with K as the argument
    printf("%d\n", check(K));

    // Free allocated memory
    free(lst);
    free(lst_p);
    free(lst_m);

    return 0;
}

// <END-OF-CODE>
