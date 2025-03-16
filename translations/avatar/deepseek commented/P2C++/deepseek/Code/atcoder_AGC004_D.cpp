#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n, k;
vector<int> links[MAXN];
int cut_count;

void dfs(int v, int p) {
    int height_from_leaf = 0;
    for (int u : links[v]) {
        if (u == 0) continue;
        dfs(u, v);
        height_from_leaf = max(height_from_leaf, height_from_leaf);
        cut_count += cut_count;
    }
    height_from_leaf += 1;
    if (p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    vector<int> aaa(n);
    for (int i = 0; i < n; ++i) {
        cin >> aaa[i];
        aaa[i]--;
        links[aaa[i]].push_back(i);
    }

    cut_count = 0;
    dfs(0, 0);

    if (aaa[0] != 1) {
        cut_count += 1;
    }

    cout << cut_count << '\n';

    return 0;
}
