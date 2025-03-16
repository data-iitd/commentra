#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct {
    int first;
    int second;
} Edge;

typedef struct {
    int node;
    int color;
} QueueNode;

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

void enqueue(Queue *q, int node, int color) {
    q->data[q->rear] = node;
    q->data[q->rear + 1] = color;
    q->rear += 2;
    q->size += 2;
}

QueueNode dequeue(Queue *q) {
    QueueNode node;
    node.node = q->data[q->front];
    node.color = q->data[q->front + 1];
    q->front += 2;
    q->size -= 2;
    return node;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

void bfs(int v, int N, int *G[], Edge edges[], int *node2color, int *K) {
    bool visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    Queue queue = {malloc(2 * MAX_N * sizeof(int)), 0, 0, 0};
    enqueue(&queue, v, 0);
    visited[v] = true;
    while (!isEmpty(&queue)) {
        QueueNode q = dequeue(&queue);
        int node = q.node;
        int color = 0;
        for (int i = 0; i < N; i++) {
            int nex = G[node][i];
            if (visited[nex]) {
                continue;
            }
            visited[nex] = true;
            color++;
            if (color == node2color[node]) {
                color++;
            }
            node2color[nex] = color;
            edges[*K].first = node;
            edges[*K].second = nex;
            (*K)++;
            enqueue(&queue, nex, color);
        }
        if (color > *K) {
            *K = color;
        }
    }
    free(queue.data);
}

int main() {
    int N;
    scanf("%d", &N);
    int *G[N];
    for (int i = 0; i < N; i++) {
        G[i] = malloc(N * sizeof(int));
    }
    Edge edges[N - 1];
    int node2color[N];
    for (int i = 0; i < N; i++) {
        node2color[i] = -1;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        G[a][i] = b;
        G[b][i] = a;
    }
    int K = 0;
    bfs(0, N, G, edges, node2color, &K);
    printf("%d\n", K);
    for (int i = 0; i < K; i++) {
        printf("%d\n", edges[i].first < edges[i].second ? edges[i].first : edges[i].second);
    }
    for (int i = 0; i < N; i++) {
        free(G[i]);
    }
    return 0;
}
