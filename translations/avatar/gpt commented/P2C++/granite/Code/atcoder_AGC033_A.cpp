
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<int>> graph(h, std::vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < w; j++) {
            graph[i][j] = (row[j] == '#'? 0 : INT_MAX);
        }
    }

    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            graph[y][x + 1] = std::min(graph[y][x] + 1, graph[y][x + 1]);
        }
    }

    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            graph[y][x - 1] = std::min(graph[y][x] + 1, graph[y][x - 1]);
        }
    }

    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            graph[y + 1][x] = std::min(graph[y][x] + 1, graph[y + 1][x]);
        }
    }

    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            graph[y - 1][x] = std::min(graph[y][x] + 1, graph[y - 1][x]);
        }
    }

    int maxDistance = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            maxDistance = std::max(maxDistance, graph[y][x]);
        }
    }

    std::cout << maxDistance << std::endl;

    return 0;
}
