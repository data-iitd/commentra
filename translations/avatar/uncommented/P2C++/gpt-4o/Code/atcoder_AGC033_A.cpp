#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> graph(h, vector<int>(w, numeric_limits<int>::max()));

    for (int i = 0; i < h; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < w; ++j) {
            if (row[j] == '#') {
                graph[i][j] = 0;
            }
        }
    }

    for (int x = 0; x < w - 1; ++x) {
        for (int y = 0; y < h; ++y) {
            graph[y][x + 1] = min(graph[y][x] + 1, graph[y][x + 1]);
        }
    }

    for (int x = w - 1; x > 0; --x) {
        for (int y = 0; y < h; ++y) {
            graph[y][x - 1] = min(graph[y][x] + 1, graph[y][x - 1]);
        }
    }

    for (int y = 0; y < h - 1; ++y) {
        for (int x = 0; x < w; ++x) {
            graph[y + 1][x] = min(graph[y][x] + 1, graph[y + 1][x]);
        }
    }

    for (int y = h - 1; y > 0; --y) {
        for (int x = 0; x < w; ++x) {
            graph[y - 1][x] = min(graph[y][x] + 1, graph[y - 1][x]);
        }
    }

    int max_value = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            max_value = max(max_value, graph[i][j]);
        }
    }

    cout << max_value << endl;

    return 0;
}

// <END-OF-CODE>
