#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e18

// Function to read input from standard input
char* input() {
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

// Function to initialize a queue
typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int item) {
    if (queue->size == queue->capacity) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void main() {
    // Set the recursion limit to a high value to handle deep recursions if needed
    // This is not directly supported in C, so we skip this part

    // Define a constant for infinity
    // This is not directly supported in C, so we skip this part

    // Read the number of nodes (N) and edges (M)
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();  // Consume the newline character

    // Initialize an adjacency list to represent the graph
    int** edge = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        edge[i] = (int*)malloc(N * sizeof(int));
    }

    // Read each edge and populate the adjacency list
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        scanf("%d %d %d", &X, &Y, &Z);
        getchar();  // Consume the newline character
        X--; Y--;  // Adjust for 0-based index
        edge[X][Y] = 1;
        edge[Y][X] = 1;
    }

    // Array to track visited nodes
    bool* used = (bool*)malloc(N * sizeof(bool));
    for (int i = 0; i < N; i++) {
        used[i] = false;
    }

    // Variable to count the number of connected components
    int ans = 0;

    // Iterate through each node to find connected components
    for (int i = 0; i < N; i++) {
        if (!used[i]) {  // If the node has not been visited
            ans++;  // Increment the count of connected components
            Queue* queue = createQueue(N);  // Initialize a queue for BFS
            enqueue(queue, i);  // Start BFS from the current node

            // Perform BFS to mark all reachable nodes from the current node
            while (!isQueueEmpty(queue)) {
                int node = dequeue(queue);  // Dequeue a node
                used[node] = true;  // Mark the node as visited

                // Explore all adjacent nodes
                for (int nextnode = 0; nextnode < N; nextnode++) {
                    if (edge[node][nextnode] == 1 && !used[nextnode]) {  // If the adjacent node has not been visited
                        enqueue(queue, nextnode);  // Enqueue the adjacent node
                    }
                }
            }
            free(queue);
        }
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(edge[i]);
    }
    free(edge);
    free(used);

    // Output the number of connected components found
    printf("%d\n", ans);
}
