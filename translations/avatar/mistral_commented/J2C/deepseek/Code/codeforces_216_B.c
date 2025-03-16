#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_NODES + 1];
    bool seen[MAX_NODES + 1];
    int count;
    int path, cycle;
} Graph;

int dfs(int child, int par, Graph* graph) {
    if (graph->seen[child]) {
        return graph->cycle;
    }
    graph->seen[child] = true;

    Node* temp = graph->adjList[child];
    while (temp != NULL) {
        if (temp->data != par) {
            graph->count++;
            if (dfs(temp->data, child, graph) == graph->cycle) {
                return graph->cycle;
            }
        }
        temp = temp->next;
    }
    return graph->path;
}

int main() {
    Graph graph;
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 0; i <= m; i++) {
        graph.adjList[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = y;
        newNode->next = graph.adjList[x];
        graph.adjList[x] = newNode;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = graph.adjList[y];
        graph.adjList[y] = newNode;
    }

    int toremove = 0;
    for (int i = 1; i <= m; i++) {
        if (!graph.seen[i]) {
            graph.count = 0;
            if (dfs(i, 0, &graph) == graph.cycle) {
                if (graph.count % 2 == 1) {
                    toremove++;
                }
            }
        }
    }

    if ((m - toremove) % 2 == 1) {
        toremove++;
    }

    printf("%d\n", toremove);

    return 0;
}
