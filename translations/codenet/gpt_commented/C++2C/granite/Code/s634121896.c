

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int dp[n + 1];
    dp[0] = 1;
    int last[100001];
    int next[100001];
    for (int i = 0; i <= 100000; i++) {
        last[i] = -1;
        next[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (last[a[i - 1]]!= -1 && next[a[i - 1]]!= i - 1) {
            dp[i] = (dp[i] + dp[last[a[i - 1]]]) % 100000007;
        }
        last[a[i - 1]] = i - 1;
        next[a[i - 1]] = -1;
    }
    printf("%d\n", dp[n]);
    return 0;
}
