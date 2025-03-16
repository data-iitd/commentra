#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

#define ll long long
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define repp(i, l, r, k) for (ll i = (l); i < (r); i += (k))
#define INF ((1LL << 62) - (1LL << 31))
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))
#define bit(n, m) (((n) >> (m)) & 1)
#define upll(a, b) return *(ll*)a < *(ll*)b ? -1 : *(ll*)a > *(ll*)b ? 1 : 0;
#define downll(a, b) return *(ll*)a < *(ll*)b ? 1 : *(ll*)a > *(ll*)b ? -1 : 0;

void sortup(ll* a, int n) {
    std::qsort(a, n, sizeof(ll), upll);
}

void sortdown(ll* a, int n) {
    std::qsort(a, n, sizeof(ll), downll);
}

ll pom(ll a, ll n, int m) {
    ll x = 1;
    for (a %= m; n; n /= 2)
        n & 1 ? x = x * a % m : 0,
        a = a * a % m;
    return x;
}

#define MOD 1000000007
#define invp(a, p) pom(a, p - 2, p)

struct Edge {
    ll p, i;
    std::string s;
};

int esort(const void* a, const void* b) {
    Edge* p = (Edge*)a, * q = (Edge*)b;
    if (p->s.compare(q->s)) return p->s.compare(q->s);
    if (p->p < q->p) return 1;
    return -1;
}

Edge data[100];
ll n;

int main() {
    std::cin >> n;
    rep(i, 0, n) {
        std::cin >> data[i].s >> data[i].p;
        data[i].i = i;
    }
    std::qsort(data, n, sizeof(Edge), esort);
    rep(i, 0, n) std::cout << data[i].i + 1 << std::endl;
}

