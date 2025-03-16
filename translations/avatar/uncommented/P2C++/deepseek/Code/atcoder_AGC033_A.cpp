#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> graph(h, std::vector<int>(w, INT_MAX));

    for (int y = 0; y < h; ++y) {
        std::string row;
        std::cin >> row;
        for (int x = 0; x < w; ++x) {
            if (row[x] == '#') {
                graph[y][x] = 0;
            }
        }
    }

    for (int x = 0; x < w - 1; ++x) {
        for (int y = 0; y < h; ++y) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x + 1] = std::min(graph[y][x] + 1, graph[y][x + 1]);
            }
        }
    }

    for (int x = w - 1; x > 0; --x) {
        for (int y = 0; y < h; ++y) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x - 1] = std::min(graph[y][x] + 1, graph[y][x - 1]);
            }
        }
    }

    for (int y = 0; y < h - 1; ++y) {
        for (int x = 0; x < w; ++x) {
            if (graph[y][x] != INT_MAX) {
                graph[y + 1][x] = std::min(graph[y][x] + 1, graph[y + 1][x]);
            }
        }
    }

    for (int y = h - 1; y > 0; --y) {
        for (int x = 0; x < w; ++x) {
            if (graph[y][x] != INT_MAX) {
                graph[y - 1][x] = std::min(graph[y][x] + 1, graph[y - 1][x]);
            }
        }
    }

    int max_distance = 0;
    for (const auto& row : graph) {
        for (int distance : row) {
            if (distance != INT_MAX) {
                max_distance = std::max(max_distance, distance);
            }
        }
    }

    std::cout << max_distance << std::endl;

    return 0;
}
