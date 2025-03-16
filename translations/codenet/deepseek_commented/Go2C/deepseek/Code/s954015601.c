#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_EDGES 200000

int genid(int a, int b) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    return a * 100000 + b;
}

int readInt() {
    int result;
    scanf("%d", &result);
    return result;
}

void dfs(int node, int parent, int usedColor, int *edges[], int edgeCount[], int colors[], int *colorIndex) {
    int color = 1;
    for (int i = 0; i < edgeCount[node]; i++) {
        int child = edges[node][i];
        if (child == parent) continue;
        if (color == usedColor) color++;
        colors[*colorIndex] = color;
        (*colorIndex)++;
        dfs(child, node, color, edges, edgeCount, colors, colorIndex);
        color++;
    }
}

int main() {
    int N = readInt();
    int edges[MAX_N][MAX_N] = {0};
    int edgeCount[MAX_N] = {0};
    int colors[MAX_N - 1];
    int colorIndex = 0;

    for (int i = 0; i < N - 1; i++) {
        int a = readInt() - 1;
        int b = readInt() - 1;
        edges[a][edgeCount[a]++] = b;
        edges[b][edgeCount[b]++] = a;
    }

    dfs(0, -1, -1, edges, edgeCount, colors, &colorIndex);

    int K = 0;
    for (int i = 0; i < N; i++) {
        if (edgeCount[i] > K) {
            K = edgeCount[i];
        }
    }
    printf("%d\n", K);

    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[i]);
    }

    return 0;
}
