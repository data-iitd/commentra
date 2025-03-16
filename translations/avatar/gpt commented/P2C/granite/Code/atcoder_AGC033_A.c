
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the height (h) and width (w) of the graph from input
    int h, w;
    scanf("%d %d", &h, &w);

    // Initialize the graph: 
    // Replace '#' with 0 (indicating an obstacle) and other characters with infinity (indicating unvisited cells)
    int graph[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            scanf(" %c", &c);
            graph[i][j] = (c == '#'? 0 : INT_MAX);
        }
    }

    // Update the graph by calculating the minimum distance from the left side
    for (int x = 1; x < w; x++) {
        // For each column, update the distance from the previous column
        for (int y = 0; y < h; y++) {
            graph[y][x] = graph[y][x] < graph[y][x - 1] + 1? graph[y][x] : graph[y][x - 1] + 1;
        }
    }

    // Update the graph by calculating the minimum distance from the right side
    for (int x = w - 2; x >= 0; x--) {
        // For each column, update the distance from the next column
        for (int y = 0; y < h; y++) {
            graph[y][x] = graph[y][x] < graph[y][x + 1] + 1? graph[y][x] : graph[y][x + 1] + 1;
        }
    }

    // Update the graph by calculating the minimum distance from the top side
    for (int y = 1; y < h; y++) {
        // For each row, update the distance from the previous row
        for (int x = 0; x < w; x++) {
            graph[y][x] = graph[y][x] < graph[y - 1][x] + 1? graph[y][x] : graph[y - 1][x] + 1;
        }
    }

    // Update the graph by calculating the minimum distance from the bottom side
    for (int y = h - 2; y >= 0; y--) {
        // For each row, update the distance from the next row
        for (int x = 0; x < w; x++) {
            graph[y][x] = graph[y][x] < graph[y + 1][x] + 1? graph[y][x] : graph[y + 1][x] + 1;
        }
    }

    // Print the maximum distance found in the graph, which represents the farthest distance from an obstacle
    int max_distance = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] > max_distance) {
                max_distance = graph[i][j];
            }
        }
    }
    printf("%d\n", max_distance);

    return 0;
}
