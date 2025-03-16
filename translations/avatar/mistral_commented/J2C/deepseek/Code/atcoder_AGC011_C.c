#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_NODES];
    bool visited[MAX_NODES];
    int color[MAX_NODES];
    long one;
    long bipartite;
    long count;
    bool mujun;
} Graph;

void addEdge(Graph* graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

void dfs(Graph* graph, int a, int c) {
    if (graph->visited[a]) {
        if (graph->color[a] >= 0 && graph->color[a] != c) {
            graph->mujun = true;
        }
        return;
    }
    graph->visited[a] = true;
    graph->color[a] = c;
    graph->count++;
    Node* temp = graph->adjList[a];
    while (temp != NULL) {
        dfs(graph, temp->data, 1 - c);
        temp = temp->next;
    }
}

int main() {
    Graph graph;
    memset(&graph, 0, sizeof(Graph));

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&graph, u - 1, v - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (graph.visited[i]) continue;
        graph.one++;
        graph.mujun = false;
        dfs(&graph, i, 0);
        if (!graph.mujun) {
            graph.bipartite++;
        }
    }

    long total = graph.one * (2 * n - graph.one) + (graph.count - graph.one) * (graph.count - graph.one) + graph.bipartite * graph.bipartite;
    printf("%ld\n", total);

    return 0;
}
