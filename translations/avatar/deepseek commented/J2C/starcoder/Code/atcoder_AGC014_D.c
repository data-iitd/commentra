#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int n;
int g[MAX_N][MAX_N];
int m[MAX_N];

int maxMatching(int v, int p) {
    int a = 0;
    int o = 0;
    for (int w = 0; w < n; ++w) {
        if (w == p) continue;
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }
    return 2 * a + (o == 0? 1 : 0);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = 1;
        g[b][a] = 1;
    }
    int m = maxMatching(0, -1) / 2;
    printf("%s\n", 2 * m == n? "Second" : "First");
    return 0;
}

