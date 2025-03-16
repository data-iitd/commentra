#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_EDGES 200000

int genid(int a, int b) {
    return a < b ? a * 100000 + b : b * 100000 + a;
}

int readInt() {
    int result;
    scanf("%d", &result);
    return result;
}

void dfs(int node, int parent, int usedColor, int *colors, int **edges, int N) {
    int color = 1;
    if (color == usedColor) {
        color++;
    }
    for (int i = 0; i < edges[node][0]; i++) {
        int childNode = edges[node][i + 1];
        if (childNode == parent) {
            continue;
        }
        colors[genid(node, childNode)] = color;
        dfs(childNode, node, color, colors, edges, N);
        color++;
        if (color == usedColor) {
            color++;
        }
    }
}

int main() {
    int N = readInt();
    int **edges = (int **)malloc(N * sizeof(int *));
    int *edges_sizes = (int *)malloc(N * sizeof(int));
    int ab[N - 1][2];
    int colors[MAX_EDGES] = {0};

    for (int i = 0; i < N - 1; i++) {
        int a = readInt() - 1;
        int b = readInt() - 1;
        ab[i][0] = a;
        ab[i][1] = b;
        edges[a] = (int *)malloc(edges_sizes[a] + 2 * sizeof(int));
        edges[a][0] = edges_sizes[a] + 1;
        edges[a][edges_sizes[a] + 1] = b;
        edges[b] = (int *)malloc(edges_sizes[b] + 2 * sizeof(int));
        edges[b][0] = edges_sizes[b] + 1;
        edges[b][edges_sizes[b] + 1] = a;
        edges_sizes[a]++;
        edges_sizes[b]++;
    }

    int K = 0;
    for (int i = 0; i < N; i++) {
        if (edges_sizes[i] > K) {
            K = edges_sizes[i];
        }
    }
    printf("%d\n", K);

    dfs(0, -1, -1, colors, edges, N);

    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
    }

    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(edges_sizes);

    return 0;
}
