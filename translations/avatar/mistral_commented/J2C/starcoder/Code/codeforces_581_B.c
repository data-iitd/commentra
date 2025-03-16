
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_N 100000

int main() {
    int n;
    scanf("%d", &n);
    long a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
    long dp[MAX_N];
    memset(dp, -1, sizeof(dp));
    dp[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i + 1], a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > dp[i + 1]) {
            printf("0 ");
        } else {
            printf("%ld ", dp[i + 1] - a[i] + 1);
        }
    }
    printf("\n");
    return 0;
}

