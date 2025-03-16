#include <iostream>
#include <vector>
#include <algorithm>

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
    for (int j = 0; j < w - 1; j++) {
        for (int i = 0; i < h; i++) {
            graph[i][j + 1] = min(graph[i][j] + 1, graph[i][j + 1]);
        }
    }
    for (int j = w - 1; j > 0; j--) {
        for (int i = 0; i < h; i++) {
            graph[i][j - 1] = min(graph[i][j] + 1, graph[i][j - 1]);
        }
    }
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            graph[i + 1][j] = min(graph[i][j] + 1, graph[i + 1][j]);
        }
    }
    for (int i = h - 1; i > 0; i--) {
        for (int j = 0; j < w; j++) {
            graph[i - 1][j] = min(graph[i][j] + 1, graph[i - 1][j]);
        }
    }
    cout << *max_element(graph.begin(), graph.end()) << endl;
    return 0;
}

