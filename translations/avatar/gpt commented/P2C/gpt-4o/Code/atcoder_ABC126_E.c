#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000
#define INF 1000000000000000000LL

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

// Function to enqueue an element
void enqueue(Queue* queue, int item) {
    queue->data[queue->rear++] = item;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

// Function to free the queue
void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    // Initialize an adjacency list
    int **edge = (int**)malloc(N * sizeof(int*));
    int *edgeCount = (int*)calloc(N, sizeof(int));
    
    for (int i = 0; i < N; i++) {
        edge[i] = (int*)malloc(M * sizeof(int)); // Allocate maximum possible size
    }
    
    // Read each edge and populate the adjacency list
    for (int i = 0; i < M; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        X--; Y--; // Convert to 0-based index
        edge[X][edgeCount[X]++] = Y;
        edge[Y][edgeCount[Y]++] = X;
    }
    
    // Array to track visited nodes
    bool *used = (bool*)calloc(N, sizeof(bool));
    
    // Variable to count the number of connected components
    int ans = 0;
    
    // Iterate through each node to find connected components
    for (int i = 0; i < N; i++) {
        if (!used[i]) { // If the node has not been visited
            ans++; // Increment the count of connected components
            Queue* queue = createQueue(N); // Initialize a queue for BFS
            enqueue(queue, i); // Start BFS from the current node
            
            // Perform BFS to mark all reachable nodes from the current node
            while (!isEmpty(queue)) {
                int node = dequeue(queue); // Dequeue a node
                used[node] = true; // Mark the node as visited
                
                // Explore all adjacent nodes
                for (int j = 0; j < edgeCount[node]; j++) {
                    int nextnode = edge[node][j];
                    if (!used[nextnode]) { // If the adjacent node has not been visited
                        enqueue(queue, nextnode); // Enqueue the adjacent node
                    }
                }
            }
            freeQueue(queue); // Free the queue after use
        }
    }
    
    // Output the number of connected components found
    printf("%d\n", ans);
    
    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(edge[i]);
    }
    free(edge);
    free(edgeCount);
    free(used);
    
    return 0;
}

// <END-OF-CODE>
