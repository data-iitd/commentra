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

    // Initialize adjacency list
    int **edge = (int**)malloc(N * sizeof(int*));
    int *edgeCount = (int*)calloc(N, sizeof(int));
    for (int i = 0; i < N; i++) {
        edge[i] = (int*)malloc(N * sizeof(int)); // Allocate maximum possible size
    }

    // Read edges
    for (int i = 0; i < M; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        X--; Y--; // Convert to 0-based index
        edge[X][edgeCount[X]++] = Y;
        edge[Y][edgeCount[Y]++] = X;
    }

    // Initialize used array
    bool *used = (bool*)calloc(N, sizeof(bool));
    int ans = 0;

    // Iterate through all nodes
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;
            Queue* queue = createQueue(N);
            enqueue(queue, i);

            // Traverse through the graph using BFS
            while (!isEmpty(queue)) {
                int node = dequeue(queue);
                used[node] = true;

                for (int j = 0; j < edgeCount[node]; j++) {
                    int nextnode = edge[node][j];
                    if (!used[nextnode]) {
                        enqueue(queue, nextnode);
                    }
                }
            }
            freeQueue(queue);
        }
    }

    // Print the answer
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
