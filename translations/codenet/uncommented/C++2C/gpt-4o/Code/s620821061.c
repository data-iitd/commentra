#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MN 520

typedef long long ll;

<<<<<<< HEAD
struct BitMatching {
=======
typedef struct {
>>>>>>> 98c87cb78a (data updated)
    int G[2 * MN][2 * MN]; // Adjacency list representation
    int match[2 * MN];
    int used[2 * MN];
    int size[2 * MN]; // To keep track of the size of each adjacency list
<<<<<<< HEAD

    void init() {
        for (int i = 0; i < 2 * MN; i++) {
            size[i] = 0; // Initialize size of each list
        }
    }

    void add(int a, int b) {
        G[a][size[a]++] = b + MN; // Add b + MN to a's list
        G[b + MN][size[b + MN]++] = a; // Add a to b's list
    }

    int dfs(int v) {
        used[v] = 1;
        for (int i = 0; i < size[v]; i++) {
            int u = G[v][i], w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return 1;
            }
        }
        return 0;
    }

    int exec() {
        int res = 0;
        memset(match, -1, sizeof(match));
        for (int v = 0; v < MN; v++) {
            if (match[v] < 0) {
                memset(used, 0, sizeof(used));
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }
};
=======
} BitMatching;

void init(BitMatching *bm) {
    for (int i = 0; i < 2 * MN; i++) {
        bm->size[i] = 0; // Initialize size of each list
    }
}

void add(BitMatching *bm, int a, int b) {
    bm->G[a][bm->size[a]++] = b + MN; // Add edge a -> b + V
    bm->G[b + MN][bm->size[b + MN]++] = a; // Add edge b + V -> a
}

int dfs(BitMatching *bm, int v) {
    bm->used[v] = 1;
    for (int i = 0; i < bm->size[v]; i++) {
        int u = bm->G[v][i], w = bm->match[u];
        if (w < 0 || (!bm->used[w] && dfs(bm, w))) {
            bm->match[v] = u;
            bm->match[u] = v;
            return 1;
        }
    }
    return 0;
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
>>>>>>> 98c87cb78a (data updated)

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
<<<<<<< HEAD
    struct BitMatching bm;
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (!n) break;
        bm.init();
=======
    BitMatching bm;
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        init(&bm);
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
                    bm.add(i, j);
                }
            }
        }
        printf("%d\n", bm.exec());
=======
                    add(&bm, i, j);
                }
            }
        }
        printf("%d\n", exec(&bm));
>>>>>>> 98c87cb78a (data updated)
    }
    return 0;
}

// <END-OF-CODE>
