#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int dfs(Graph* graph, int child, int par, bool* seen, int* count) {
    if (seen[child]) return 1; // cycle detected
    seen[child] = true;

    for (Node* temp = graph->adjLists[child]; temp != NULL; temp = temp->next) {
        int i = temp->data;
        if (i != par) {
            (*count)++;
            if (dfs(graph, i, child, seen, count) == 1) return 1; // cycle detected
        }
    }
    return 0; // no cycle
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    Graph* graph = createGraph(m + 1);
    bool* seen = malloc((m + 1) * sizeof(bool));
    for (int i = 0; i <= m; i++) {
        seen[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(graph, x, y);
    }

    int toremove = 0;
    for (int i = 1; i <= m; i++) {
        if (!seen[i]) {
            int count = 0;
            if (dfs(graph, i, 0, seen, &count) == 1) {
                if (count % 2 == 1) toremove++;
            }
        }
    }

    if ((m - toremove) % 2 == 1) toremove++;
    printf("%d\n", toremove);

    // Free memory
    for (int i = 0; i <= m; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
    free(seen);

    return 0;
}

// <END-OF-CODE>
