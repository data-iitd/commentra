#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    // Initialize the grid with 0 for '.' and INT_MAX for '#'
    vector<vector<int>> graph(h, vector<int>(w, INT_MAX));

    // Read the grid
    for (int y = 0; y < h; ++y) {
        string row;
        cin >> row;
        for (int x = 0; x < w; ++x) {
            if (row[x] == '#') {
                graph[y][x] = 0;
            } else {
                graph[y][x] = INT_MAX;
            }
        }
    }

    // Calculate the minimum distance to any '#' for each cell in the grid
    // Processing in the left to right direction
    for (int x = 0; x < w - 1; ++x) {
        for (int y = 0; y < h; ++y) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x + 1] = min(graph[y][x] + 1, graph[y][x + 1]);
            }
        }
    }

    // Processing in the right to left direction
    for (int x = w - 1; x > 0; --x) {
        for (int y = 0; y < h; ++y) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x - 1] = min(graph[y][x] + 1, graph[y][x - 1]);
            }
        }
    }

    // Processing in the top to bottom direction
    for (int y = 0; y < h - 1; ++y) {
        for (int x = 0; x < w; ++x) {
            if (graph[y][x] != INT_MAX) {
                graph[y + 1][x] = min(graph[y][x] + 1, graph[y + 1][x]);
            }
        }
    }

    // Processing in the bottom to top direction
    for (int y = h - 1; y > 0; --y) {
        for (int x = 0; x < w; ++x) {
            if (graph[y][x] != INT_MAX) {
                graph[y - 1][x] = min(graph[y][x] + 1, graph[y - 1][x]);
            }
        }
    }

    // Find the maximum value in the grid, which represents the maximum distance to the nearest '#'
    int max_distance = 0;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (graph[y][x] != INT_MAX) {
                max_distance = max(max_distance, graph[y][x]);
            }
        }
    }

    // Print the maximum distance to the nearest '#'
    cout << max_distance << endl;

    return 0;
}
