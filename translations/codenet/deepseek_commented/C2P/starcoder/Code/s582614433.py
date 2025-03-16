#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define repp(i, l, r, k) for (ll i = (l); i < (r); i += (k))
#define max(p, q) ((p) > (q)? (p) : (q))
#define min(p, q) ((p) < (q)? (p) : (q))
#define bit(n, m) (((n) >> (m)) & 1)
#define MOD 1000000007
#define invp(a, p) pom(a, p - 2, p)

typedef struct edge {
    ll p;
    int i;
    char s[20];
} E;

int esort(const void* a, const void* b) {
    E* p = (E*)a, * q = (E*)b;
    int cmp = strcmp(p->s, q->s);
    if (cmp) return cmp;
    if (p->p < q->p) return 1;
    return -1;
}

E data[100];
ll n, m;

int main() {
    scanf("%lld", &n);
    rep(i, 0, n) {
        scanf(" %s%lld", data[i].s, &data[i].p);
        data[i].i = i;
    }
    qsort(data, n, sizeof(E), esort);
    rep(i, 0, n) printf("%lld\n", data[i].i + 1);
}

