
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main(int argc, char **argv)
{
    if (argc >= 2) {
        freopen(argv[1], "r", stdin);
    }

    int q, h, s, d, n;
    scanf("%d%d%d%d%d", &q, &h, &s, &d, &n);

    int best1L = q * 4;
    best1L = best1L > h * 2? h * 2 : best1L;
    best1L = best1L > s? s : best1L;

    int best2L = d;
    best2L = best2L > best1L * 2? best1L * 2 : best2L;

    int ans = 0;
    if (n % 2 == 0) {
        ans = best2L * (n / 2);
    } else {
        ans = best2L * (n / 2) + best1L;
    }

    printf("%d\n", ans);

    return 0;
}
