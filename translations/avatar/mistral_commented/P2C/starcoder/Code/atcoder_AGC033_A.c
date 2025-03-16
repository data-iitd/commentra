#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    int graph[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            graph[i][j] = 0;
            char c = getchar();
            if (c == '#') {
                graph[i][j] = 1000000000;
            }
        }
        getchar();
    }
    for (int i = 0; i < w - 1; i++) {
        for (int j = 0; j < h; j++) {
            graph[j][i] = graph[j][i] + 1;
            graph[j][i + 1] = graph[j][i + 1] + 1;
        }
    }
    for (int i = 0; i < w - 1; i++) {
        for (int j = 0; j < h; j++) {
            graph[j][i] = graph[j][i] + 1;
            graph[j][i + 1] = graph[j][i + 1] + 1;
        }
    }
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            graph[i][j] = graph[i][j] + 1;
            graph[i + 1][j] = graph[i + 1][j] + 1;
        }
    }
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            graph[i][j] = graph[i][j] + 1;
            graph[i + 1][j] = graph[i + 1][j] + 1;
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

