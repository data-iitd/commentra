
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int root(vector<int>& par, vector<int>& rank, int x) {
    if (par[x] == x) return x;
    else return par[x] = root(par, rank, par[x]);
}

bool same(vector<int>& par, vector<int>& rank, int x, int y) {
    return root(par, rank, x) == root(par, rank, y);
}

void unite(vector<int>& par, vector<int>& rank, vector<int>& size, int x, int y) {
    int rx = root(par, rank, x);
    int ry = root(par, rank, y);
    if (rx!= ry) {
        if (rank[rx] < rank[ry]) {
            par[rx] = ry;
            size[ry] += size[rx];
        } else {
            par[ry] = rx;
            size[rx] += size[ry];
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }
}

int main() {
    ifstream ifs("1.txt");
    string line;
    getline(ifs, line);
    int n = stoi(line);
    vector<int> par(n);
    vector<int> rank(n, 1);
    vector<int> size(n, 1);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        getline(ifs, line);
        b[stoi(line) - 1] = i;
    }
    long long c = 0;
    for (int k = n - 1; k >= 0; k--) {
        int l = 1, r = 1;
        if (k > 0 && b[k - 1] > b[k]) {
            l += size[root(par, rank, k - 1)];
            unite(par, rank, size, k - 1, k);
        }
        if (k + 1 < n && b[k + 1] > b[k]) {
            r += size[root(par, rank, k + 1)];
            unite(par, rank, size, k + 1, k);
        }
        c += l * r * (b[k] + 1);
    }
    cout << c << endl;
    return 0;
}
