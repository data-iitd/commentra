#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int *data;
    int size;
} MaxHeap;

typedef struct {
    int *data;
    int size;
} MinHeap;

void initMaxHeap(MaxHeap *heap) {
    heap->data = (int *)malloc(MAX_SIZE * sizeof(int));
    heap->size = 0;
}

void initMinHeap(MinHeap *heap) {
    heap->data = (int *)malloc(MAX_SIZE * sizeof(int));
    heap->size = 0;
}

void maxHeapInsert(MaxHeap *heap, int value) {
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

void minHeapInsert(MinHeap *heap, int value) {
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

int maxHeapExtractMax(MaxHeap *heap) {
    if (heap->size == 0) return -1; // Error: heap is empty
    int max = heap->data[0];
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
    return max;
}

int minHeapExtractMin(MinHeap *heap) {
    if (heap->size == 0) return -1; // Error: heap is empty
    int min = heap->data[0];
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
    return min;
}

int main() {
    int t;
    scanf("%d", &t);
    
    MaxHeap pqmax;
    MinHeap pqmin;
    initMaxHeap(&pqmax);
    initMinHeap(&pqmin);
    
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    while (t-- > 0) {
        char command[10];
        scanf("%s", command);
        
        if (command[0] == '2') {
            long long ans = min;
            ans *= pqmin.size;
            ans -= sumMin;
            long long ans1 = min;
            ans1 = sumMax - ans1;
            printf("%d %lld\n", min, ans + ans1 + sumb);
        } else {
            int in;
            long long current;
            scanf("%d %lld", &in, &current);
            sumb += current;

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
            } else if (pqmin.size < pqmax.size) {
                sumMax -= pqmax.data[0];
                sumMin += pqmax.data[0];
                minHeapInsert(&pqmin, maxHeapExtractMax(&pqmax));
            }

            if (pqmin.size > 0) {
                min = pqmin.data[0];
            }
        }
    }

    free(pqmax.data);
    free(pqmin.data);
    return 0;
}

// <END-OF-CODE>
