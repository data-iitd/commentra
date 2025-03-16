#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (c > b) {
        printf("0\n");
    } else if (a > d) {
        printf("0\n");
    } else if (a < c) {
        printf("%d\n", (int)fmin(b, d) - c);
    } else {
        int l[4] = {a, b, c, d};
        qsort(l, 4, sizeof(int), cmpfunc);
        printf("%d\n", l[2] - l[1]);
    }
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

