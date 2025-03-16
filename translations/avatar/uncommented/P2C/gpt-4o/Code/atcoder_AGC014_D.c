#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q, int size) {
    q->data = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->size = size;
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
    
    int adj[MAX_N + 1][MAX_N + 1] = {0}; // Adjacency list
    int child_num[MAX_N + 1] = {0};
    int par[MAX_N + 1] = {0};
    int seen[MAX_N + 1] = {0};
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][child_num[a]++] = b;
        adj[b][child_num[b]++] = a;
    }
    
    Queue que;
    initQueue(&que, N);
    enqueue(&que, 1);
    seen[1] = 1;
    
    while (!isEmpty(&que)) {
        int v = dequeue(&que);
        for (int j = 0; j < child_num[v]; j++) {
            int u = adj[v][j];
            if (seen[u] == 0) {
                seen[u] = 1;
                par[u] = v;
                que.data[v]++; // Increment child count for v
                enqueue(&que, u);
            }
        }
    }
    
    Queue seq;
    initQueue(&seq, N);
    for (int i = 1; i <= N; i++) {
        if (child_num[i] == 0) {
            enqueue(&seq, i);
        }
    }
    
    while (!isEmpty(&seq)) {
        int c = dequeue(&seq);
        seen[c] = 0;
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
    
    printf("Second\n");
    return 0;
}

// <END-OF-CODE>
