#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int ll[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ll[i]);
    }

    qsort(ll, n, sizeof(int), compare);

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) >> 1;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            ans += l - (j + 1);
        }
    }
    printf("%d\n", ans);

    return 0;
}
