#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INFINITY 1000000000

int main() {
    int h, w;
    scanf("%d %d", &h, &w);

    int graph[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            graph[y][x + 1] = min(graph[y][x] + 1, graph[y][x + 1]);
        }
    }

    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            graph[y][x - 1] = min(graph[y][x] + 1, graph[y][x - 1]);
        }
    }

    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            graph[y + 1][x] = min(graph[y][x] + 1, graph[y + 1][x]);
        }
    }

    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            graph[y - 1][x] = min(graph[y][x] + 1, graph[y - 1][x]);
        }
    }

    int max_distance = -INFINITY;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            max_distance = max(max_distance, graph[i][j]);
        }
    }

    printf("%d", max_distance);

    return 0;
}

