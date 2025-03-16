#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000010

int main() {
    int n;
    int l[MAXN] = {0};
    int dp[MAXN] = {0};

    // Read the number of test cases
    scanf("%d", &n);

    // Read input for 'n' test cases
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        l[a] = b;
    }

    // Check if the first element of the array 'l' is positive
    if (l[0] > 0) {
        dp[0] = 1;
    }

    // Initialize a variable 'mx' to keep track of the maximum length of a subsequence
    int mx = 0;

    // Iterate through the array 'l' from index 1 to MAXN
    for (int i = 1; i < MAXN; i++) {
        // If the current element of 'l' is zero, set the corresponding element of 'dp' to the previous element
        if (l[i] == 0) {
            dp[i] = dp[i - 1];
        }
        // If the current element of 'l' is greater than or equal to 'i', set the corresponding element of 'dp' to 1
        // This indicates that the current element is part of a subsequence of length 'i'
        else if (l[i] >= i) {
            dp[i] = 1;
        }
        // If the current element of 'l' is less than 'i', calculate the length of the longest subsequence ending at 'i - l[i] - 1'
        // and add 1 to get the length of the subsequence ending at 'i'
        else {
            dp[i] = dp[i - l[i] - 1] + 1;
        }
        // Update the maximum length of a subsequence if a longer one is found
        if (dp[i] > mx) {
            mx = dp[i];
        }
    }

    // Print the answer, which is the number of elements in the longest subsequence that is not a subsequence of the given sequence
    printf("%d\n", n - mx);

    return 0;
}
