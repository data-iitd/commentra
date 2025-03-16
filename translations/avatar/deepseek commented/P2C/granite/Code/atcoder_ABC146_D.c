
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure to represent a node in the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure to represent the graph
typedef struct Graph {
    int V;
    Node** array;
} Graph;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* temp = newNode(dest);
    temp->next = graph->array[src];
    graph->array[src] = temp;
}

// Function to perform Breadth-First Search (BFS) to color the graph
int bfs(Graph* graph, int V, int src, int* color, int* edgeColor) {
    // Initialize visited array to keep track of visited nodes
    bool* visited = (bool*)malloc(V * sizeof(bool));
    memset(visited, false, V * sizeof(bool));
    // Initialize a queue for BFS using array
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;
    // Initialize the maximum color index K
    int K = -1;
    // List to store the color of each node, initialized to -1 (no color)
    memset(color, -1, V * sizeof(int));
    // Start BFS from vertex src
    queue[rear++] = src;
    visited[src] = true;
    while (front < rear) {
        // Dequeue the front node
        int q = queue[front++];
        // Initialize color for the current node
        int c = 0;
        // Iterate over all adjacent nodes
        Node* temp = graph->array[q];
        while (temp!= NULL) {
            int nex = temp->data;
            temp = temp->next;
            if (visited[nex])
                continue;
            visited[nex] = true;
            c++;
            // Ensure the color is different from the parent node's color
            if (c == color[q])
                c++;
            // Assign the color to the node and record the edge color
            color[nex] = c;
            edgeColor[nex] = c;
            // Enqueue the adjacent node for further exploration
            queue[rear++] = nex;
        }
        // Update the maximum color used
        K = max(K, c);
    }
    free(visited);
    free(queue);
    return K;
}

// Main function to read input, construct the graph, and execute the BFS
int main() {
    // Read the number of nodes V
    int V;
    scanf("%d", &V);
    // Initialize a list of arrays to represent the graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (Node**)malloc(V * sizeof(Node*));
    memset(graph->array, 0, V * sizeof(Node*));
    // Read edges to populate the graph
    for (int i = 0; i < V - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a - 1, b - 1);
        addEdge(graph, b - 1, a - 1);
    }
    // Initialize an array to store the color of each node
    int* color = (int*)malloc(V * sizeof(int));
    // Initialize an array to store the colors of all edges
    int* edgeColor = (int*)malloc(V * sizeof(int));
    // Perform BFS to determine the maximum color and edge colors
    int K = bfs(graph, V, 0, color, edgeColor);
    // Print the maximum color used
    printf("%d\n", K);
    // Print the colors of all edges
    for (int i = 0; i < V; i++) {
        printf("%d\n", edgeColor[i]);
    }
    free(graph->array);
    free(graph);
    free(color);
    free(edgeColor);
    return 0;
}

Translate the above C code to Java and end with comment "