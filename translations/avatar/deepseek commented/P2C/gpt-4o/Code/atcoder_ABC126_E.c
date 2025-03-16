#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000  // Define a maximum number of nodes
#define INF 1000000000000000000LL  // Define a constant for infinity

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, int value) {
    queue->data[queue->rear++] = value;
}

int dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);  // Read the number of nodes and edges

    // Initialize the edge list to represent the graph
    int **edge = (int**)malloc(N * sizeof(int*));
    int *edgeCount = (int*)calloc(N, sizeof(int));
    for (int i = 0; i < N; i++) {
        edge[i] = (int*)malloc(M * sizeof(int));  // Allocate space for edges
    }

    for (int i = 0; i < M; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        X--; Y--;  // Adjust indices to be zero-based
        edge[X][edgeCount[X]++] = Y;  // Add edge in both directions for an undirected graph
        edge[Y][edgeCount[Y]++] = X;
    }

    bool *used = (bool*)calloc(N, sizeof(bool));  // Initialize a list to track visited nodes
    int ans = 0;  // Initialize the counter for connected components

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;  // Increment the counter for each new connected component found
            Queue* queue = createQueue(N);  // Initialize a queue for BFS
            enqueue(queue, i);  // Start BFS from the current node

            while (!isEmpty(queue)) {
                int node = dequeue(queue);  // Get the next node from the queue
                used[node] = true;  // Mark the node as visited
                for (int j = 0; j < edgeCount[node]; j++) {
                    int nextnode = edge[node][j];
                    if (!used[nextnode]) {
                        enqueue(queue, nextnode);  // Add unvisited neighbors to the queue
                    }
                }
            }
            freeQueue(queue);  // Free the queue after use
        }
    }

    printf("%d\n", ans);  // Output the total number of connected components

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
