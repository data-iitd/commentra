#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100000

typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

typedef struct {
    int *arr;
    int size;
    int capacity;
} MaxHeap;

void initMinHeap(MinHeap *heap, int capacity) {
    heap->arr = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
}

void initMaxHeap(MaxHeap *heap, int capacity) {
    heap->arr = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUpMin(MinHeap *heap, int index) {
    while (index > 0 && heap->arr[index] < heap->arr[(index - 1) / 2]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyUpMax(MaxHeap *heap, int index) {
    while (index > 0 && heap->arr[index] > heap->arr[(index - 1) / 2]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDownMin(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDownMin(heap, smallest);
    }
}

void heapifyDownMax(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapifyDownMax(heap, largest);
    }
}

void insertMinHeap(MinHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->arr = (int *)realloc(heap->arr, heap->capacity * sizeof(int));
    }
    heap->arr[heap->size] = value;
    heap->size++;
    heapifyUpMin(heap, heap->size - 1);
}

void insertMaxHeap(MaxHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->arr = (int *)realloc(heap->arr, heap->capacity * sizeof(int));
    }
    heap->arr[heap->size] = value;
    heap->size++;
    heapifyUpMax(heap, heap->size - 1);
}

int extractMin(MinHeap *heap) {
    if (heap->size == 0) {
        return INT_MAX;
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDownMin(heap, 0);
    return root;
}

int extractMax(MaxHeap *heap) {
    if (heap->size == 0) {
        return INT_MIN;
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDownMax(heap, 0);
    return root;
}

int main() {
    int q;
    scanf("%d", &q);
    int ans[2] = {0, 0};

    MinHeap p1;
    initMinHeap(&p1, MAX_HEAP_SIZE);
    MaxHeap p2;
    initMaxHeap(&p2, MAX_HEAP_SIZE);

    int sum_b = 0;
    int sum_p1 = 0;
    int sum_p2 = 0;

    for (int i = 0; i < q; i++) {
        int query[3];
        scanf("%d %d %d", &query[0], &query[1], &query[2]);

        if (query[0] == 2) {
            if (p1.size == p2.size) {
                printf("%d %d\n", -p2.arr[0], sum_p1 - p1.size * -p2.arr[0] + p2.size * -p2.arr[0] - sum_p2 + sum_b);
            } else {
                printf("%d %d\n", p1.arr[0], sum_p1 - p1.size * p1.arr[0] + p2.size * p1.arr[0] - sum_p2 + sum_b);
            }
        } else {
            sum_b += query[2];

            if (p1.size == 0) {
                insertMinHeap(&p1, query[1]);
                sum_p1 += query[1];
            } else if (p1.arr[0] <= query[1]) {
                insertMinHeap(&p1, query[1]);
                sum_p1 += query[1];
            } else {
                insertMaxHeap(&p2, query[1]);
                sum_p2 += query[1];
                sum_p1 -= query[1];
                sum_p2 -= query[1];
            }

            if (p1.size < p2.size) {
                int k = extractMin(&p2);
                insertMaxHeap(&p1, k);
                sum_p2 += k;
                sum_p1 -= k;
            }

            if (p1.size - 1 > p2.size) {
                int k = extractMax(&p1);
                insertMinHeap(&p2, k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }

    free(p1.arr);
    free(p2.arr);
    return 0;
}
