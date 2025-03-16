
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 10;
int par[N], rank[N], size[N];

int root(int x) {
    return x == par[x] ? x : root(par[x]);
}

bool same(int x, int y) {
    return root(x) == root(y);
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
}

int main() {
    int n, a[N];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 1;
        size[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long c = 0;
    for (int i = n - 1; i >= 0; i--) {
        int l = 1, r = 1;
        if (i > 0 && a[i - 1] > a[i]) {
            l += size[root(i - 1)];
            unite(i - 1, i);
        }
        if (i + 1 < n && a[i + 1] > a[i]) {
            r += size[root(i + 1)];
            unite(i + 1, i);
        }
        c += l * r * a[i];
    }
    printf("%lld\n", c);
    return 0;
}

