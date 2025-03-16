#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

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
    queue->rear = -1;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

void enqueue(Queue* queue, int item) {
    queue->data[++queue->rear] = item;
}

int dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

void bfs(int v, int N, int G[MAX_NODES][MAX_NODES], int E[MAX_NODES][MAX_NODES], int* edgeColors) {
    int visited[MAX_NODES] = {0};
    Queue* queue = createQueue(N);
    int K = -1;  // Variable to track the maximum color used
    int node2color[MAX_NODES] = {-1};  // Color assigned to each node

    enqueue(queue, v);
    visited[v] = 1;  // Mark the starting node as visited

    while (!isEmpty(queue)) {
        int q = dequeue(queue);
        int color = 0;  // Initialize color counter for the current node

        for (int nex = 0; nex < N; nex++) {
            if (G[q][nex]) {  // Check if there is an edge
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
                E[q][nex] = color;
                E[nex][q] = color;  // Since it's an undirected graph

                // Enqueue the adjacent node for further exploration
                enqueue(queue, nex);
            }
        }

        // Update the maximum color used
        if (color > K) {
            K = color;
        }
    }

    free(queue->data);
    free(queue);
    return K;  // Return the maximum color used
}

int main() {
    int N;
    scanf("%d", &N);
    int G[MAX_NODES][MAX_NODES] = {0};  // Adjacency matrix
    int E[MAX_NODES][MAX_NODES] = {0};  // Edge colors

    // Read edges and build the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;  // Convert to 0-based index
        G[a][b] = 1;  // Add edge from a to b
        G[b][a] = 1;  // Add edge from b to a
        E[a][b] = 0;  // Initialize edge color to 0
        E[b][a] = 0;  // Initialize edge color to 0
    }

    // Perform BFS starting from node 0
    int K = bfs(0, N, G, E, E);

    // Print the maximum color used
    printf("%d\n", K);
    // Print the colors assigned to each edge
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (E[i][j] != 0) {
                printf("%d\n", E[i][j]);
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
