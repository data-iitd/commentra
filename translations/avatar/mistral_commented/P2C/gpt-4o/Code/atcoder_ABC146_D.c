#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Structure to represent a queue
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue an item
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        return; // Queue is full
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an item
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1; // Queue is empty
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Reset the queue
    }
    return item;
}

// Function to perform Breadth First Search (BFS)
int bfs(int v, int N, int G[MAX_NODES][MAX_NODES], int E[MAX_NODES][MAX_NODES], int* edgeColors) {
    int visited[MAX_NODES] = {0};
    Queue queue;
    initQueue(&queue);

    int K = -1;
    int node2color[MAX_NODES] = {-1};

    enqueue(&queue, v);
    visited[v] = 1;

    while (!isEmpty(&queue)) {
        int q = dequeue(&queue);
        int color = 0;

        for (int nex = 0; nex < N; nex++) {
            if (G[q][nex]) { // If there is an edge
                if (visited[nex]) {
                    continue;
                }

                visited[nex] = 1;
                color++;

                if (color == node2color[q]) {
                    color++;
                }

                node2color[nex] = color;
                E[q][nex] = color;
                E[nex][q] = color; // Since it's an undirected graph

                enqueue(&queue, nex);
            }
        }

        K = (K > color) ? K : color;
    }

    return K;
}

// Main function to read input and call bfs function
int main() {
    int N;
    scanf("%d", &N);

    int G[MAX_NODES][MAX_NODES] = {0};
    int E[MAX_NODES][MAX_NODES] = {0};
    int edgeColors[MAX_NODES] = {0};

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--;
        G[a][b] = 1;
        G[b][a] = 1;
        E[a][b] = 0;
        E[b][a] = 0; // Since it's an undirected graph
    }

    int K = bfs(0, N, G, E, edgeColors);
    printf("%d\n", K);

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
