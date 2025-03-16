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

    int pre = 1e9;
    int ans = 0;

    for (int j = 0; j < n; j++) {
        ans += (a[j] < pre) ? a[j] : (pre - 1);
        pre = (a[j] < pre) ? a[j] : (pre - 1);
    }

    printf("%d\n", ans);

    return 0;
}
