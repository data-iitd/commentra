#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int h, w;
    scanf("%d %d", &h, &w);

    // Initialize the grid with 0 for '.' and INT_MAX for '#'
    int** graph = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        graph[i] = (int*)malloc(w * sizeof(int));
        char line[w + 1];
        scanf("%s", line);
        for (int j = 0; j < w; j++) {
            graph[i][j] = (line[j] == '#') ? INT_MAX : 0;
        }
    }

    // Calculate the minimum distance to any '#' for each cell in the grid
    // Processing in the left to right direction
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x + 1] > graph[y][x] + 1) {
                graph[y][x + 1] = graph[y][x] + 1;
            }
        }
    }

    // Processing in the right to left direction
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x - 1] > graph[y][x] + 1) {
                graph[y][x - 1] = graph[y][x] + 1;
            }
        }
    }

    // Processing in the top to bottom direction
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            if (graph[y + 1][x] > graph[y][x] + 1) {
                graph[y + 1][x] = graph[y][x] + 1;
            }
        }
    }

    // Processing in the bottom to top direction
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            if (graph[y - 1][x] > graph[y][x] + 1) {
                graph[y - 1][x] = graph[y][x] + 1;
            }
        }
    }

    // Find the maximum value in the grid, which represents the maximum distance to the nearest '#'
    int max_distance = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] > max_distance) {
                max_distance = graph[y][x];
            }
        }
    }

    // Print the maximum distance
    printf("%d\n", max_distance);

    // Free allocated memory
    for (int i = 0; i < h; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
