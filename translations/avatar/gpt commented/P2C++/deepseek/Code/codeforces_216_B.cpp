#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <stdexcept>

std::vector<int> readInts() {
    std::string line;
    std::getline(std::cin, line);
    std::vector<int> result;
    std::stringstream ss(line);
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

void dfs(const std::vector<std::set<int>>& g, std::set<int>& seen, int i, int& nodes, int& edges) {
    if (seen.find(i) != seen.end()) {
        return;
    }
    seen.insert(i);
    nodes++;
    edges += g[i].size();
    for (int j : g[i]) {
        dfs(g, seen, j, nodes, edges);
    }
}

bool solve() {
    auto line0 = readInts();
    if (line0.empty()) {
        return false;
    }
    int n = line0[0], m = line0[1];
    std::vector<std::set<int>> g(n + 1);
    std::set<int> seen;
    for (int i = 1; i <= n; ++i) {
        g[i] = std::set<int>();
    }
    for (int i = 0; i < m; ++i) {
        auto edge = readInts();
        int a = edge[0], b = edge[1];
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (seen.find(i) == seen.end()) {
            int nodes = 0, edges = 0;
            dfs(g, seen, i, nodes, edges);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        ans++;
    }
    std::cout << ans << std::endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
