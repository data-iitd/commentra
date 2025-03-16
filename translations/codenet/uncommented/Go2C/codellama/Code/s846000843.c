
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 1000000000

int64_t combinationCount(int64_t n, int64_t m, int64_t **memo) {
    if (n == m || m == 0) {
        return 1;
    }

    int64_t left, right;
    if (memo[n-1][m-1] != 0) {
        left = memo[n-1][m-1];
    } else {
        left = combinationCount(n-1, m-1, memo);
        memo[n-1][m-1] = left;
    }

    if (memo[n-1][m] != 0) {
        right = memo[n-1][m];
    } else {
        right = combinationCount(n-1, m, memo);
        memo[n-1][m] = right;
    }

    return left + right;
}

int64_t **initMemo(int64_t maxInput) {
    int64_t **memo = (int64_t **)malloc(sizeof(int64_t *) * maxInput);
    for (int i = 0; i < maxInput; i++) {
        memo[i] = (int64_t *)malloc(sizeof(int64_t) * maxInput);
        memset(memo[i], 0, sizeof(int64_t) * maxInput);
    }
    return memo;
}

int64_t *initArray(int64_t maxInput) {
    int64_t *array = (int64_t *)malloc(sizeof(int64_t) * maxInput);
    memset(array, 0, sizeof(int64_t) * maxInput);
    return array;
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int64_t *aa = initArray(n);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &aa[i]);
    }

    int64_t **memo = initMemo(MAX_INPUT);
    int64_t ans = 2020202020;
    for (int i = 1; i < n-1; i++) {
        int64_t cumsum = 0;
        for (int j = 0; j < n; j++) {
            cumsum += aa[j];
        }
        ans = min(ans, abs(cumsum - aa[i] - (cumsum - aa[0] - aa[i])));
    }

    printf("%ld\n", ans);

    return 0;
}

