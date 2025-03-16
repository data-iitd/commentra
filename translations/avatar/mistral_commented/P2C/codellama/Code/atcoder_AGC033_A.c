#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000

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
        for (int i = 0; i < h; i++) {
            graph[i][x + 1] = graph[i][x] + 1 < graph[i][x + 1] ? graph[i][x] + 1 : graph[i][x + 1];
        }
    }

    for (int x = w - 1; x > 0; x--) {
        for (int i = 0; i < h; i++) {
            graph[i][x - 1] = graph[i][x] + 1 < graph[i][x - 1] ? graph[i][x] + 1 : graph[i][x - 1];
        }
    }

    for (int y = 0; y < h - 1; y++) {
        for (int j = 0; j < w; j++) {
            graph[y + 1][j] = graph[y][j] + 1 < graph[y + 1][j] ? graph[y][j] + 1 : graph[y + 1][j];
        }
    }

    for (int y = h - 1; y > 0; y--) {
        for (int j = 0; j < w; j++) {
            graph[y - 1][j] = graph[y][j] + 1 < graph[y - 1][j] ? graph[y][j] + 1 : graph[y - 1][j];
        }
    }

    int max = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] > max) {
                max = graph[i][j];
            }
        }
    }

    printf("%d", max);

    return 0;
}

