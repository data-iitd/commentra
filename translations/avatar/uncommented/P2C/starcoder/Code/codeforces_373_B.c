#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int w, m, k;
    scanf("%d %d %d", &w, &m, &k);
    int lo = 0, hi = 1e18;
    while (hi - lo > 1) {
        int md = (lo + hi) / 2;
        int c = sum(m + md - 1) - sum(m - 1);
        if (c * k <= w) {
            lo = md;
        } else {
            hi = md;
        }
    }
    printf("%d\n", lo);
    return 0;
}

int sum(int k) {
    int ret = 0, pw = 10, len = 1;
    while (1 == 1) {
        int cur = min(pw - 1, k);
        int prev = pw / 10;
        ret += (cur - prev + 1) * len;
        if (pw - 1 >= k) {
            break;
        }
        len += 1;
        pw *= 10;
    }
    return ret;
}

int min(int a, int b) {
    return a < b? a : b;
}

