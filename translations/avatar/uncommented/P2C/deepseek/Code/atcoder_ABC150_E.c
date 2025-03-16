#include <stdio.h>
#include <math.h>

#define MOD 1000000007

int main() {
    long long mod = 1000000007;
    int n;
    scanf("%d", &n);
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    // Sort the array in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i] < c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    long long b = pow(2, 2 * n - 2) % mod;
    long long a = 2 * b % mod;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i] * (a + i * b) % mod;
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}
