#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#define ll long long
#define rep(i, l, r) for(ll i = (l); i < (r); i++)
#define repp(i, l, r, k) for(ll i = (l); i < (r); i += (k))
#define INF ((1LL << 62) - (1LL << 31))
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))
#define bit(n, m) (((n) >> (m)) & 1)

//#define MOD 998244353
#define MOD 1000000007
#define invp(a, p) pow_mod(a, p - 2, p)

//辺の情報を個別に持つタイプ

struct Edge {
    ll p, i;
    char s[20];
};

int esort(const void* a, const void* b) {
    Edge* p = (Edge*)a, * q = (Edge*)b;
    int cmp = strcmp(p->s, q->s);
    if (cmp != 0) return cmp;
    if (p->p < q->p) return 1;
    return -1;
}

Edge data[100];
ll n, m;

int main() {
    std::cin >> n;
    rep(i, 0, n) {
        std::cin >> data[i].s >> data[i].p;
        data[i].i = i;
    }
    std::qsort(data, n, sizeof(Edge), [](const void* a, const void* b) {
        Edge* p = (Edge*)a, * q = (Edge*)b;
        int cmp = strcmp(p->s, q->s);
        if (cmp != 0) return cmp;
        if (p->p < q->p) return 1;
        return -1;
    });
    rep(i, 0, n) {
        std::cout << data[i].i + 1 << std::endl;
    }
}

