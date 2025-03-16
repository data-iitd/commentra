
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Taking input dimensions of the graph
    int h, w;
    std::cin >> h >> w;

    // Initializing the graph as a 2D vector with initial values
    std::vector<std::vector<int>> graph(h, std::vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < w; j++) {
            graph[i][j] = (row[j] == '#'? 0 : INT_MAX);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            graph[y][x + 1] = std::min(graph[y][x + 1], graph[y][x] + 1);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            graph[y][x - 1] = std::min(graph[y][x - 1], graph[y][x] + 1);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            graph[y + 1][x] = std::min(graph[y + 1][x], graph[y][x] + 1);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            graph[y - 1][x] = std::min(graph[y - 1][x], graph[y][x] + 1);
        }
    }

    // Finding and printing the maximum shortest path distance in the graph
    int maxDistance = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            maxDistance = std::max(maxDistance, graph[y][x]);
        }
    }
    std::cout << maxDistance << std::endl;

    return 0;
}
