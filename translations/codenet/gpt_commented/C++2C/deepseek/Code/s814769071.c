#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MOD 1000000007

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    long long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
    long long mn = k * (k - 1) / 2;
    long long res = 0;

    for (int i = k; i <= n + 1; ++i) {
        res += mx - mn + 1;
        res %= MOD;
        mx += n - i;
        mn += i;
    }

    printf("%lld\n", res);
}

