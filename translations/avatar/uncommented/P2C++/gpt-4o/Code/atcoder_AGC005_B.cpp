#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> par, rank, size;

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    par.resize(n);
    iota(par.begin(), par.end(), 0);
    rank.assign(n, 1);
    size.assign(n, 1);
    vector<int> b(n, 0);
    
    for (int i = 0; i < n; ++i) {
        b[a[i] - 1] = i;
    }

    long long c = 0;
    for (int k = n - 1; k >= 0; --k) {
        int l = 1, r = 1;
        if (k > 0 && a[k - 1] > a[k]) {
            l += size[root(k - 1)];
            unite(k - 1, k);
        }
        if (k + 1 < n && a[k + 1] > a[k]) {
            r += size[root(k + 1)];
            unite(k + 1, k);
        }
        c += l * r * a[k];
    }
    
    cout << c << endl;
    return 0;
}

// <END-OF-CODE>
