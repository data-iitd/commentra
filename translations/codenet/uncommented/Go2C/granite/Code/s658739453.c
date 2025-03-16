
#include <stdio.h>

const int d = 1000000007;

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    long mdans[p];
    for (int index = 0; index < p; index++) {
        scanf("%ld", &mdans[index]);
    }

    long dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    if (mdans[0] == 1) {
        dp[1] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (mdans[i-1] == i) {
            continue;
        }
        dp[i] = (dp[i-1] + dp[i-2]) % d;
    }

    printf("%ld\n", dp[n]);
}
