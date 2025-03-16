
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int h, w;
    scanf("%d %d", &h, &w);
    char graph[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %c", &graph[i][j]);
        }
    }
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x]!= '#') {
                graph[y][x + 1] = (graph[y][x + 1] == '#'? '#' : (graph[y][x + 1] == '.'? '.' : graph[y][x + 1] + 1));
            }
        }
    }
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            if (graph[y][x]!= '#') {
                graph[y][x - 1] = (graph[y][x - 1] == '#'? '#' : (graph[y][x - 1] == '.'? '.' : graph[y][x - 1] + 1));
            }
        }
    }
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x]!= '#') {
                graph[y + 1][x] = (graph[y + 1][x] == '#'? '#' : (graph[y + 1][x] == '.'? '.' : graph[y + 1][x] + 1));
            }
        }
    }
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x]!= '#') {
                graph[y - 1][x] = (graph[y - 1][x] == '#'? '#' : (graph[y - 1][x] == '.'? '.' : graph[y - 1][x] + 1));
            }
        }
    }
    int max = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (graph[y][x]!= '#' && max < graph[y][x]) {
                max = graph[y][x];
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
