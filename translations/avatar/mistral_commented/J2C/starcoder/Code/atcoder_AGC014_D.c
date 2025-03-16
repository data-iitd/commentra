
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100000

int g[MAX][MAX];
int maxMatching;

int maxMatching(int v, int p) {
    int a = 0;
    int o = 0;
    for (int i = 0; i < g[v].size(); i++) {
        int w = g[v][i];
        if (w == p) continue;
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }
    return 2 * a + (o < 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a - 1][b - 1] = 1;
        g[b - 1][a - 1] = 1;
    }
    maxMatching = maxMatching(0, -1) / 2;
    if (2 * maxMatching == n) {
        printf("Second\n");
    } else {
        printf("First\n");
    }
    return 0;
}

