#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    
    // Allocate memory for the graph
    int **graph = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        graph[i] = (int *)malloc(w * sizeof(int));
    }

    // Read the input and initialize the graph
    for (int i = 0; i < h; i++) {
        char row[w + 1]; // +1 for the null terminator
        scanf("%s", row);
        for (int j = 0; j < w; j++) {
            if (row[j] == '#') {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX; // Use INT_MAX to represent infinity
            }
        }
    }

    // Update the graph from left to right
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x + 1] = (graph[y][x] + 1 < graph[y][x + 1]) ? graph[y][x] + 1 : graph[y][x + 1];
            }
        }
    }

    // Update the graph from right to left
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x - 1] = (graph[y][x] + 1 < graph[y][x - 1]) ? graph[y][x] + 1 : graph[y][x - 1];
            }
        }
    }

    // Update the graph from top to bottom
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] != INT_MAX) {
                graph[y + 1][x] = (graph[y][x] + 1 < graph[y + 1][x]) ? graph[y][x] + 1 : graph[y + 1][x];
            }
        }
    }

    // Update the graph from bottom to top
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] != INT_MAX) {
                graph[y - 1][x] = (graph[y][x] + 1 < graph[y - 1][x]) ? graph[y][x] + 1 : graph[y - 1][x];
            }
        }
    }

    // Find the maximum value in the graph
    int max_value = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] != INT_MAX && graph[i][j] > max_value) {
                max_value = graph[i][j];
            }
        }
    }

    printf("%d\n", max_value);

    // Free allocated memory
    for (int i = 0; i < h; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

// <END-OF-CODE>
