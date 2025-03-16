#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int m;
    Node* adjList[MAX_NODES + 1];
    bool seen[MAX_NODES + 1];
} Graph;

int count;
int cycle = 1;
int path = 0;

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

int dfs(Graph* graph, int child, int par) {
    if (graph->seen[child]) return cycle;
    graph->seen[child] = true;

    Node* adjNode = graph->adjList[child];
    while (adjNode != NULL) {
        if (adjNode->data != par) {
            count++;
            if (dfs(graph, adjNode->data, child) == cycle) return cycle;
        }
        adjNode = adjNode->next;
    }
    return path;
}

int main() {
    Graph graph;
    int m, n, toremove = 0;

    scanf("%d %d", &m, &n);
    graph.m = m;

    for (int i = 0; i <= m; i++) {
        graph.adjList[i] = NULL;
        graph.seen[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(&graph, x, y);
    }

    for (int i = 1; i <= m; i++) {
        if (!graph.seen[i]) {
            count = 0;
            if (dfs(&graph, i, 0) == cycle) {
                if (count % 2 == 1) toremove++;
            }
        }
    }

    if ((m - toremove) % 2 == 1) toremove++;

    printf("%d\n", toremove);

    return 0;
}
