#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    // Read the height (h) and width (w) of the graph from input
    int h, w;
    cin >> h >> w;

    // Initialize the graph: 
    // Replace '#' with 0 (indicating an obstacle) and other characters with infinity (indicating unvisited cells)
    vector<vector<int>> graph(h, vector<int>(w, numeric_limits<int>::max()));
    for (int i = 0; i < h; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < w; ++j) {
            if (row[j] == '#') {
                graph[i][j] = 0; // Obstacle
            }
        }
    }

    // Update the graph by calculating the minimum distance from the left side
    for (int x = 0; x < w - 1; ++x) {
        for (int y = 0; y < h; ++y) {
            graph[y][x + 1] = min(graph[y][x] + 1, graph[y][x + 1]);
        }
    }

    // Update the graph by calculating the minimum distance from the right side
    for (int x = w - 1; x > 0; --x) {
        for (int y = 0; y < h; ++y) {
            graph[y][x - 1] = min(graph[y][x] + 1, graph[y][x - 1]);
        }
    }

    // Update the graph by calculating the minimum distance from the top side
    for (int y = 0; y < h - 1; ++y) {
        for (int x = 0; x < w; ++x) {
            graph[y + 1][x] = min(graph[y][x] + 1, graph[y + 1][x]);
        }
    }

    // Update the graph by calculating the minimum distance from the bottom side
    for (int y = h - 1; y > 0; --y) {
        for (int x = 0; x < w; ++x) {
            graph[y - 1][x] = min(graph[y][x] + 1, graph[y - 1][x]);
        }
    }

    // Print the maximum distance found in the graph, which represents the farthest distance from an obstacle
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
