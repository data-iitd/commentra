#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int x[3];
    int max = 0;
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        if (x[i] > max) {
            max = x[i];
        }
    }
    int k;
    scanf("%d", &k);
    long long a[3][max];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            scanf("%lld", &a[i][j]);
        }
        qsort(a[i], x[i], sizeof(long long), (int (*)(const void *, const void *))compare);
    }
    int n = 0;
    long long ans[max * max * max];
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    long long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[n++] = tmp;
                }
            }
        }
    }
    qsort(ans, n, sizeof(long long), (int (*)(const void *, const void *))compare);
    for (int i = 0; i < k; ++i) {
        printf("%lld\n", ans[n - i - 1]);
    }
    return 0;
}

int compare(const void *a, const void *b) {
    long long l = *(long long *)a;
    long long r = *(long long *)b;
    if (l < r) return -1;
    if (l > r) return 1;
    return 0;
}
