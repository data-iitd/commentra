
#include <stdio.h>

int main() {
    int n, maxn = 4010, a, b, c, arr[3], dp[maxn];
    scanf("%d%d%d", &n, &a, &b, &c);
    arr[0] = a, arr[1] = b, arr[2] = c;
    for (int i = 0; i < n; i++) {
        dp[i] = -10000;
    }
    dp[0] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < n; j++) {
            dp[j] = dp[j] > dp[j - arr[i]] + 1? dp[j] : dp[j - arr[i]] + 1;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
//END-OF-CODE