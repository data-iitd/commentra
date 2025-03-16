#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Deque;

void initDeque(Deque *deque, int capacity) {
    deque->data = (int *)malloc(capacity * sizeof(int));
    deque->front = 0;
    deque->rear = 0;
    deque->capacity = capacity;
}

void pushBack(Deque *deque, int value) {
    deque->data[deque->rear++] = value;
}

int popFront(Deque *deque) {
    return deque->data[deque->front++];
}

int isEmpty(Deque *deque) {
    return deque->front == deque->rear;
}

void freeDeque(Deque *deque) {
    free(deque->data);
}

int bfs(int v, int N, Deque *G, int *E) {
    int visited[MAX_N] = {0};
    Deque queue;
    initDeque(&queue, N);
    int K = -1;
    int node2color[MAX_N] = {-1};

    pushBack(&queue, v);
    visited[v] = 1;

    while (!isEmpty(&queue)) {
        int q = popFront(&queue);
        int color = 0;

        for (int i = 0; i < G[q].rear; i++) {
            int nex = G[q].data[i];
            if (visited[nex]) {
                continue;
            }
            visited[nex] = 1;
            color++;

            if (color == node2color[q]) {
                color++;
            }

            node2color[nex] = color;
            E[(q < nex) ? (q * N + nex) : (nex * N + q)] = color;
            pushBack(&queue, nex);
        }
        K = (color > K) ? color : K;
    }

    freeDeque(&queue);
    return K;
}

int main() {
    int N;
    scanf("%d", &N);
    Deque G[MAX_N];
    for (int i = 0; i < N; i++) {
        initDeque(&G[i], N);
    }
    int *E = (int *)calloc(N * N, sizeof(int));

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        pushBack(&G[a], b);
        pushBack(&G[b], a);
        E[(a < b) ? (a * N + b) : (b * N + a)] = 0;
    }

    int K = bfs(0, N, G, E);
    printf("%d\n", K);
    for (int i = 0; i < N * N; i++) {
        if (E[i] != 0) {
            printf("%d\n", E[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        freeDeque(&G[i]);
    }
    free(E);
    return 0;
}

// <END-OF-CODE>
