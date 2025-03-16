#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int maxMatching(int v, int p, int g[MAX_N][MAX_N], int n) {
    int a = 0;
    int o = 0;
    for (int w = 0; w < n; ++w) {
        if (g[v][w] == 0 || w == p) continue;
        int r = maxMatching(w, v, g, n);
        a += r / 2;
        o += r % 2;
    }
    return 2 * a + (o % 2 == 0 ? 0 : 1) + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int g[MAX_N][MAX_N] = {0};
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a - 1][b - 1] = 1;
        g[b - 1][a - 1] = 1;
    }
    int m = maxMatching(0, -1, g, n) / 2;
    printf(2 * m == n ? "Second\n" : "First\n");
    return 0;
}

