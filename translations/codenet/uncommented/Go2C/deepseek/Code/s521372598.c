#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt() {
    int ret;
    scanf("%d", &ret);
    return ret;
}

int* getIntSlice(int n) {
    int* ret = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ret[i]);
    }
    return ret;
}

int abs(int n) {
    return n < 0 ? -n : n;
}

void solve() {
    int n = getInt();
    int* as = getIntSlice(n);

    int* xs = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }
    free(as);

    qsort(xs, n, sizeof(int), (int (*)(const void*, const void*))compare);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);
    free(xs);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    solve();
    return 0;
}

