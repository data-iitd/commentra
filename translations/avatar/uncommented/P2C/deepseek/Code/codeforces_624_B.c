#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    long long ans = 0;
    int pre = 1e9;
    for (int j = 0; j < n; j++) {
        ans += (long long)fmax(0, fmin(pre - 1, a[j]));
        pre = (int)fmax(0, fmin(pre - 1, a[j]));
    }
    printf("%lld\n", ans);
    return 0;
}
