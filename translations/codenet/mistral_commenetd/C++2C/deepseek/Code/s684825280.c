#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define SIZE (1e5 * 2) + 13

int cnt[SIZE];
int *a = (int *)malloc(SIZE * sizeof(int));

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (cnt[i] > 0) {
            a[index++] = cnt[i];
        }
    }

    int ans = 0;
    std::sort(a, a + index);

    int m = index - k;
    for (int i = 0; i < m; ++i) {
        ans += a[i];
    }

    printf("%d\n", ans);

    free(a);
    return 0;
}

