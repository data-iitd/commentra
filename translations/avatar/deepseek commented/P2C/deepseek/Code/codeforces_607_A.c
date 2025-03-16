#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000010

int main() {
    int n;
    scanf("%d", &n);
    int l[MAXN] = {0};
    int dp[MAXN] = {0};

    // Read `n` pairs of integers and store them in list `l`
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        l[a] = b;
    }

    // If the value at index 0 in `l` is greater than 0, set `dp[0]` to 1
    if (l[0] > 0) {
        dp[0] = 1;
    }

    int mx = 0;

    // Iterate through the list `l` from 1 to 1000010, updating the `dp` list
    for (int i = 1; i < MAXN; i++) {
        if (l[i] == 0) {
            dp[i] = dp[i - 1];
        } else {
            if (l[i] >= i) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - l[i] - 1] + 1;
            }
        }
        if (dp[i] > mx) {
            mx = dp[i];
        }
    }

    // Print the result as `n - mx`
    printf("%d\n", n - mx);

    return 0;
}
