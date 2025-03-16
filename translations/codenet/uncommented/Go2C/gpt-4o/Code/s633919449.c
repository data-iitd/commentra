#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

void getInt(int *n) {
    scanf("%d", n);
}

void printResult(int n) {
    switch (n % 10) {
        case 2: case 4: case 5: case 7: case 9:
            printf("hon\n");
            break;
        case 0: case 1: case 6: case 8:
            printf("pon\n");
            break;
        case 3:
            printf("bon\n");
            break;
    }
}

typedef struct {
    int n;
    int **edges;
} Graph;

Graph* newGraph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;
    g->edges = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int *)malloc(n * sizeof(int));
    }
    return g;
}

void addEdge(Graph *g, int u, int v) {
    g->edges[u][g->n++] = v;
    g->edges[v][g->n++] = u;
}

void dfs(int c, int **edges, bool *visited) {
    visited[c] = true;
    for (int i = 0; i < edges[c][0]; i++) {
        int v = edges[c][i];
        if (!visited[v]) {
            dfs(v, edges, visited);
        }
    }
}

void bfs(int c, Graph *graph) {
    int *next = (int *)malloc(graph->n * sizeof(int));
    int front = 0, rear = 0;
    next[rear++] = c;
    bool *visited = (bool *)calloc(graph->n, sizeof(bool));

    while (front < rear) {
        int u = next[front++];
        visited[u] = true;

        for (int i = 0; i < graph->edges[u][0]; i++) {
            int v = graph->edges[u][i];
            if (!visited[v]) {
                // Do something
                next[rear++] = v;
            }
        }
    }
    free(next);
    free(visited);
}

int main() {
    int N;
    getInt(&N);
    printResult(N);
    
    // Free allocated memory for graph if used
    // Example: Graph *g = newGraph(10); free(g->edges); free(g);
    
    return 0;
}

// Additional utility functions can be implemented as needed

