
#include <bits/stdc++.h>
using namespace std;

// Define the operations for the ReRootingSolver
auto f = [](int x, int y) { return x * y % m; };
auto g = [](int v, int p) { return v + 1; };

// Initialize and use the ReRootingSolver to compute the results
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }

    ReRootingSolver<int> s(n, edges, 1, f, g);
    for (int i = 0; i < n; i++) {
        cout << s.Query(i) - 1 << endl;
    }

    return 0;
}

