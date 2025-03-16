

#include <stdio.h>
#include <stdlib.h>

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    char grid[h][w];
    int dist[h][w];

    // Read the grid and initialize the distance matrix
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %c", &grid[i][j]);
            dist[i][j] = (grid[i][j] == '#')? 0 : INT_MAX;
        }
    }

    // Calculate the minimum distance to any '#' for each cell in the grid
    // Processing in the left to right direction
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            dist[y][x + 1] = min(dist[y][x + 1], dist[y][x] + 1);
        }
    }

    // Processing in the right to left direction
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            dist[y][x - 1] = min(dist[y][x - 1], dist[y][x] + 1);
        }
    }

    // Processing in the top to bottom direction
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            dist[y + 1][x] = min(dist[y + 1][x], dist[y][x] + 1);
        }
    }

    // Processing in the bottom to top direction
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            dist[y - 1][x] = min(dist[y - 1][x], dist[y][x] + 1);
        }
    }

    // Print the maximum value in the distance matrix, which represents the maximum distance to the nearest '#'
    int max_dist = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            max_dist = max(max_dist, dist[i][j]);
        }
    }
    printf("%d\n", max_dist);

    return 0;
}
