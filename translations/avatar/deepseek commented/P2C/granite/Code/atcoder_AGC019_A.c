
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#include <setjmp.h>
#include <unistd.h>

int main() {
    int q, h, s, d, n;
    scanf("%d %d %d %d", &q, &h, &s, &d);
    scanf("%d", &n);

    int best1L = q * 4 < h * 2? q * 4 : h * 2;
    best1L = best1L < s? best1L : s;

    int best2L = d < best1L * 2? d : best1L * 2;

    if (n % 2 == 0) {
        printf("%d\n", best2L * (n / 2));
    } else {
        printf("%d\n", best2L * (n / 2) + best1L);
    }

    return 0;
}
