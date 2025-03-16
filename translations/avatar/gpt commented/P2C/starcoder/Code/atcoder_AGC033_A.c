#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    int graph[h][w];
    for (int i = 0; i < h; i++) {
        char line[w + 1];
        scanf("%s", line);
        for (int j = 0; j < w; j++) {
            if (line[j] == '#') {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 0; i < w - 1; i++) {
        for (int j = 0; j < h; j++) {
            graph[j][i + 1] = graph[j][i] + 1;
        }
    }
    for (int i = w - 1; i > 0; i--) {
        for (int j = 0; j < h; j++) {
            graph[j][i - 1] = graph[j][i] + 1;
        }
    }
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            graph[i + 1][j] = graph[i][j] + 1;
        }
    }
    for (int i = h - 1; i > 0; i--) {
        for (int j = 0; j < w; j++) {
            graph[i - 1][j] = graph[i][j] + 1;
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

