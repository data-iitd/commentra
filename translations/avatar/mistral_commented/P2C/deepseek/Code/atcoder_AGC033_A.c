#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

void dijkstra_horizontal(int **graph, int h, int w) {
    for (int x = 0; x < w - 1; x++) {
        for (int i = 0; i < h; i++) {
            if (graph[i][x] != '#') {
                if (graph[i][x] + 1 < graph[i][x + 1]) {
                    graph[i][x + 1] = graph[i][x] + 1;
                }
            }
        }
    }
}

void dijkstra_horizontal_reverse(int **graph, int h, int w) {
    for (int x = w - 1; x > 0; x--) {
        for (int i = 0; i < h; i++) {
            if (graph[i][x] != '#') {
                if (graph[i][x] + 1 < graph[i][x - 1]) {
                    graph[i][x - 1] = graph[i][x] + 1;
                }
            }
        }
    }
}

void dijkstra_vertical(int **graph, int h, int w) {
    for (int y = 0; y < h - 1; y++) {
        for (int i = 0; i < w; i++) {
            if (graph[y][i] != '#') {
                if (graph[y][i] + 1 < graph[y + 1][i]) {
                    graph[y + 1][i] = graph[y][i] + 1;
                }
            }
        }
    }
}

void dijkstra_vertical_reverse(int **graph, int h, int w) {
    for (int y = h - 1; y > 0; y--) {
        for (int i = 0; i < w; i++) {
            if (graph[y][i] != '#') {
                if (graph[y][i] + 1 < graph[y - 1][i]) {
                    graph[y - 1][i] = graph[y][i] + 1;
                }
            }
        }
    }
}

int main() {
    int h, w;
    scanf("%d %d", &h, &w);

    // Allocate memory for the graph
    int **graph = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        graph[i] = (int *)malloc(w * sizeof(int));
    }

    // Read the graph
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            scanf(" %c", &c);
            graph[i][j] = (c == '#') ? INF : 0;
        }
    }

    // Perform Dijkstra's shortest path algorithm
    dijkstra_horizontal(graph, h, w);
    dijkstra_horizontal_reverse(graph, h, w);
    dijkstra_vertical(graph, h, w);
    dijkstra_vertical_reverse(graph, h, w);

    // Find the maximum shortest path distance
    int max_distance = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] != '#' && graph[i][j] > max_distance) {
                max_distance = graph[i][j];
            }
        }
    }

    // Print the result
    printf("%d\n", max_distance);

    // Free allocated memory
    for (int i = 0; i < h; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
