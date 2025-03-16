#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n, k;
vector<int> links[MAXN];
bool visited[MAXN];

int dfs(int v, int p) {
    visited[v] = true;
    int height_from_leaf = 0;
    int cut_count = 0;
    for (int u : links[v]) {
        if (!visited[u]) {
            int hgt = dfs(u, v);
            height_from_leaf = max(height_from_leaf, hgt);
            cut_count++;
        }
    }
    height_from_leaf += 1;
    if (p != -1 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count++;
    }
    return height_from_leaf;
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

    memset(visited, false, sizeof(visited));
    int ans = dfs(0, -1);
    if (aaa[0] != 0) {
        ans++;
    }
    cout << ans << '\n';

    return 0;
}
