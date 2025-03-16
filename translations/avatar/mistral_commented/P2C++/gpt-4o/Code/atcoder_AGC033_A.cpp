#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    // Taking input dimensions of the graph
    int h, w;
    cin >> h >> w;

    // Initializing the graph as a 2D vector with initial values
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

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
    for (int x = 0; x < w - 1; ++x) {
        for (int y = 0; y < h; ++y) {
            graph[y][x + 1] = min(graph[y][x + 1], graph[y][x] + 1);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
    for (int x = w - 1; x > 0; --x) {
        for (int y = 0; y < h; ++y) {
            graph[y][x - 1] = min(graph[y][x - 1], graph[y][x] + 1);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
    for (int y = 0; y < h - 1; ++y) {
        for (int x = 0; x < w; ++x) {
            graph[y + 1][x] = min(graph[y + 1][x], graph[y][x] + 1);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
    for (int y = h - 1; y > 0; --y) {
        for (int x = 0; x < w; ++x) {
            graph[y - 1][x] = min(graph[y - 1][x], graph[y][x] + 1);
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

// <END-OF-CODE>
