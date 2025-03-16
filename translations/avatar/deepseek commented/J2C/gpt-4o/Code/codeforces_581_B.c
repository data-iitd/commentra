#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 4: Read input values
    int n;
    scanf("%d", &n);
    long *a = (long *)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }

    // Step 5: Initialize a dynamic programming array
    long *dp = (long *)malloc((n + 1) * sizeof(long));
    for (int i = 0; i <= n; i++) {
        dp[i] = -1; // Fill with -1
    }

    // Step 6: Fill the dynamic programming array
    dp[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = (dp[i + 1] > a[i]) ? dp[i + 1] : a[i];
    }

    // Step 7: Calculate the result
    for (int i = 0; i < n; i++) {
        if (a[i] > dp[i + 1]) {
            printf("0 ");
        } else {
            printf("%ld ", (dp[i + 1] - a[i] + 1));
        }
    }

    // Step 8: Print the result
    printf("\n");

    // Free allocated memory
    free(a);
    free(dp);

    return 0;
}

// <END-OF-CODE>
