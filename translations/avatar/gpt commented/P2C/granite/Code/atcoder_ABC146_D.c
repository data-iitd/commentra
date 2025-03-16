
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 100000

typedef struct {
    int color;
    bool visited;
} Node;

typedef struct {
    int from;
    int to;
} Edge;

void bfs(int v, int N, int** G, int* E, int* K) {
    Node* nodes = (Node*)malloc(sizeof(Node) * N);
    for (int i = 0; i < N; i++) {
        nodes[i].color = 0;
        nodes[i].visited = false;
    }

    int* queue = (int*)malloc(sizeof(int) * N);
    int front = 0, rear = 0;
    queue[rear++] = v;
    nodes[v].visited = true;

    while (front < rear) {
        int q = queue[front++];
        int color = 0;
        for (int i = 0; i < G[q][0]; i++) {
            int nex = G[q][i + 1];
            if (nodes[nex].visited) {
                continue;
            }
            nodes[nex].visited = true;
            color++;
            if (color == nodes[q].color) {
                color++;
            }
            nodes[nex].color = color;
            E[(q < nex? q : nex) * N + (q > nex? q : nex)] = color;
            queue[rear++] = nex;
        }
        *K = *K > color? *K : color;
    }

    free(nodes);
    free(queue);
}

int main() {
    int N;
    scanf("%d", &N);
    int** G = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        G[i] = (int*)malloc(sizeof(int) * (N + 1));
        scanf("%d", &G[i][0]);
        for (int j = 1; j <= G[i][0]; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    int* E = (int*)malloc(sizeof(int) * (N * (N - 1) / 2));
    int K = 0;
    bfs(0, N, G, E, &K);

    printf("%d\n", K);
    for (int i = 0; i < N * (N - 1) / 2; i++) {
        printf("%d\n", E[i]);
    }

    for (int i = 0; i < N; i++) {
        free(G[i]);
    }
    free(G);
    free(E);

    return 0;
}

