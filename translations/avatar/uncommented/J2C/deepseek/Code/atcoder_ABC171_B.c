#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }
    printf("%d\n", ans);
    return 0;
}

