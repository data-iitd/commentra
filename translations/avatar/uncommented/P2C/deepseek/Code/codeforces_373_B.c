#include <stdio.h>
#include <limits.h>

long long sum(long long k) {
    long long ret = 0;
    long long pw = 10;
    long long len = 1;
    while (1 == 1) {
        long long cur = (k < pw) ? k : pw - 1;
        long long prev = pw / 10;
        ret += (cur - prev + 1) * len;
        if (pw - 1 >= k) {
            break;
        }
        len++;
        pw *= 10;
    }
    return ret;
}

int main() {
    long long w, m, k;
    scanf("%lld %lld %lld", &w, &m, &k);
    long long lo = 0;
    long long hi = LLONG_MAX;
    while (hi - lo > 1) {
        long long md = (lo + hi) / 2;
        long long c = sum(m + md - 1) - sum(m - 1);
        if (c * k <= w) {
            lo = md;
        } else {
            hi = md;
        }
    }
    printf("%lld\n", lo);
    return 0;
}
