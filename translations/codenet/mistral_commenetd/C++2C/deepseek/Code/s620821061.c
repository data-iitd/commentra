#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MN 520

typedef long long ll;

typedef struct {
    int G[2 * MN][2 * MN];
    int match[2 * MN];
    int used[2 * MN];
} BitMatching;

BitMatching bm;

void init(BitMatching *bm) {
    for (int i = 0; i < 2 * MN; i++) {
        for (int j = 0; j < 2 * MN; j++) {
            bm->G[i][j] = 0;
        }
    }
}

void add(BitMatching *bm, int a, int b) {
    bm->G[a][b + MN] = 1;
    bm->G[b + MN][a] = 1;
}

int dfs(BitMatching *bm, int v) {
    bm->used[v] = 1;

    for (int i = 0; i < 2 * MN; i++) {
        if (bm->G[v][i] && (bm->match[i] == -1 || (!bm->used[bm->match[i]] && dfs(bm, bm->match[i])))) {
            bm->match[v] = i;
            bm->match[i] = v;
            return 1;
        }
    }
    return 0;
}

int exec(BitMatching *bm) {
    int res = 0;
    memset(bm->match, -1, sizeof(bm->match));

    for (int v = 0; v < MN; v++) {
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
    return gcd(b, a % b);
}

int main() {
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);

        if (n == 0) break;

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
                if (gcd(a[i], b[j]) != 1) {
                    add(&bm, i, j);
                }
            }
        }

        printf("%d\n", exec(&bm));
    }

    return 0;
}
