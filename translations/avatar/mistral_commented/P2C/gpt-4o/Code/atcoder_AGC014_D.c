#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure for a queue
typedef struct {
    int items[MAX_N];
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
void enqueue(Queue* q, int item) {
    if (q->rear == MAX_N - 1) return; // Queue is full
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = item;
}

// Function to dequeue an item
int dequeue(Queue* q) {
    if (isEmpty(q)) return -1; // Queue is empty
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

int main() {
    // Read number of vertices in the graph
    int N;
    scanf("%d", &N);

    // Initialize adjacency list
    int adj[MAX_N + 1][MAX_N];
    int adj_size[MAX_N + 1] = {0}; // To keep track of the number of edges for each vertex

    // Read edges and add them to the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][adj_size[a]++] = b;
        adj[b][adj_size[b]++] = a;
    }

    // Initialize queue for BFS traversal
    Queue que;
    initQueue(&que);
    enqueue(&que, 1);

    // Initialize arrays for seen, parent, and child count
    int seen[MAX_N + 1] = {0};
    int par[MAX_N + 1] = {0};
    int child_num[MAX_N + 1] = {0};

    // BFS traversal
    seen[1] = 1;
    while (!isEmpty(&que)) {
        int v = dequeue(&que);
        for (int i = 0; i < adj_size[v]; i++) {
            int u = adj[v][i];
            if (seen[u] == 0) {
                seen[u] = 1;
                par[u] = v;
                child_num[v]++;
                enqueue(&que, u);
            }
        }
    }

    // Initialize queue for topological order
    Queue seq;
    initQueue(&seq);

    // Find vertices with no incoming edges
    for (int i = 1; i <= N; i++) {
        if (child_num[i] == 0) {
            enqueue(&seq, i);
        }
    }

    // Topological sort
    while (!isEmpty(&seq)) {
        int c = dequeue(&seq);
        if (seen[par[c]] == 0) {
            printf("First\n");
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        if (child_num[par[par[c]]] == 0) {
            enqueue(&seq, par[par[c]]);
        }
    }

    // If all vertices have been processed
    printf("Second\n");
    return 0;
}

// <END-OF-CODE>
