#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

typedef struct {
    int *data;
    int size;
    int capacity;
} MaxHeap;

void initMinHeap(MinHeap *heap, int capacity) {
    heap->data = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
}

void initMaxHeap(MaxHeap *heap, int capacity) {
    heap->data = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapInsert(MinHeap *heap, int value) {
    if (heap->size == heap->capacity) return;
    heap->data[heap->size] = value;
    int i = heap->size;
    heap->size++;
    while (i > 0 && heap->data[i] < heap->data[(i - 1) / 2]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapInsert(MaxHeap *heap, int value) {
    if (heap->size == heap->capacity) return;
    heap->data[heap->size] = value;
    int i = heap->size;
    heap->size++;
    while (i > 0 && heap->data[i] > heap->data[(i - 1) / 2]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int minHeapExtractMin(MinHeap *heap) {
    if (heap->size == 0) return -1; // or some error value
    int min = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }
        if (smallest == i) break;
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
    return min;
}

int maxHeapExtractMax(MaxHeap *heap) {
    if (heap->size == 0) return -1; // or some error value
    int max = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heap->size && heap->data[left] > heap->data[largest]) {
            largest = left;
        }
        if (right < heap->size && heap->data[right] > heap->data[largest]) {
            largest = right;
        }
        if (largest == i) break;
        swap(&heap->data[i], &heap->data[largest]);
        i = largest;
    }
    return max;
}

int main() {
    int t;
    scanf("%d", &t);

    MinHeap pqmin;
    MaxHeap pqmax;
    initMinHeap(&pqmin, MAX_SIZE);
    initMaxHeap(&pqmax, MAX_SIZE);

    long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    while (t-- > 0) {
        int command;
        scanf("%d", &command);
        if (command == 2) {
            long ans = min * pqmin.size;
            ans -= sumMin;
            long ans1 = min * pqmax.size;
            ans1 = sumMax - ans1;

            printf("%d %ld\n", min, ans + ans1 + sumb);
        } else {
            int in;
            long additional;
            scanf("%d %ld", &in, &additional);
            sumb += additional;

            if (in > min) {
                maxHeapInsert(&pqmax, in);
                sumMax += in;
            } else {
                minHeapInsert(&pqmin, in);
                sumMin += in;
            }

            if (pqmin.size > pqmax.size) {
                sumMax += pqmin.data[0];
                sumMin -= pqmin.data[0];
                maxHeapInsert(&pqmax, minHeapExtractMin(&pqmin));
            }
            if (pqmin.size < pqmax.size) {
                sumMax -= pqmax.data[0];
                sumMin += pqmax.data[0];
                minHeapInsert(&pqmin, maxHeapExtractMax(&pqmax));
            }

            if (pqmin.size > 0) {
                min = pqmin.data[0];
            }
        }
    }

    free(pqmin.data);
    free(pqmax.data);
    return 0;
}

// <END-OF-CODE>
