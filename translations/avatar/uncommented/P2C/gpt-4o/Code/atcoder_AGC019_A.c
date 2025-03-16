#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

int main() {
    long long q, h, s, d;
    scanf("%lld %lld %lld %lld", &q, &h, &s, &d);
    int n;
    scanf("%d", &n);

    long long best1L = min(min(q * 4, h * 2), s);
    long long best2L = min(d, best1L * 2);

    if (n % 2 == 0) {
        printf("%lld\n", best2L * (n / 2));
    } else {
        printf("%lld\n", best2L * (n / 2) + best1L);
    }

    return 0;
}

// <END-OF-CODE>
