#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Taking input dimensions of the graph
    int h, w;
    scanf("%d %d", &h, &w);

    // Initializing the graph as a 2D array with initial values
    int **graph = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        graph[i] = (int *)malloc(w * sizeof(int));
        for (int j = 0; j < w; j++) {
            char c;
            scanf(" %c", &c);
            if (c == '#') {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX; // Use INT_MAX to represent infinity
            }
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x + 1] = (graph[y][x] + 1 < graph[y][x + 1]) ? graph[y][x] + 1 : graph[y][x + 1];
            }
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x] != INT_MAX) {
                graph[y][x - 1] = (graph[y][x] + 1 < graph[y][x - 1]) ? graph[y][x] + 1 : graph[y][x - 1];
            }
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] != INT_MAX) {
                graph[y + 1][x] = (graph[y][x] + 1 < graph[y + 1][x]) ? graph[y][x] + 1 : graph[y + 1][x];
            }
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x] != INT_MAX) {
                graph[y - 1][x] = (graph[y][x] + 1 < graph[y - 1][x]) ? graph[y][x] + 1 : graph[y - 1][x];
            }
        }
    }

    // Finding the maximum shortest path distance in the graph
    int max_distance = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] != INT_MAX && graph[i][j] > max_distance) {
                max_distance = graph[i][j];
            }
        }
    }

    // Printing the maximum shortest path distance
    printf("%d\n", max_distance);

    // Freeing allocated memory
    for (int i = 0; i < h; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

// <END-OF-CODE>
