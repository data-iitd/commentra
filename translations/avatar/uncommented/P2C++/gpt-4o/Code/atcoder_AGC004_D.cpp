#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

pair<int, int> dfs(const vector<set<int>>& links, int n, int k, int v, int p) {
    int height_from_leaf = 0;
    int cut_count = 0;
    
    for (int u : links[v]) {
        if (u == 0) {
            continue;
        }
        auto [hgt, cut] = dfs(links, n, k, u, v);
        height_from_leaf = max(height_from_leaf, hgt);
        cut_count += cut;
    }
    
    height_from_leaf += 1;
    
    if (p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }
    
    return {height_from_leaf, cut_count};
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> aaa(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> aaa[i];
        aaa[i]--; // Convert to 0-based index
    }
    
    vector<set<int>> links(n);
    for (int i = 0; i < n - 1; ++i) {
        links[aaa[i]].insert(i + 1); // i + 1 to maintain the 1-based index in the input
    }
    
    auto [_, ans] = dfs(links, n, k, 0, 0);
    if (aaa[0] != 1) {
        ans += 1;
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
