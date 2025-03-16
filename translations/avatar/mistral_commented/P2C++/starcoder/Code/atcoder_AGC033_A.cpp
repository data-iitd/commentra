#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> graph(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j < w - 1) {
                graph[i][j] = min(graph[i][j] + 1, graph[i][j + 1]);
            }
            if (j > 0) {
                graph[i][j] = min(graph[i][j] + 1, graph[i][j - 1]);
            }
            if (i < h - 1) {
                graph[i][j] = min(graph[i][j] + 1, graph[i + 1][j]);
            }
            if (i > 0) {
                graph[i][j] = min(graph[i][j] + 1, graph[i - 1][j]);
            }
        }
    }
    cout << *max_element(graph.begin(), graph.end()) << endl;
    return 0;
}

