#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

void initHeap(MinHeap *heap, int capacity) {
    heap->data = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
}

void push(MinHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int *)realloc(heap->data, heap->capacity * sizeof(int));
    }
    heap->data[heap->size++] = value;
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[parent] <= heap->data[i]) break;
        int temp = heap->data[parent];
        heap->data[parent] = heap->data[i];
        heap->data[i] = temp;
        i = parent;
    }
}

int pop(MinHeap *heap) {
    if (heap->size == 0) return -1; // Heap is empty
    int root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap->size && heap->data[left] < heap->data[smallest]) smallest = left;
        if (right < heap->size && heap->data[right] < heap->data[smallest]) smallest = right;
        if (smallest == i) break;
        int temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        i = smallest;
    }
    return root;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int **edges = (int **)malloc(N * sizeof(int *));
    int *degs = (int *)calloc(N, sizeof(int));
    int *parity = (int *)calloc(N, sizeof(int));
    bool *flag = (bool *)calloc(N, sizeof(bool));
    
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            edges[i][j] = -1; // Initialize with -1 (no edge)
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--; // Convert to 0-based index
        edges[a][degs[a]] = b;
        edges[b][degs[b]] = a;
        degs[a]++;
        degs[b]++;
    }

    if (M % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    MinHeap Q;
    initHeap(&Q, N);
    for (int i = 0; i < N; i++) {
        push(&Q, degs[i]);
    }

    while (Q.size > 0) {
        int u = pop(&Q);
        if (flag[u]) continue;
        flag[u] = true;

        for (int i = 0; i < degs[u]; i++) {
            int v = edges[u][i];
            if (v == -1) continue; // Skip if no edge
            edges[v][u] = -1; // Remove edge
            if (parity[u] != 0 && i == 0) {
                printf("%d %d\n", u + 1, v + 1);
                parity[u] = 1 - parity[u];
            } else {
                printf("%d %d\n", v + 1, u + 1);
                parity[v] = 1 - parity[v];
            }
            degs[v]--;
            push(&Q, degs[v]);
        }
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(degs);
    free(parity);
    free(flag);
    free(Q.data);

    return 0;
}

// <END-OF-CODE>
