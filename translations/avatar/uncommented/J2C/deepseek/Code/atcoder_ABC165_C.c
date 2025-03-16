#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n = 0, m = 0, q = 0;
long ans = LONG_MIN;

void dfs(int *a, int *b, int *c, int *d, int *list, int size) {
    if (size == n) {
        long score = 0;
        for (int i = 0; i < q; ++i) {
            if (list[b[i]] - list[a[i]] == c[i]) {
                score += d[i];
            }
        }
        if (score > ans) {
            ans = score;
        }
        return;
    }
    if (size > 0) {
        for (int num = list[size - 1]; num <= m; ++num) {
            list[size] = num;
            dfs(a, b, c, d, list, size + 1);
        }
    } else {
        for (int num = 1; num <= m; ++num) {
            list[size] = num;
            dfs(a, b, c, d, list, size + 1);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    int *a = (int *)malloc(q * sizeof(int));
    int *b = (int *)malloc(q * sizeof(int));
    int *c = (int *)malloc(q * sizeof(int));
    int *d = (int *)malloc(q * sizeof(int));
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i]--;
        b[i]--;
    }
    int *list = (int *)malloc(n * sizeof(int));
    dfs(a, b, c, d, list, 0);
    printf("%ld\n", ans);
    free(a);
    free(b);
    free(c);
    free(d);
    free(list);
    return 0;
}

