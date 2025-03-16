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
    int front;
    int rear;
    int size;
    QueueNode data[MAX_N];
} Queue;

void enqueue(Queue *q, int node, int color) {
    q->data[q->rear].node = node;
    q->data[q->rear].color = color;
    q->rear = (q->rear + 1) % MAX_N;
    q->size++;
}

QueueNode dequeue(Queue *q) {
    QueueNode node = q->data[q->front];
    q->front = (q->front + 1) % MAX_N;
    q->size--;
    return node;
}

int bfs(int v, int N, int G[MAX_N][], int E[], int node2color[]) {
    bool visited[MAX_N] = { false };
    Queue queue = { 0, 0, 0 };
    int K = -1;

    enqueue(&queue, v, 0);
    visited[v] = true;

    while (queue.size > 0) {
        QueueNode q = dequeue(&queue);
        int color = 0;

        for (int i = 0; i < N; i++) {
            int nex = G[q.node][i];
            if (visited[nex]) continue;

            visited[nex] = true;
            color++;

            if (color == node2color[q.node]) {
                color++;
            }

            node2color[nex] = color;
            E[(q.node < nex) ? (Edge){q.node, nex} : (Edge){nex, q.node}] = color;

            enqueue(&queue, nex, color);
        }

        K = (K > color) ? K : color;
    }

    return K;
}

int main() {
    int N;
    scanf("%d", &N);

    int G[MAX_N][];
    Edge E[MAX_N];
    int node2color[MAX_N];

    for (int i = 0; i < N; i++) {
        G[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            G[i][j] = 0;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a][G[a][0]++] = b;
        G[b][G[b][0]++] = a;
        E[i] = (Edge){a, b};
        node2color[i] = -1;
    }

    int K = bfs(0, N, G, E, node2color);
    printf("%d\n", K);

    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", E[i].color);
    }

    for (int i = 0; i < N; i++) {
        free(G[i]);
    }

    return 0;
}
