
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long ans = 0;

long get(long a) {
    long ret = 0;
    long now = 1;
    long t = 1;
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

long binarySearch(long k, long l, long r, long x) {
    if (r >= l) {
        long mid = l + (r - l) / 2;
        if (mid > ans && mid * k <= x) {
            ans = mid;
        }
        if (k * mid == x) {
            return mid;
        }
        if (k * mid > x) {
            return binarySearch(k, l, mid - 1, x);
        }
        return binarySearch(k, mid + 1, r, x);
    }
    return -1;
}

int main() {
    long gen, st, tim;
    scanf("%ld %ld %ld", &gen, &st, &tim);
    gen /= tim;
    long beg = st - 1, end = pow(10, 18);
    while (true) {
        long med = (beg + end) / 2 + 1;
        if (get(med) - get(st - 1) > gen) {
            end = med - 1;
        } else {
            beg = med;
        }
        if (beg == end) {
            printf("%ld\n", beg - st + 1);
            break;
        }
    }
    return 0;
}
