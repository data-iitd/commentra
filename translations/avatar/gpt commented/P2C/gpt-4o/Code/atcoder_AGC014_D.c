#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
    int *data;
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->data = (int *)malloc(MAX_N * sizeof(int));
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue *q, int value) {
    q->data[q->rear++] = value;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int main() {
    int N;
    scanf("%d", &N);

    // Initialize adjacency list for the tree
    int adj[MAX_N + 1][MAX_N + 1] = {0};
    int child_num[MAX_N + 1] = {0};
    int par[MAX_N + 1] = {0};
    int seen[MAX_N + 1] = {0};

    // Read edges and build the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][child_num[a]++] = b;
        adj[b][child_num[b]++] = a;
    }

    // Initialize a queue for BFS and mark the starting node
    Queue que;
    initQueue(&que);
    enqueue(&que, 1);
    seen[1] = 1;  // Mark the root node as seen

    // Perform BFS to populate parent and child count information
    while (!isEmpty(&que)) {
        int v = dequeue(&que);  // Get the current node
        for (int j = 0; j < child_num[v]; j++) {  // Iterate through adjacent nodes
            int u = adj[v][j];
            if (seen[u] == 0) {  // If the node has not been visited
                seen[u] = 1;  // Mark it as seen
                par[u] = v;  // Set the parent of the node
                enqueue(&que, u);  // Add the node to the queue for further exploration
            }
        }
    }

    // Initialize a queue to process leaf nodes
    Queue seq;
    initQueue(&seq);

    // Identify all leaf nodes (nodes with no children)
    for (int i = 1; i <= N; i++) {
        if (child_num[i] == 1) {  // A leaf node has only one connection (to its parent)
            enqueue(&seq, i);
        }
    }

    // Process the leaf nodes in reverse order
    while (!isEmpty(&seq)) {
        int c = dequeue(&seq);  // Get the current leaf node
        seen[c] = 0;  // Mark the leaf node as unseen
        if (seen[par[c]] == 0) {  // Check if the parent is unseen
            printf("First\n");  // If so, print 'First' and exit
            return 0;
        }
        seen[par[c]] = 0;  // Mark the parent as unseen
        child_num[par[c]]--;  // Decrement the child count of the parent
        if (child_num[par[c]] == 1) {  // If the parent has no children left
            enqueue(&seq, par[c]);  // Add the parent to the sequence for processing
        }
    }

    // If all nodes are processed without triggering 'First', print 'Second'
    printf("Second\n");

    // Free allocated memory
    free(que.data);
    free(seq.data);

    return 0;
}

// <END-OF-CODE>
