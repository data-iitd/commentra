#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Q 50
#define MAX_N 10
#define MAX_M 10

int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];
int n, m, q;
long long ans = -100LL;

void dfs(int *list, int size) {
    if (size == n) {
        long long score = 0LL;
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

    int list[MAX_N];
    dfs(list, 0);

    printf("%lld\n", ans);
    return 0;
}
