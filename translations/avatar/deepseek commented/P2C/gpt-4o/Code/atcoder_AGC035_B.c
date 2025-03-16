#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

void initHeap(MinHeap *heap, int capacity) {
    heap->data = (int *)malloc(capacity * sizeof(int) * 2); // Store (degree, node) pairs
    heap->size = 0;
    heap->capacity = capacity;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *heap, int degree, int node) {
    if (heap->size >= heap->capacity) return;
    heap->data[heap->size * 2] = degree;
    heap->data[heap->size * 2 + 1] = node;
    heap->size++;
    
    // Bubble up
    int index = heap->size - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->data[index * 2] < heap->data[parent * 2]) {
            swap(&heap->data[index * 2], &heap->data[parent * 2]);
            swap(&heap->data[index * 2 + 1], &heap->data[parent * 2 + 1]);
            index = parent;
        } else {
            break;
        }
    }
}

void pop(MinHeap *heap, int *degree, int *node) {
    if (heap->size == 0) return;
    *degree = heap->data[0];
    *node = heap->data[1];
    
    // Move the last element to the root and bubble down
    heap->data[0] = heap->data[(heap->size - 1) * 2];
    heap->data[1] = heap->data[(heap->size - 1) * 2 + 1];
    heap->size--;
    
    int index = 0;
    while (index * 2 + 2 < heap->size * 2) {
        int left = index * 2 + 2;
        int right = index * 2 + 4;
        int smallest = left;
        
        if (right < heap->size * 2 && heap->data[right] < heap->data[left]) {
            smallest = right;
        }
        
        if (heap->data[smallest] < heap->data[index * 2]) {
            swap(&heap->data[index * 2], &heap->data[smallest]);
            swap(&heap->data[index * 2 + 1], &heap->data[smallest + 1]);
            index = smallest / 2;
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
    
    int edges[MAX_NODES][MAX_NODES] = {0};
    int degs[MAX_NODES] = {0};
    int parity[MAX_NODES] = {0};
    int flag[MAX_NODES] = {0};
    
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a][degs[a]++] = b;
        edges[b][degs[b]++] = a;
    }
    
    MinHeap Q;
    initHeap(&Q, N);
    
    for (int i = 0; i < N; i++) {
        push(&Q, degs[i], i);
    }
    
    while (Q.size > 0) {
        int u, degree;
        pop(&Q, &degree, &u);
        
        if (flag[u]) continue;
        flag[u] = 1;
        
        for (int i = 0; i < degs[u]; i++) {
            int v = edges[u][i];
            if (v == -1) continue; // Skip if already processed
            
            // Print the edge in the required format, alternating the direction based on the parity
            if (parity[u] != 0) {
                printf("%d %d\n", u + 1, v + 1);
                parity[u] = 1 - parity[u];
            } else {
                printf("%d %d\n", v + 1, u + 1);
                parity[v] = 1 - parity[v];
            }
            
            // Update the degree
            degs[v]--;
            push(&Q, degs[v], v);
        }
    }
    
    free(Q.data);
    return 0;
}

// <END-OF-CODE>
