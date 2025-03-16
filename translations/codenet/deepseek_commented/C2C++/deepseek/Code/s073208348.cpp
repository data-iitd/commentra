#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define ll long long
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define max(p, q) ((p) > (q) ? (p) : (q))

// 辺の情報を個別に持つタイプ
struct edge {
    ll s, g, c;
};

struct graph {
    int vcnt, ecnt;
    vector<edge> e;
    vector<int> id;
};

bool esort(const edge& a, const edge& b) {
    if (a.s != b.s) return a.s < b.s;
    if (a.g != b.g) return a.g < b.g;
    return a.c < b.c;
}

graph g;

void readgraph() {
    ll n;
    cin >> n;
    g.e.resize(2 * n - 2);
    g.id.resize(n + 1);
    rep(i, 0, n - 1) {
        ll x, y, c;
        cin >> x >> y >> c;
        g.e[2 * i] = { x, y, c };
        g.e[2 * i + 1] = { y, x, c };
    }
    g.vcnt = n;
    g.ecnt = 2 * n - 2;
    sort(g.e.begin(), g.e.end(), esort);

    int p = 0;
    rep(i, 0, g.vcnt) {
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p;
    }
    g.id[g.vcnt] = g.ecnt;
}

// 木の直径を求める2回dfs
int* tyokkeitemp;
void tyokkeidfs(ll s) {
    for (int i = g.id[s]; i < g.id[s + 1]; i++) {
        if (tyokkeitemp[g.e[i].g] == 0) {
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
            tyokkeidfs(g.e[i].g);
        }
    }
}

int tyokkei() {
    tyokkeitemp = (int*)calloc(g.vcnt + 10, sizeof(int));
    tyokkeitemp[0] = 1;
    tyokkeidfs(0);
    int M = 0, Mi;
    rep(i, 0, g.vcnt) {
        if (tyokkeitemp[i] > M) {
            M = tyokkeitemp[i];
            Mi = i;
        }
    }
    rep(i, 0, g.vcnt) tyokkeitemp[i] = 0;
    tyokkeitemp[Mi] = 1;
    tyokkeidfs(Mi);
    rep(i, 0, g.vcnt) M = max(M, tyokkeitemp[i]);
    free(tyokkeitemp);
    return M - 1;
}

int main() {
    readgraph();
    cout << tyokkei() << endl;
}
