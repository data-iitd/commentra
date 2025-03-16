#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000
#define MAX_EDGES 100000

// Structure to represent a graph
typedef struct Graph {
    int N;  // Number of nodes
    int E;  // Number of edges
    int G[MAX_NODES][MAX_NODES];  // Adjacency matrix
    int E_color[MAX_EDGES];  // Edge color
} Graph;

// Structure to represent a queue
typedef struct Queue {
    int front;  // Front of the queue
    int rear;  // Rear of the queue
    int size;  // Size of the queue
    int* arr;  // Array to store the queue elements
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->arr = (int*)malloc(sizeof(int) * size);
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue an element
void enqueue(Queue* queue, int element) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = element;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int element = queue->arr[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return element;
}

// Function to perform BFS starting from a given vertex
int bfs(Graph* graph, int start) {
    // Initialize visited list to keep track of visited nodes
    int visited[graph->N];
    memset(visited, 0, sizeof(visited));
    // Initialize a queue for BFS
    Queue* queue = createQueue(graph->N);
    int K = -1;  // Variable to track the maximum color used
    // Initialize a list to store the color assigned to each node
    int node2color[graph->N];
    memset(node2color, -1, sizeof(node2color));
    
    // Start BFS from the given vertex 'start'
    enqueue(queue, start);
    visited[start] = 1;  // Mark the starting node as visited
    
    while (!isEmpty(queue)) {
        // Dequeue the front node
        int q = dequeue(queue);
        int color = 0;  // Initialize color counter for the current node
        
        // Explore all adjacent nodes
        for (int nex = 0; nex < graph->N; nex++) {
            if (visited[nex]) {
                continue;  // Skip if the node has already been visited
            }
            
            visited[nex] = 1;  // Mark the adjacent node as visited
            color++;  // Increment the color counter
            
            // Ensure the color assigned to the next node is different from the current node's color
            if (color == node2color[q]) {
                color++;
            }
            
            // Assign the color to the adjacent node
            node2color[nex] = color;
            
            // Store the color used for the edge between the current node and the adjacent node
            graph->E_color[(q < nex) ? (q * graph->N + nex) : (nex * graph->N + q)] = color;
            
            // Enqueue the adjacent node for further exploration
            enqueue(queue, nex);
        }
        
        // Update the maximum color used
        K = max(K, color);
    }
    
    return K;  // Return the maximum color used
}

// Function to perform BFS starting from all the nodes
int bfsAll(Graph* graph) {
    int K = -1;  // Variable to track the maximum color used
    
    // Perform BFS starting from each node
    for (int i = 0; i < graph->N; i++) {
        K = max(K, bfs(graph, i));
    }
    
    return K;  // Return the maximum color used
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->N; i++) {
        for (int j = 0; j < graph->N; j++) {
            printf("%d ", graph->G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print the edge colors
void printEdgeColors(Graph* graph) {
    printf("Edge colors:\n");
    for (int i = 0; i < graph->E; i++) {
        printf("%d ", graph->E_color[i]);
    }
    printf("\n");
}

int main() {
    // Read the number of nodes
    int N;
    scanf("%d", &N);
    // Initialize the graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->N = N;
    graph->E = 0;
    memset(graph->G, 0, sizeof(graph->G));
    memset(graph->E_color, 0, sizeof(graph->E_color));
    
    // Read edges and build the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph->G[a - 1][b - 1] = 1;  // Add edge from a to b
        graph->G[b - 1][a - 1] = 1;  // Add edge from b to a
        graph->E_color[(a < b) ? (a * N + b) : (b * N + a)] = 0;  // Initialize edge color to 0
        graph->E++;
    }
    
    // Perform BFS starting from all the nodes
    int K = bfsAll(graph);
    
    // Print the maximum color used
    printf("Maximum color used: %d\n", K);
    // Print the edge colors
    printEdgeColors(graph);
    
    return 0;
}

