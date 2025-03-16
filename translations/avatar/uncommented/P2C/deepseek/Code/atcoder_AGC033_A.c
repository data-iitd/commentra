#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    int graph[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            scanf(" %c", &c);
            graph[i][j] = (c == '#') ? INT_MAX : 0;
        }
    }

    for (int x = 0; x < w - 1; x++) {
        for (int i = 0; i < h; i++) {
            if (graph[i][x] + 1 < graph[i][x + 1]) {
                graph[i][x + 1] = graph[i][x] + 1;
            }
        }
    }

    for (int x = w - 1; x > 0; x--) {
        for (int i = 0; i < h; i++) {
            if (graph[i][x] + 1 < graph[i][x - 1]) {
                graph[i][x - 1] = graph[i][x] + 1;
            }
        }
    }

    for (int y = 0; y < h - 1; y++) {
        for (int j = 0; j < w; j++) {
            if (graph[y][j] + 1 < graph[y + 1][j]) {
                graph[y + 1][j] = graph[y][j] + 1;
            }
        }
    }

    for (int y = h - 1; y > 0; y--) {
        for (int j = 0; j < w; j++) {
            if (graph[y][j] + 1 < graph[y - 1][j]) {
                graph[y - 1][j] = graph[y][j] + 1;
            }
        }
    }

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
