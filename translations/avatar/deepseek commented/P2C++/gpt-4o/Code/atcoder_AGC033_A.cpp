#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    // Read the dimensions of the grid
    int h, w;
    cin >> h >> w;

    // Initialize the grid with 0 for '#' and inf for '.'
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

    // Calculate the minimum distance to any '#' for each cell in the grid
    // Processing in the left to right direction
    for (int x = 0; x < w - 1; ++x) {
        for (int y = 0; y < h; ++y) {
            graph[y][x + 1] = min(graph[y][x] + 1, graph[y][x + 1]);
        }
    }

    // Processing in the right to left direction
    for (int x = w - 1; x > 0; --x) {
        for (int y = 0; y < h; ++y) {
            graph[y][x - 1] = min(graph[y][x] + 1, graph[y][x - 1]);
        }
    }

    // Processing in the top to bottom direction
    for (int y = 0; y < h - 1; ++y) {
        for (int x = 0; x < w; ++x) {
            graph[y + 1][x] = min(graph[y][x] + 1, graph[y + 1][x]);
        }
    }

    // Processing in the bottom to top direction
    for (int y = h - 1; y > 0; --y) {
        for (int x = 0; x < w; ++x) {
            graph[y - 1][x] = min(graph[y][x] + 1, graph[y - 1][x]);
        }
    }

    // Print the maximum value in the grid, which represents the maximum distance to the nearest '#'
    int max_distance = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            max_distance = max(max_distance, graph[i][j]);
        }
    }
    cout << max_distance << endl;

    return 0;
}

// <END-OF-CODE>
