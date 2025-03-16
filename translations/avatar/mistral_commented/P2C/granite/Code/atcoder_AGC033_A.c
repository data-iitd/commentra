
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Taking input dimensions of the graph
    int h, w;
    scanf("%d %d", &h, &w);

    // Initializing the graph as a 2D array with initial values
    int graph[h][w];
    for (int i = 0; i < h; i++) {
        char c;
        for (int j = 0; j < w; j++) {
            scanf(" %c", &c);
            graph[i][j] = (c == '#'? 0 : INT_MAX);
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            graph[y][x + 1] = graph[y][x + 1] < graph[y][x] + 1? graph[y][x + 1] : graph[y][x] + 1;
        }
    }

    // Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            graph[y][x - 1] = graph[y][x - 1] < graph[y][x] + 1? graph[y][x - 1] : graph[y][x] + 1;
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            graph[y + 1][x] = graph[y + 1][x] < graph[y][x] + 1? graph[y + 1][x] : graph[y][x] + 1;
        }
    }

    // Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            graph[y - 1][x] = graph[y - 1][x] < graph[y][x] + 1? graph[y - 1][x] : graph[y][x] + 1;
        }
    }

    // Finding and printing the maximum shortest path distance in the graph
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
