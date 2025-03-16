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

int popBack(Deque *deque) {
    return deque->data[--deque->rear];
}

int isEmpty(Deque *deque) {
    return deque->front == deque->rear;
}

int main() {
    int N;
    scanf("%d", &N);

    // Initialize adjacency list
    int **adj = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        adj[i] = (int *)malloc(N * sizeof(int));
    }

    // Read N-1 edges
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1; // Mark edge a-b
        adj[b][a] = 1; // Mark edge b-a
    }

    // Initialize deque for BFS and seen array
    Deque que;
    initDeque(&que, N);
    pushBack(&que, 1);
    
    int *seen = (int *)calloc(N + 1, sizeof(int));
    seen[1] = 1;

    // Parent and child count arrays
    int *par = (int *)calloc(N + 1, sizeof(int));
    int *child_num = (int *)calloc(N + 1, sizeof(int));

    // Perform BFS
    while (!isEmpty(&que)) {
        int v = popBack(&que);
        for (int u = 1; u <= N; u++) {
            if (adj[v][u] && !seen[u]) {
                seen[u] = 1;
                par[u] = v;
                child_num[v]++;
                pushBack(&que, u);
            }
        }
    }

    // Find leaf nodes
    Deque seq;
    initDeque(&seq, N);
    for (int i = 1; i <= N; i++) {
        if (child_num[i] == 0) {
            pushBack(&seq, i);
        }
    }

    // Process leaf nodes
    while (!isEmpty(&seq)) {
        int c = popBack(&seq);
        seen[c] = 0;
        if (seen[par[c]] == 0) {
            printf("First\n");
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        if (child_num[par[par[c]]] == 0) {
            pushBack(&seq, par[par[c]]);
        }
    }

    // If no winning strategy is found for the first player
    printf("Second\n");

    // Free allocated memory
    for (int i = 0; i <= N; i++) {
        free(adj[i]);
    }
    free(adj);
    free(seen);
    free(par);
    free(child_num);
    free(que.data);
    free(seq.data);

    return 0;
}

// <END-OF-CODE>
