
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

int main(int argc, char **argv) {
    int k;
    scanf("%d", &k);
    int t = 0;
    for (int i = 1; i <= k; i++) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            printf("%d\n", i);
            break;
        }
    }
    if (i > k) {
        printf("-1\n");
    }
    return 0;
}
