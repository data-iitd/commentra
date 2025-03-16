#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct {
    int data[MAX_N];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_N - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void bfs(int v, int N, int G[MAX_N][], int E[MAX_N][MAX_N], int *K) {
    bool visited[MAX_N] = {false};
    int node2color[MAX_N];
    for (int i = 0; i < N; i++) {
        node2color[i] = -1;
    }
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, v);
    visited[v] = true;
    node2color[v] = 0;
    while (!isEmpty(&queue)) {
        int q = dequeue(&queue);
        int color = 0;
        for (int i = 0; i < N; i++) {
            if (G[q][i] && !visited[i]) {
                visited[i] = true;
                color++;
                if (color == node2color[q]) {
                    color++;
                }
                node2color[i] = color;
                E[q][i] = color;
                E[i][q] = color;
                enqueue(&queue, i);
            }
        }
        if (color > *K) {
            *K = color;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int G[MAX_N][MAX_N] = {0};
    int E[MAX_N][MAX_N] = {0};
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int K = -1;
    bfs(0, N, G, E, &K);
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
