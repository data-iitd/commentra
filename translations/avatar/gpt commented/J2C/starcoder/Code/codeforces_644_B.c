#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_N 100000
#define MAX_B 100000

int main(int argc, char *argv[])
{
    int n, b;
    scanf("%d %d", &n, &b);
    long ans[MAX_N];
    long t, d;
    int i;
    long *q = (long *)malloc(sizeof(long) * b);
    memset(q, 0, sizeof(long) * b);
    for (i = 0; i < n; i++) {
        scanf("%ld %ld", &t, &d);
        while (q[0] <= t && q[0]!= 0) {
            q[0] = 0;
            memmove(q, q + 1, sizeof(long) * (b - 1));
        }
        if (q[0] == 0) {
            ans[i] = t + d;
            q[0] = ans[i];
        } else {
            ans[i] = q[b - 1] + d;
            q[0] = ans[i];
        }
    }
    for (i = 0; i < n; i++) {
        printf("%ld ", ans[i]);
    }
    printf("