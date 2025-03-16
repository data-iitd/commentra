

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node** array;
    int size;
} Graph;

Graph* createGraph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = size;
    graph->array = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        graph->array[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->array[src];
    graph->array[src] = newNode;
}

int dfs(Graph* graph, int* seen, int* count, int curr, int parent) {
    if (seen[curr]) return 1; // If node is already seen, return 1
    seen[curr] = 1; // Mark the node as seen
    *count += 1; // Increment count for each edge traversed
    Node* temp = graph->array[curr];
    while (temp!= NULL) {
        if (temp->data!= parent) { // Avoid going back to parent
            if (dfs(graph, seen, count, temp->data, curr) == 1) return 1; // If cycle is detected, return 1
        }
        temp = temp->next;
    }
    return 0; // Return 0 if no cycle is detected
}

int main() {
    int m, n, x, y, toremove = 0;
    scanf("%d %d", &m, &n);
    Graph* graph = createGraph(m + 1);
    int* seen = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        seen[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        addEdge(graph, x, y);
        addEdge(graph, y, x);
    }
    for (int i = 1; i <= m; i++) {
        if (seen[i - 1] == 0) { // If node is not visited
            int count = 0; // Reset count for each DFS call
            if (dfs(graph, seen, &count, i - 1, -1) == 1) { // If cycle is detected
                if (count % 2 == 1) toremove++; // Increment removal count if cycle length is odd
            }
        }
    }
    if ((m - toremove) % 2 == 1) toremove++; // Adjust removal count if total nodes minus removed nodes is odd
    printf("%d\n", toremove); // Print the final removal count
    return 0;
}

