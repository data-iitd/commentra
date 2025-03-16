#include <stdio.h>

#define SIZE 1000010

int main() {
    // Read the number of pairs from user input
    int n;
    scanf("%d", &n);

    // Initialize a list to store values, filled with zeros
    int l[SIZE] = {0};

    // Initialize a dynamic programming list to store results
    int dp[SIZE] = {0};

    // Read n pairs of integers and populate the list l
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        l[a] = b;  // Set l[a] to b based on the input pairs
    }

    // If the first element in l is greater than 0, set dp[0] to 1
    if (l[0] > 0) {
        dp[0] = 1;
    }

    // Initialize a variable to keep track of the maximum value found in dp
    int mx = 0;

    // Iterate through the list from index 1 to 1000009
    for (int i = 1; i < SIZE; i++) {
        // If l[i] is 0, carry forward the previous dp value
        if (l[i] == 0) {
            dp[i] = dp[i - 1];
        } else {
            // If l[i] is greater than or equal to i, set dp[i] to 1
            if (l[i] >= i) {
                dp[i] = 1;
            } else {
                // Otherwise, calculate dp[i] based on previous values
                dp[i] = dp[i - l[i] - 1] + 1;
            }
        }

        // Update the maximum value found in dp
        if (dp[i] > mx) {
            mx = dp[i];
        }
    }

    // Print the result, which is the difference between n and the maximum value found in dp
    printf("%d\n", n - mx);

    return 0;
}

// <END-OF-CODE>
