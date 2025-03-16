

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
    long dp[n + 1];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = a[i] > dp[i + 1]? 0 : dp[i + 1] - a[i] + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%ld ", dp[i]);
    }
    printf("\n");
    return 0;
}

These comments should provide a clear understanding of the code logic and the purpose of each block.