#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

void initHeap(MinHeap *heap, int capacity) {
    heap->data = (int *)malloc(capacity * sizeof(int) * 2); // Store (degree, index)
    heap->size = 0;
    heap->capacity = capacity;
}

void swap(MinHeap *heap, int i, int j) {
    int temp1 = heap->data[i * 2];
    int temp2 = heap->data[i * 2 + 1];
    heap->data[i * 2] = heap->data[j * 2];
    heap->data[i * 2 + 1] = heap->data[j * 2 + 1];
    heap->data[j * 2] = temp1;
    heap->data[j * 2 + 1] = temp2;
}

void insertHeap(MinHeap *heap, int degree, int index) {
    if (heap->size >= heap->capacity) return;
    heap->data[heap->size * 2] = degree;
    heap->data[heap->size * 2 + 1] = index;
    heap->size++;
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[i * 2] < heap->data[parent * 2]) {
            swap(heap, i, parent);
            i = parent;
        } else {
            break;
        }
    }
}

void popHeap(MinHeap *heap, int *degree, int *index) {
    if (heap->size == 0) return;
    *degree = heap->data[0];
    *index = heap->data[1];
    heap->data[0] = heap->data[(heap->size - 1) * 2];
    heap->data[1] = heap->data[(heap->size - 1) * 2 + 1];
    heap->size--;
    int i = 0;
    while (i * 2 + 1 < heap->size) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int smallest = left;
        if (right < heap->size && heap->data[right * 2] < heap->data[left * 2]) {
            smallest = right;
        }
        if (heap->data[i * 2] > heap->data[smallest * 2]) {
            swap(heap, i, smallest);
            i = smallest;
        } else {
            break;
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    if (M % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    int *degs = (int *)calloc(N, sizeof(int));
    int **edges = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(N * sizeof(int));
    }
    bool *flag = (bool *)calloc(N, sizeof(bool));
    int *parity = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a][degs[a]++] = b;
        edges[b][degs[b]++] = a;
    }

    MinHeap heap;
    initHeap(&heap, N);
    for (int i = 0; i < N; i++) {
        insertHeap(&heap, degs[i], i);
    }

    while (heap.size > 0) {
        int u, degree;
        popHeap(&heap, &degree, &u);
        if (flag[u]) continue;
        flag[u] = true;

        for (int i = 0; i < degs[u]; i++) {
            int v = edges[u][i];
            if (flag[v]) continue;

            // Print the edge based on parity
            if (parity[u] != 0 && i == 0) {
                printf("%d %d\n", u + 1, v + 1);
                parity[u] = 1 - parity[u];
            } else {
                printf("%d %d\n", v + 1, u + 1);
                parity[v] = 1 - parity[v];
            }

            // Decrement degree and update heap
            degs[v]--;
            insertHeap(&heap, degs[v], v);
        }
    }

    // Free allocated memory
    free(degs);
    free(flag);
    free(parity);
    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(heap.data);

    return 0;
}

// <END-OF-CODE>
