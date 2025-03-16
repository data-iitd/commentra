#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> graph(h, vector<int>(w, 0));

    for (int i = 0; i < h; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < w; ++j) {
            graph[i][j] = (row[j] == '#') ? 0 : INT_MAX;
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
    for (int x = 0; x < w - 1; ++x) {
        for (int i = 0; i < h; ++i) {
            graph[i][x + 1] = min(graph[i][x] + 1, graph[i][x + 1]);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
    for (int x = w - 1; x > 0; --x) {
        for (int i = 0; i < h; ++i) {
            graph[i][x - 1] = min(graph[i][x] + 1, graph[i][x - 1]);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
    for (int y = 0; y < h - 1; ++y) {
        for (int j = 0; j < w; ++j) {
            graph[y + 1][j] = min(graph[y][j] + 1, graph[y + 1][j]);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
    for (int y = h - 1; y > 0; --y) {
        for (int j = 0; j < w; ++j) {
            graph[y - 1][j] = min(graph[y][j] + 1, graph[y - 1][j]);
        }
    }

    // Finding and printing the maximum shortest path distance in the graph
    int max_distance = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            max_distance = max(max_distance, graph[i][j]);
        }
    }
    cout << max_distance << endl;

    return 0;
}
