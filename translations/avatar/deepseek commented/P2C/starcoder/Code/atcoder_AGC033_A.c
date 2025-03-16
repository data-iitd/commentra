
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
            if (c == '#') {
                graph[i][j] = INT_MAX;
            } else {
                graph[i][j] = 0;
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
    int max = INT_MIN;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            max = max > graph[i][j]? max : graph[i][j];
        }
    }
    printf("%d", max);
    return 0;
}

