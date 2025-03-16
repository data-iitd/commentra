

#include <stdio.h>
#include <stdlib.h>

long long ans = 0;

long long get(long long a) {
    long long ret = 0;
    long long now = 1;
    long long t = 1;
    for (; ; ) {
        if (now * 10 > a) {
            ret += (a - now + 1) * t;
            break;
        }
        ret += now * 9 * t;
        now *= 10;
        t++;
    }
    return ret;
}

long long binarySearch(long long k, long long l, long long r, long long x) {
    if (r >= l) {
        long long mid = l + (r - l) / 2;
        if (mid > ans && mid * k <= x) ans = mid;

        if (k * mid == x) return mid;

        if (k * mid > x) return binarySearch(k, l, mid - 1, x);

        return binarySearch(k, mid + 1, r, x);
    }

    return -1;
}

int main() {
    long long gen, st, tim;
    scanf("%lld %lld %lld", &gen, &st, &tim);
    gen /= tim;
    long long beg = st - 1, end = (long long) pow(10, 18);
    while (true) {
        long long med = (beg + end) / 2 + 1;
        if (get(med) - get(st - 1) > gen) {
            end = med - 1;
        } else {
            beg = med;
        }
        if (beg == end) {
            printf("%lld\n", beg - st + 1);
            break;
        }
    }
    return 0;
}

