#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e18

typedef struct {
    int size;
    int *data;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0;
    queue->data = (int*)malloc(size * sizeof(int));
    return queue;
}

void enqueue(Queue* queue, int item) {
    queue->data[queue->size++] = item;
}

int dequeue(Queue* queue) {
    int item = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->size--;
    return item;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void bfs(int node, bool *used, int **edge, int N) {
    Queue* queue = createQueue(N);
    used[node] = true;
    enqueue(queue, node);
    while (!isEmpty(queue)) {
        int current = dequeue(queue);
        for (int i = 0; i < edge[current][0]; i++) {
            int nextnode = edge[current][i + 1];
            if (!used[nextnode]) {
                used[nextnode] = true;
                enqueue(queue, nextnode);
            }
        }
    }
    free(queue);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int **edge = (int**)malloc((N + 1) * sizeof(int*));
    for (int i = 0; i < N + 1; i++) {
        edge[i] = (int*)malloc(N * sizeof(int));
        edge[i][0] = 0;
    }
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        scanf("%d %d %d", &X, &Y, &Z);
        X--; Y--;
        edge[X][++edge[X][0]] = Y;
        edge[Y][++edge[Y][0]] = X;
    }
    bool *used = (bool*)malloc(N * sizeof(bool));
    for (int i = 0; i < N; i++) {
        used[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;
            bfs(i, used, edge, N);
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < N + 1; i++) {
        free(edge[i]);
    }
    free(edge);
    free(used);
    return 0;
}
