#include <iostream>
#include <vector>
#include <numeric> // for std::iota

using namespace std;

// Function to find the root of a given element in a disjoint set
int root(int x, vector<int>& par) {
    return par[x] == x ? x : root(par[x], par);
}

// Function to check if two elements are in the same set
bool same(int x, int y, vector<int>& par) {
    return root(x, par) == root(y, par);
}

// Function to merge two sets containing the given elements
void unite(int x, int y, vector<int>& par, vector<int>& rank, vector<int>& size) {
    x = root(x, par);
    y = root(y, par);
    if (x != y) {
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
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

    vector<int> par(n);
    iota(par.begin(), par.end(), 0);
    vector<int> rank(n, 1);
    vector<int> size(n, 1);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        b[a[i] - 1] = i;
    }

    long long c = 0;

    for (int k : b) {
        int l = 1, r = 1;
        if (k > 0 && a[k - 1] > a[k]) {
            l += size[root(k - 1, par)];
            unite(k - 1, k, par, rank, size);
        }
        if (k + 1 < n && a[k + 1] > a[k]) {
            r += size[root(k + 1, par)];
            unite(k + 1, k, par, rank, size);
        }
        c += static_cast<long long>(l) * r * a[k];
    }

    cout << c << endl;

    return 0;
}
