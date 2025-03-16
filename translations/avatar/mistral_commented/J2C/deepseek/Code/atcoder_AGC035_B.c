#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent the adjacency list
typedef struct AdjList {
    Node* head;
} AdjList;

// Structure to represent the graph
typedef struct Graph {
    int numNode;
    AdjList* array;
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int numNode) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNode = numNode;
    graph->array = (AdjList*)malloc(numNode * sizeof(AdjList));
    for (int i = 0; i < numNode; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform DFS and check for bipartite graph
bool dfs(Graph* graph, int node, int parent, int* visited, bool* odd, FILE* outputFile) {
    visited[node] = 1;
    Node* adjNode = graph->array[node].head;
    while (adjNode != NULL) {
        int child = adjNode->data;
        if (child == parent || visited[child] == 1) {
            adjNode = adjNode->next;
            continue;
        }
        if (visited[child] == 2) {
            fprintf(outputFile, "%d %d\n", node + 1, child + 1);
            odd[node] = !odd[node];
        } else {
            if (!dfs(graph, child, node, visited, odd, outputFile)) {
                return false;
            }
            if (odd[child]) {
                fprintf(outputFile, "%d %d\n", child + 1, node + 1);
                odd[child] = !odd[child];
            } else {
                fprintf(outputFile, "%d %d\n", node + 1, child + 1);
                odd[node] = !odd[node];
            }
        }
        adjNode = adjNode->next;
    }
    visited[node] = 2;
    return true;
}

int main() {
    int numNode, numEdge;
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    fscanf(inputFile, "%d", &numNode);
    fscanf(inputFile, "%d", &numEdge);

    Graph* graph = createGraph(numNode);
    for (int i = 0; i < numEdge; i++) {
        int src, dest;
        fscanf(inputFile, "%d %d", &src, &dest);
        addEdge(graph, src - 1, dest - 1);
    }

    if (numEdge % 2 != 0) {
        fprintf(outputFile, "-1\n");
        return 0;
    }

    int* visited = (int*)malloc(numNode * sizeof(int));
    bool* odd = (bool*)malloc(numNode * sizeof(bool));
    for (int i = 0; i < numNode; i++) {
        visited[i] = 0;
        odd[i] = false;
    }

    if (!dfs(graph, 0, -1, visited, odd, outputFile)) {
        fprintf(outputFile, "-1\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    free(visited);
    free(odd);
    return 0;
}
