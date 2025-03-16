#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Read the dimensions of the grid
    int h, w;
    scanf("%d %d", &h, &w);

    // Initialize the grid
    int **graph = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        graph[i] = (int *)malloc(w * sizeof(int));
    }

    // Read the grid and initialize distances
    for (int i = 0; i < h; i++) {
        char row[w + 1]; // +1 for null terminator
        scanf("%s", row);
        for (int j = 0; j < w; j++) {
            if (row[j] == '#') {
                graph[i][j] = 0; // Distance to '#' is 0
            } else {
                graph[i][j] = INT_MAX; // Distance to '.' is infinity
            }
        }
    }

    // Processing in the left to right direction
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x] < INT_MAX) {
                graph[y][x + 1] = (graph[y][x] + 1 < graph[y][x + 1]) ? graph[y][x] + 1 : graph[y][x + 1];
            }
        }
    }

    // Processing in the right to left direction
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x] < INT_MAX) {
                graph[y][x - 1] = (graph[y][x] + 1 < graph[y][x - 1]) ? graph[y][x] + 1 : graph[y][x - 1];
            }
        }
    }

    // Processing in the top to bottom direction
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] < INT_MAX) {
                graph[y + 1][x] = (graph[y][x] + 1 < graph[y + 1][x]) ? graph[y][x] + 1 : graph[y + 1][x];
            }
        }
    }

    // Processing in the bottom to top direction
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] < INT_MAX) {
                graph[y - 1][x] = (graph[y][x] + 1 < graph[y - 1][x]) ? graph[y][x] + 1 : graph[y - 1][x];
            }
        }
    }

    // Find the maximum value in the grid
    int max_distance = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] < INT_MAX) {
                if (graph[i][j] > max_distance) {
                    max_distance = graph[i][j];
                }
            }
        }
    }

    // Print the maximum value, which represents the maximum distance to the nearest '#'
    printf("%d\n", max_distance);

    // Free allocated memory
    for (int i = 0; i < h; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

// <END-OF-CODE>
