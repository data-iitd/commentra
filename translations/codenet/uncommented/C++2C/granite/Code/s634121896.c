

#include <stdio.h>

#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int dp[n + 1];
    dp[0] = 1;
    int kek[100001];
    int prev[100001];
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i - 1] + (prev[nums[i - 1]]!= i - 1? kek[nums[i - 1]] : 0)) % MOD;
        kek[nums[i - 1]] = dp[i];
        prev[nums[i - 1]] = i;
    }
    printf("%d\n", dp[n]);
    return 0;
}

