
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve() {
    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    return (n < 0)? -n : n;
}

int main() {
    solve();
    return 0;
}

