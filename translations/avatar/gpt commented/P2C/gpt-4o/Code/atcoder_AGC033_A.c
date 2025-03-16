#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int h, w;
    // Read the height (h) and width (w) of the graph from input
    scanf("%d %d", &h, &w);

    // Initialize the graph
    int **graph = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        graph[i] = (int *)malloc(w * sizeof(int));
        for (int j = 0; j < w; j++) {
            char c;
            scanf(" %c", &c); // Read each character
            if (c == '#') {
                graph[i][j] = 0; // Obstacle
            } else {
                graph[i][j] = INT_MAX; // Unvisited cells
            }
        }
    }

    // Update the graph by calculating the minimum distance from the left side
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x + 1] = (graph[y][x] + 1 < graph[y][x + 1]) ? graph[y][x] + 1 : graph[y][x + 1];
            }
        }
    }

    // Update the graph by calculating the minimum distance from the right side
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x - 1] = (graph[y][x] + 1 < graph[y][x - 1]) ? graph[y][x] + 1 : graph[y][x - 1];
            }
        }
    }

    // Update the graph by calculating the minimum distance from the top side
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] != INT_MAX) {
                graph[y + 1][x] = (graph[y][x] + 1 < graph[y + 1][x]) ? graph[y][x] + 1 : graph[y + 1][x];
            }
        }
    }

    // Update the graph by calculating the minimum distance from the bottom side
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] != INT_MAX) {
                graph[y - 1][x] = (graph[y][x] + 1 < graph[y - 1][x]) ? graph[y][x] + 1 : graph[y - 1][x];
            }
        }
    }

    // Find the maximum distance in the graph
    int max_distance = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] != INT_MAX && graph[i][j] > max_distance) {
                max_distance = graph[i][j];
            }
        }
    }

    // Print the maximum distance found in the graph
    printf("%d\n", max_distance);

    // Free allocated memory
    for (int i = 0; i < h; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

// <END-OF-CODE>
