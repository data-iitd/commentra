#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000
#define INF 1000000000000000000LL

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
    queue->rear = 0;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, int item) {
    queue->data[queue->rear++] = item;
}

int dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int **edge = (int**)malloc(N * sizeof(int*));
    int *edgeSize = (int*)calloc(N, sizeof(int));
    
    for (int i = 0; i < N; i++) {
        edge[i] = (int*)malloc(M * sizeof(int)); // Allocate maximum size for edges
    }

    for (int i = 0; i < M; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        X--; Y--; // Convert to 0-based index
        edge[X][edgeSize[X]++] = Y;
        edge[Y][edgeSize[Y]++] = X;
    }

    bool *used = (bool*)calloc(N, sizeof(bool));
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;
            Queue* queue = createQueue(N);
            enqueue(queue, i);
            while (!isEmpty(queue)) {
                int node = dequeue(queue);
                used[node] = true;
                for (int j = 0; j < edgeSize[node]; j++) {
                    int nextnode = edge[node][j];
                    if (!used[nextnode]) {
                        enqueue(queue, nextnode);
                    }
                }
            }
            freeQueue(queue);
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < N; i++) {
        free(edge[i]);
    }
    free(edge);
    free(edgeSize);
    free(used);

    return 0;
}

// <END-OF-CODE>
