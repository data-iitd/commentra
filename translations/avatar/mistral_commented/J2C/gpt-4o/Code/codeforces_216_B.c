#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000 // Define a maximum number of nodes

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjLists;
    bool* seen;
    int count;
} Graph;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int nodes) {
    Graph* graph = malloc(sizeof(Graph));
    graph->adjLists = malloc((nodes + 1) * sizeof(Node*));
    graph->seen = malloc((nodes + 1) * sizeof(bool));
    graph->count = 0;

    for (int i = 0; i <= nodes; i++) {
        graph->adjLists[i] = NULL;
        graph->seen[i] = false;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int dfs(Graph* graph, int child, int par) {
    if (graph->seen[child]) {
        return 1; // Cycle detected
    }
    graph->seen[child] = true;

    for (Node* temp = graph->adjLists[child]; temp != NULL; temp = temp->next) {
        int i = temp->data;
        if (i != par) {
            graph->count++;
            if (dfs(graph, i, child) == 1) {
                return 1; // Cycle detected
            }
        }
    }
    return 0; // No cycle
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    Graph* graph = createGraph(m);
    
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(graph, x, y);
    }

    int toremove = 0;
    for (int i = 1; i <= m; i++) {
        if (!graph->seen[i]) {
            graph->count = 0;
            if (dfs(graph, i, 0) == 1) {
                if (graph->count % 2 == 1) {
                    toremove++;
                }
            }
        }
    }

    if ((m - toremove) % 2 == 1) {
        toremove++;
    }

    printf("%d\n", toremove);

    // Free allocated memory
    for (int i = 0; i <= m; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->seen);
    free(graph);

    return 0;
}

// <END-OF-CODE>
