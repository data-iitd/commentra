#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Q 1000

int n = 0, m = 0, q = 0;
long ans = -100L;
int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];

void dfs(int *list, int size) {
    if (size == n) {
        long score = 0L;
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
            dfs(list, size + 1);
        }
    } else {
        for (int num = 1; num <= m; ++num) {
            list[size] = num;
            dfs(list, size + 1);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i]--;
        b[i]--;
    }

    int list[n];
    dfs(list, 0);

    printf("%ld\n", ans);
    return 0;
}

