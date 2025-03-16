
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_B 100000

int main(int argc, char **argv)
{
    int n, b;
    scanf("%d %d", &n, &b);
    long ans[MAX_N];
    long *q = (long *)malloc(sizeof(long) * b);
    memset(q, 0, sizeof(long) * b);
    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);
        int j = 0;
        while (j < b && q[j] <= t) {
            q[j] = 0;
            j++;
        }
        if (j < b) {
            ans[i] = (q[j] == 0? t : q[j - 1]) + d;
            q[j] = ans[i];
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%ld ", ans[i]);
    }
    printf("