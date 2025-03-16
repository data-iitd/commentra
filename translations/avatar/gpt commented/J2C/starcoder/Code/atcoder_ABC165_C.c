#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int a[q], b[q], c[q], d[q];
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    long ans = -100L;
    for (int i = 0; i < m; ++i) {
        bool visited[m];
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        dfs(i, visited, a, b, c, d, n, m, q, ans);
    }
    printf("%ld\n", ans);
    return 0;
}

bool dfs(int i, bool visited[m], int a[q], int b[q], int c[q], int d[q], int n, int m, int q, long *ans) {
    if (i == m) {
        long score = 0L;
        for (int j = 0; j < q; ++j) {
            if (visited[b[j] - 1] - visited[a[j] - 1] == c[j]) {
                score += d[j];
            }
        }
        *ans = max(*ans, score);
        return true;
    }
    for (int j = i + 1; j <= m; ++j) {
        if (!visited[j]) {
            visited[j] = true;
            dfs(j, visited, a, b, c, d, n, m, q, ans);
            visited[j] = false;
        }
    }
    return false;
}

