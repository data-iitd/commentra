#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

vector<int> colors;

void dfs(int node, int length, const unordered_map<int, int>& adjList) {
    if (colors[node] != -1) return;
    if (length % 2 == 0) {
        colors[node] = 0;
    } else {
        colors[node] = 1;
    }
    for (const auto& neighbor : adjList) {
        int neighborNode = neighbor.first;
        int edgeLength = neighbor.second;
        dfs(neighborNode, length + edgeLength, adjList);
    }
}

int main() {
    int n;
    cin >> n;
    int m = n - 1;
    colors.resize(n, -1);
    vector<unordered_map<int, int>> points(n);
    while (m--) {
        int me, you, length;
        cin >> me >> you >> length;
        me--; you--;
        points[me][you] = length;
        points[you][me] = length;
    }
    dfs(0, 0, points[0]);
    for (int c : colors) {
        cout << c << endl;
    }
    return 0;
}
