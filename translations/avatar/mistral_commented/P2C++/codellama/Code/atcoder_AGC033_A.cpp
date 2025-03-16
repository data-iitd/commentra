#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> graph(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
        }
    }

    for (int x = 0; x < w - 1; x++) {
        for (int i = 0; i < h; i++) {
            graph[i][x + 1] = min(graph[i][x] + 1, graph[i][x + 1]);
        }
    }

    for (int x = w - 1; x > 0; x--) {
        for (int i = 0; i < h; i++) {
            graph[i][x - 1] = min(graph[i][x] + 1, graph[i][x - 1]);
        }
    }

    for (int y = 0; y < h - 1; y++) {
        for (int i = 0; i < w; i++) {
            graph[y + 1][i] = min(graph[y][i] + 1, graph[y + 1][i]);
        }
    }

    for (int y = h - 1; y > 0; y--) {
        for (int i = 0; i < w; i++) {
            graph[y - 1][i] = min(graph[y][i] + 1, graph[y - 1][i]);
        }
    }

    int max_distance = numeric_limits<int>::min();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            max_distance = max(max_distance, graph[i][j]);
        }
    }

    cout << max_distance << endl;

    return 0;
}

