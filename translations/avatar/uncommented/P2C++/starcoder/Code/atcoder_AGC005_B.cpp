#include <bits/stdc++.h>
using namespace std;
int n, a[100000], par[100000], rank[100000], size[100000], c = 0;
int root(int x) { return x == par[x]? x : par[x] = root(par[x]); }
bool same(int x, int y) { return root(x) == root(y); }
void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x!= y) {
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
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) par[i] = i, rank[i] = 1, size[i] = 1;
    for (int i = 0; i < n; i++) {
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
    cout << c << endl;
}
