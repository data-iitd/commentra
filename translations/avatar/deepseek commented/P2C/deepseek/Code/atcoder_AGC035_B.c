#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct {
    int deg;
    int node;
} HeapNode;

typedef struct {
    HeapNode data[MAX_N];
    int size;
} MinHeap;

void initHeap(MinHeap *heap) {
    heap->size = 0;
}

void pushHeap(MinHeap *heap, HeapNode node) {
    heap->data[heap->size++] = node;
    int i = heap->size - 1;
    while (i > 0 && heap->data[i].deg < heap->data[(i - 1) / 2].deg) {
        HeapNode temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

HeapNode popHeap(MinHeap *heap) {
    HeapNode root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (2 * i + 1 < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (heap->data[left].deg < heap->data[smallest].deg) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right].deg < heap->data[smallest].deg) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }
        HeapNode temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        i = smallest;
    }
    return root;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int edges[MAX_N][2];
    int degs[MAX_N] = {0};
    int parity[MAX_N] = {0};
    bool flag[MAX_N] = {false};

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[i][0] = a;
        edges[i][1] = b;
        degs[a]++;
        degs[b]++;
    }

    if (M % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    MinHeap heap;
    initHeap(&heap);

    for (int i = 0; i < N; i++) {
        HeapNode node = {degs[i], i};
        pushHeap(&heap, node);
    }

    while (heap.size > 0) {
        HeapNode top = popHeap(&heap);
        int u = top.node;

        if (flag[u]) {
            continue;
        }

        flag[u] = true;

        for (int i = 0; i < M; i++) {
            if (edges[i][0] == u || edges[i][1] == u) {
                int v = edges[i][0] == u ? edges[i][1] : edges[i][0];
                edges[i][0] = edges[i][1] = -1;

                if (parity[u] != 0) {
                    printf("%d %d\n", u + 1, v + 1);
                    parity[u] = 1 - parity[u];
                } else {
                    printf("%d %d\n", v + 1, u + 1);
                    parity[v] = 1 - parity[v];
                }

                degs[v]--;
                HeapNode updatedNode = {degs[v], v};
                pushHeap(&heap, updatedNode);
            }
        }
    }

    return 0;
}
