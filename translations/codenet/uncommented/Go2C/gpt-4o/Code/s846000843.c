#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_N 100000

int cumsum[MAX_N + 1];

int Abs(int a) {
    return a >= 0 ? a : -a;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

void CumSum(int *nums, int n) {
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + nums[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *aa = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }

    CumSum(aa, n);

    int ans = 2020202020;
    for (int i = 1; i < n; i++) {
        ans = Min(ans, Abs(cumsum[n] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    printf("%d\n", ans);

    free(aa);
    return 0;
}

// <END-OF-CODE>
