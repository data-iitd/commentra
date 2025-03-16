#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct {
    int degree;
    int node;
} HeapNode;

typedef struct {
    HeapNode data[MAX_N];
    int size;
} MinHeap;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    while (index > 0 && heap->data[index].degree < heap->data[(index - 1) / 2].degree) {
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left].degree < heap->data[smallest].degree) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right].degree < heap->data[smallest].degree) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insertHeap(MinHeap *heap, HeapNode node) {
    heap->data[heap->size] = node;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

HeapNode extractMin(MinHeap *heap) {
    HeapNode minNode = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return minNode;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int edges[N][N];
    int degs[N];
    bool parity[N];
    bool flag[N];

    for (int i = 0; i < N; i++) {
        degs[i] = 0;
        parity[i] = 0;
        flag[i] = false;
        for (int j = 0; j < N; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[a][degs[a]++] = b;
        edges[b][degs[b]++] = a;
    }

    if (M % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    MinHeap Q;
    Q.size = 0;

    for (int i = 0; i < N; i++) {
        HeapNode node;
        node.degree = degs[i];
        node.node = i;
        insertHeap(&Q, node);
    }

    while (Q.size > 0) {
        HeapNode minNode = extractMin(&Q);
        int u = minNode.node;

        if (flag[u]) {
            continue;
        }

        flag[u] = true;

        for (int i = 0; i < degs[u]; i++) {
            int v = edges[u][i];
            edges[v][degs[v]--] = 0;
            if (parity[u] != 0 && i == 0) {
                printf("%d %d\n", u + 1, v + 1);
                parity[u] = 1 - parity[u];
            } else {
                printf("%d %d\n", v + 1, u + 1);
                parity[v] = 1 - parity[v];
            }
            HeapNode newNode;
            newNode.degree = degs[v];
            newNode.node = v;
            insertHeap(&Q, newNode);
        }
    }

    return 0;
}
