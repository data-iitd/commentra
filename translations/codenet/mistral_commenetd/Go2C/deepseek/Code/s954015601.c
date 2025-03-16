#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_EDGES 200000

int readInt() {
    int result;
    scanf("%d", &result);
    return result;
}

int genid(int a, int b) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    return a * 100000 + b;
}

void dfs(int node, int parent, int color, int *edges[], int edge_count[], int colors[], int *color_used) {
    int next_color = 1;
    for (int i = 0; i < edge_count[node]; i++) {
        int child = edges[node][i];
        if (child == parent) continue;
        if (next_color == color) next_color++;
        colors[genid(node, child)] = next_color;
        dfs(child, node, next_color, edges, edge_count, colors, color_used);
        next_color++;
    }
    if (*color_used < next_color) *color_used = next_color;
}

int main() {
    int N = readInt();
    int edges[MAX_N][2];
    int *edges_list[MAX_N];
    int edge_count[MAX_N] = {0};
    int colors[MAX_EDGES] = {0};
    int color_used = 0;

    for (int i = 0; i < N - 1; i++) {
        int a = readInt() - 1;
        int b = readInt() - 1;
        edges[i][0] = a;
        edges[i][1] = b;
        edge_count[a]++;
        edge_count[b]++;
    }

    for (int i = 0; i < N; i++) {
        edges_list[i] = (int *)malloc(edge_count[i] * sizeof(int));
        edge_count[i] = 0;
    }

    for (int i = 0; i < N - 1; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        edges_list[a][edge_count[a]++] = b;
        edges_list[b][edge_count[b]++] = a;
    }

    dfs(0, -1, -1, edges_list, edge_count, colors, &color_used);

    printf("%d\n", color_used);

    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(edges[i][0], edges[i][1])]);
    }

    for (int i = 0; i < N; i++) {
        free(edges_list[i]);
    }

    return 0;
}
