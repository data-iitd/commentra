#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
#define rep(i,l,r) for(ll i=(l); i<(r); i++)
#define max(p,q) ((p)>(q) ? (p) : (q))

// Edge information structure
struct Edge {
    ll s, g, c;
};

struct Graph {
    int vcnt, ecnt;
    std::vector<Edge> e; // Use vector for dynamic sizing
    std::vector<int> id; // Use vector for dynamic sizing

    Graph(int n) : vcnt(n), ecnt(2 * n - 2), e(2 * n - 2), id(n + 1) {}
};

bool esort(const Edge &p, const Edge &q) {
    if (p.s < q.s) return true;
    if (p.s > q.s) return false;
    return p.g < q.g;
}

void readGraph(Graph &g) {
    ll n;
    std::cin >> n;
    rep(i, 0, n - 1) {
        ll x, y, c;
        std::cin >> x >> y >> c;
        g.e[2 * i] = {x, y, c};
        g.e[2 * i + 1] = {y, x, c};
    }
    qsort(g.e.data(), g.ecnt, sizeof(Edge), [](const void *a, const void *b) {
        return esort(*(const Edge *)a, *(const Edge *)b) ? -1 : 1;
    });

    int p = 0;
    rep(i, 0, g.vcnt) {
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p;
    }
    g.id[g.vcnt] = g.ecnt; // Sentinel
}

// Function to find the diameter of the tree using DFS
int *tyokkeitemp;

void tyokkeidfs(Graph &g, ll s) {
    for (int i = g.id[s]; i < g.id[s + 1]; i++) {
        if (tyokkeitemp[g.e[i].g] == 0) {
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
            tyokkeidfs(g, g.e[i].g);
        }
    }
}

int tyokkei(Graph &g) {
    tyokkeitemp = (int *)calloc(g.vcnt + 10, sizeof(int));
    tyokkeitemp[0] = 1;
    tyokkeidfs(g, 0);
    int M = 0, Mi;
    rep(i, 0, g.vcnt) {
        if (tyokkeitemp[i] > M) {
            M = tyokkeitemp[i];
            Mi = i;
        }
    }
    rep(i, 0, g.vcnt) tyokkeitemp[i] = 0;
    tyokkeitemp[Mi] = 1;
    tyokkeidfs(g, Mi);
    rep(i, 0, g.vcnt) M = max(M, tyokkeitemp[i]);
    free(tyokkeitemp);
    return M - 1;
}

int main() {
    ll n;
    std::cin >> n;
    Graph g(n);
    readGraph(g);
    std::cout << tyokkei(g) << std::endl;
    return 0;
}

// <END-OF-CODE>
