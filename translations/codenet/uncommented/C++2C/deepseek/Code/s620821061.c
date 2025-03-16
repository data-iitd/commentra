#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 520

typedef long long ll;

typedef struct {
    int G[2*V][2*V];
    int match[2*V];
    int used[2*V];
    int V;
} BitMatching;

void init(BitMatching *bm, int V) {
    bm->V = V;
    for (int i = 0; i < 2*V; i++) {
        for (int j = 0; j < 2*V; j++) {
            bm->G[i][j] = 0;
        }
        bm->match[i] = -1;
        bm->used[i] = 0;
    }
}

void add(BitMatching *bm, int a, int b) {
    bm->G[a][b+V] = 1;
    bm->G[b+V][a] = 1;
}

int dfs(BitMatching *bm, int v) {
    bm->used[v] = 1;
    for (int u = 0; u < bm->V; u++) {
        if (bm->G[v][u+V] && (bm->match[u+V] == -1 || !bm->used[bm->match[u+V]] && dfs(bm, bm->match[u+V]))) {
            bm->match[v] = u+V;
            bm->match[u+V] = v;
            return 1;
        }
    }
    return 0;
}

int exec(BitMatching *bm) {
    int res = 0;
    for (int v = 0; v < bm->V; v++) {
        if (bm->match[v] == -1) {
            memset(bm->used, 0, sizeof(bm->used));
            if (dfs(bm, v)) {
                res++;
            }
        }
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        BitMatching bm;
        init(&bm, n);
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j]) != 1) {
                    add(&bm, i, j);
                }
            }
        }
        printf("%d\n", exec(&bm));
    }
    return 0;
}
