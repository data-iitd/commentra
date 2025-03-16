#include <stdio.h>
#include <limits.h>

int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int maxn = 4010;
    int arr[] = {a, b, c};
    int dp[maxn];
    for (int i = 0; i < maxn; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < maxn; j++) {
            if (dp[j - arr[i]] != INT_MIN) {
                dp[j] = (dp[j] > dp[j - arr[i]] + 1) ? dp[j] : dp[j - arr[i]] + 1;
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
