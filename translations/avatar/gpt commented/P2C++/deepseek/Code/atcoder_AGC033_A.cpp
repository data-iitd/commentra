#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int h, w;
    std::cin >> h >> w;

    // Initialize the graph
    std::vector<std::vector<int>> graph(h, std::vector<int>(w, INT_MAX));

    // Read the graph from input
    for (int i = 0; i < h; ++i) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < w; ++j) {
            if (row[j] == '#') {
                graph[i][j] = 0;
            }
        }
    }

    // Update the graph by calculating the minimum distance from the left side
    for (int x = 0; x < w - 1; ++x) {
        for (int y = 0; y < h; ++y) {
            if (graph[y][x] != 0) {
                graph[y][x + 1] = std::min(graph[y][x] + 1, graph[y][x + 1]);
            }
        }
    }

    // Update the graph by calculating the minimum distance from the right side
    for (int x = w - 1; x > 0; --x) {
        for (int y = 0; y < h; ++y) {
            if (graph[y][x] != 0) {
                graph[y][x - 1] = std::min(graph[y][x] + 1, graph[y][x - 1]);
            }
        }
    }

    // Update the graph by calculating the minimum distance from the top side
    for (int y = 0; y < h - 1; ++y) {
        for (int x = 0; x < w; ++x) {
            if (graph[y][x] != 0) {
                graph[y + 1][x] = std::min(graph[y][x] + 1, graph[y + 1][x]);
            }
        }
    }

    // Update the graph by calculating the minimum distance from the bottom side
    for (int y = h - 1; y > 0; --y) {
        for (int x = 0; x < w; ++x) {
            if (graph[y][x] != 0) {
                graph[y - 1][x] = std::min(graph[y][x] + 1, graph[y - 1][x]);
            }
        }
    }

    // Find the maximum distance found in the graph
    int max_distance = 0;
    for (const auto& row : graph) {
        for (int distance : row) {
            if (distance != 0) {
                max_distance = std::max(max_distance, distance);
            }
        }
    }

    // Print the maximum distance
    std::cout << max_distance << std::endl;

    return 0;
}
