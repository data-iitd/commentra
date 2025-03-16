#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100000

// Structure to represent a min-heap
typedef struct {
    int degree;
    int vertex;
} HeapNode;

HeapNode heap[MAX_VERTICES];
int heapSize = 0;

// Function to swap two heap nodes
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a node into the min-heap
void insertHeap(int degree, int vertex) {
    heap[heapSize].degree = degree;
    heap[heapSize].vertex = vertex;
    int i = heapSize++;
    while (i > 0 && heap[i].degree < heap[(i - 1) / 2].degree) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove the minimum node from the min-heap
HeapNode removeMin() {
    HeapNode minNode = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (i * 2 + 1 < heapSize) {
        int smallest = i * 2 + 1;
        if (smallest + 1 < heapSize && heap[smallest + 1].degree < heap[smallest].degree) {
            smallest++;
        }
        if (heap[i].degree <= heap[smallest].degree) {
            break;
        }
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return minNode;
}

// Function to check if the vertex is in the heap
int isInHeap(int vertex) {
    for (int i = 0; i < heapSize; i++) {
        if (heap[i].vertex == vertex) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize adjacency list, degrees, parity, and visited arrays
    int edges[MAX_VERTICES][MAX_VERTICES];
    int degs[MAX_VERTICES] = {0};
    int parity[MAX_VERTICES] = {0};
    int flag[MAX_VERTICES] = {0};

    // Read edges and populate the adjacency list and degrees
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a - 1][degs[a - 1]++] = b - 1;
        edges[b - 1][degs[b - 1]++] = a - 1;
    }

    // Check if the number of edges is even
    if (M % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    // Insert vertices into the heap based on their degrees
    for (int i = 0; i < N; i++) {
        insertHeap(degs[i], i);
    }

    // Process the heap until it is empty
    while (heapSize > 0) {
        HeapNode minNode = removeMin();
        int u = minNode.vertex;

        // Skip if vertex is already visited
        if (flag[u]) {
            continue;
        }
        // Mark vertex as visited
        flag[u] = 1;

        // Iterate through all adjacent vertices
        for (int i = 0; i < degs[u]; i++) {
            int v = edges[u][i];

            // Skip if vertex is already visited
            if (flag[v]) {
                continue;
            }

            // Print edge and update parity of both vertices
            if (parity[u] != 0 && i == 0) {
                printf("%d %d\n", u + 1, v + 1);
                parity[u] = 1 - parity[u];
            } else {
                printf("%d %d\n", v + 1, u + 1);
                parity[v] = 1 - parity[v];
            }

            // Decrease degree of adjacent vertex and insert it into the heap
            degs[v]--;
            if (!isInHeap(v)) {
                insertHeap(degs[v], v);
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
