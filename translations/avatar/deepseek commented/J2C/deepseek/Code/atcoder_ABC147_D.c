#include <stdio.h>
#include <math.h>

#define MOD 1000000007

int main() {
    long startTime = time(NULL);
    int n;
    scanf("%d", &n);
    long long A[n];
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }

    for (int i = 0; i < 60; i++) {
        long long a = 0;
        long long count1 = 0;

        for (int j = 0; j < n; j++) {
            if (A[j] & (1LL << i)) count1++;
        }

        a = a + count1 * (n - count1);

        for (int j = 0; j < i; j++) {
            a = (a << 1) % MOD;
        }

        ans += a;
        ans %= MOD;
    }

    printf("%lld\n", ans);
    long endTime = time(NULL);
    return 0;
}
