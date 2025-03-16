#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MN 520

typedef struct {
    int G[2*MN];
    int match[2*MN];
    int used[2*MN];
} BitMatching;

void init(BitMatching *bm) {
    for (int i = 0; i < 2*MN; i++) {
        bm->G[i].clear();
    }
}

void add(BitMatching *bm, int a, int b) {
    bm->G[a].push_back(b + MN);
    bm->G[b + MN].push_back(a);
}

bool dfs(BitMatching *bm, int v) {
    bm->used[v] = true;
    for (int i = 0; i < bm->G[v].size(); i++) {
        int u = bm->G[v][i], w = bm->match[u];
        if (w < 0 || (!bm->used[w] && dfs(bm, w))) {
            bm->match[v] = u;
            bm->match[u] = v;
            return true;
        }
    }
    return false;
}

int exec(BitMatching *bm) {
    int res = 0;
    memset(bm->match, -1, sizeof(bm->match));
    for (int v = 0; v < MN; v++) {
        if (bm->match[v] < 0) {
            memset(bm->used, 0, sizeof(bm->used));
            if (dfs(bm, v)) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    while (true) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (!n) break;

        BitMatching bm;
        init(&bm);
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j])!= 1) {
                    add(&bm, i, j);
                }
            }
        }

        printf("%d\n", exec(&bm));
    }
    return 0;
}

