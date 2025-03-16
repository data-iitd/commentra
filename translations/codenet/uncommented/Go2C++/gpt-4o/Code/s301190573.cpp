#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

const int size = 1000000;
vector<int> par, rank;

void initialize(int n) {
    par.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int root(int i) {
    if (par[i] == i) return i;
    par[i] = root(par[i]);
    return par[i];
}

bool same(int i, int j) {
    return root(i) == root(j);
}

void unite(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        par[i] = j;
    } else {
        par[j] = i;
        if (rank[i] == rank[j]) rank[i]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--; // Adjusting to 0-based index
    }
    
    initialize(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        unite(x - 1, y - 1); // Adjusting to 0-based index
    }
    
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) {
            s++;
        }
    }
    
    cout << s << endl;
    return 0;
}

// <END-OF-CODE>
