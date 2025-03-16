
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

int main(int argc, char *argv[]) {
    int n, l[100000], c = 0, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int));
    for (i = 0; i < n; i++) {
        if (l[i] > c) {
            c++;
        }
    }
    printf("%d\n", c + 1);
    return 0;
}
