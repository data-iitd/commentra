#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Structure to represent the adjacency list
typedef struct Graph {
    Node** adjLists; // Array of adjacency lists
    int* heights; // Array to store heights of nodes
    int answer; // Variable to store the answer
    int k; // Variable to store the value of k
} Graph;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int n, int k) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjLists = (Node**)malloc(n * sizeof(Node*));
    graph->heights = (int*)malloc(n * sizeof(int));
    graph->answer = 0;
    graph->k = k;

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL; // Initialize adjacency lists
        graph->heights[i] = 0; // Initialize heights
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode; // Add the new node to the adjacency list
}

// Depth First Search function
int dfs(Graph* graph, int a, int pre) {
    int h = 0; // Variable to store the height of the current node

    Node* temp = graph->adjLists[a]; // Get the adjacency list for the current node
    while (temp) {
        h = (h > dfs(graph, temp->value, a)) ? h : dfs(graph, temp->value, a); // Update height
        temp = temp->next; // Move to the next neighbor
    }

    if (pre > 0 && h == graph->k - 1) { // Check if the current node is at the desired height
        h = 0; // Reset height
        graph->answer++; // Increment answer
    } else {
        h++; // Increment height
    }

    return h; // Return height
}

// Function to calculate the answer
int calculate(Graph* graph, int n) {
    dfs(graph, 0, -1); // Perform DFS starting from node 0
    return graph->answer; // Return the answer
}

int main() {
    int n, k; // Variables to store the number of test cases and value of k
    scanf("%d %d", &n, &k); // Read input values for n and k

    Graph* graph = createGraph(n, k); // Create a new graph

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        value--; // Adjusting the index
        if (i > 0) {
            addEdge(graph, value, i); // Add edge to the graph
        } else if (value > 0) {
            graph->answer++; // Increment answer if the input array contains a negative index
        }
    }

    // Print the result of the calculation
    printf("%d\n", calculate(graph, n));

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->heights);
    free(graph);

    return 0;
}

// <END-OF-CODE>
