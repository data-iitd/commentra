#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;

void initMinHeap(MinHeap *heap) {
    heap->size = 0;
}

void initMaxHeap(MaxHeap *heap) {
    heap->size = 0;
}

void minHeapPush(MinHeap *heap, int value) {
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

void maxHeapPush(MaxHeap *heap, int value) {
    heap->data[heap->size++] = value;
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[parent] >= heap->data[i]) break;
        int temp = heap->data[parent];
        heap->data[parent] = heap->data[i];
        heap->data[i] = temp;
        i = parent;
    }
}

int minHeapPop(MinHeap *heap) {
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

int maxHeapPop(MaxHeap *heap) {
    int root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heap->size && heap->data[left] > heap->data[largest]) largest = left;
        if (right < heap->size && heap->data[right] > heap->data[largest]) largest = right;
        if (largest == i) break;
        int temp = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = temp;
        i = largest;
    }
    return root;
}

int main() {
    int q;
    scanf("%d", &q);
    
    MinHeap p1;
    MaxHeap p2;
    initMinHeap(&p1);
    initMaxHeap(&p2);
    
    long long sum_b = 0;
    long long sum_p1 = 0;
    long long sum_p2 = 0;

    for (int i = 0; i < q; i++) {
        int query[3];
        scanf("%d", &query[0]);
        if (query[0] == 2) {
            if (p1.size == p2.size) {
                printf("%d %lld\n", -p2.data[0], sum_p1 - p1.size * -p2.data[0] + p2.size * -p2.data[0] - sum_p2 + sum_b);
            } else {
                printf("%d %lld\n", p1.data[0], sum_p1 - p1.size * p1.data[0] + p2.size * p1.data[0] - sum_p2 + sum_b);
            }
        } else {
            scanf("%d %d", &query[1], &query[2]);
            sum_b += query[2];
            if (p1.size == 0) {
                minHeapPush(&p1, query[1]);
                sum_p1 += query[1];
            } else if (p1.data[0] <= query[1]) {
                minHeapPush(&p1, query[1]);
                sum_p1 += query[1];
            } else {
                maxHeapPush(&p2, query[1]);
                sum_p2 += query[1];
            }
            if (p1.size < p2.size) {
                int k = maxHeapPop(&p2);
                minHeapPush(&p1, -k);
                sum_p2 += k;
                sum_p1 -= k;
            }
            if (p1.size - 1 > p2.size) {
                int k = minHeapPop(&p1);
                maxHeapPush(&p2, -k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }
    return 0;
}

// <END-OF-CODE>
