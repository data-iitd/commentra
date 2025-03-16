#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define MAX_N 100000

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    int v[MAX_N];
    int c[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        int profit = v[i] - c[i];
        if (profit > 0) {
            max += profit;
        }
    }
    printf("%d\n", max);
    return 0;
}

