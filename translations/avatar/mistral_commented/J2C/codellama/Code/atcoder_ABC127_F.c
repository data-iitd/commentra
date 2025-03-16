
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->arr[left] < minHeap->arr[smallest]) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->arr[right] < minHeap->arr[smallest]) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&minHeap->arr[smallest], &minHeap->arr[idx]);
        minHeapify(minHeap, smallest);
    }
}

void maxHeapify(MaxHeap *maxHeap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < maxHeap->size && maxHeap->arr[left] > maxHeap->arr[largest]) {
        largest = left;
    }

    if (right < maxHeap->size && maxHeap->arr[right] > maxHeap->arr[largest]) {
        largest = right;
    }

    if (largest != idx) {
        swap(&maxHeap->arr[largest], &maxHeap->arr[idx]);
        maxHeapify(maxHeap, largest);
    }
}

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->arr = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;

    return minHeap;
}

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *maxHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
    maxHeap->arr = (int *)malloc(capacity * sizeof(int));
    maxHeap->size = 0;
    maxHeap->capacity = capacity;

    return maxHeap;
}

void insertMinHeap(MinHeap *minHeap, int element) {
    if (minHeap->size == minHeap->capacity) {
        return;
    }

    int idx = minHeap->size;
    minHeap->arr[idx] = element;
    minHeap->size++;

    while (idx > 0 && minHeap->arr[idx] < minHeap->arr[(idx - 1) / 2]) {
        swap(&minHeap->arr[idx], &minHeap->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void insertMaxHeap(MaxHeap *maxHeap, int element) {
    if (maxHeap->size == maxHeap->capacity) {
        return;
    }

    int idx = maxHeap->size;
    maxHeap->arr[idx] = element;
    maxHeap->size++;

    while (idx > 0 && maxHeap->arr[idx] > maxHeap->arr[(idx - 1) / 2]) {
        swap(&maxHeap->arr[idx], &maxHeap->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

int extractMin(MinHeap *minHeap) {
    if (minHeap->size <= 0) {
        return -1;
    }

    int element = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return element;
}

int extractMax(MaxHeap *maxHeap) {
    if (maxHeap->size <= 0) {
        return -1;
    }

    int element = maxHeap->arr[0];
    maxHeap->arr[0] = maxHeap->arr[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);

    return element;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        MinHeap *minHeap = createMinHeap(n);
        MaxHeap *maxHeap = createMaxHeap(n);

        long long sumMin = 0, sumMax = 0, sumb = 0;
        int min = 0;

        while (n--) {
            char op[2];
            scanf("%s", op);

            if (op[0] == '2') {
                long long ans = min;
                ans *= minHeap->size;
                ans -= sumMin;
                long long ans1 = min;
                ans1 = sumMax - ans1;
                printf("%lld %lld\n", min, ans + ans1 + sumb);
            } else {
                int in;
                long long b;
                scanf("%d %lld", &in, &b);
                sumb += b;

                if (in > min) {
                    insertMaxHeap(maxHeap, in);
                    sumMax += in;
                } else {
                    insertMinHeap(minHeap, in);
                    sumMin += in;
                }

                if (minHeap->size > maxHeap->size) {
                    sumMax += minHeap->arr[0];
                    sumMin -= minHeap->arr[0];
                    insertMaxHeap(maxHeap, extractMin(minHeap));
                } else if (minHeap->size < maxHeap->size) {
                    sumMax -= maxHeap->arr[0];
                    sumMin += maxHeap->arr[0];
                    insertMinHeap(minHeap, extractMax(maxHeap));
                }

                min = minHeap->arr[0];
            }
        }
    }

    return 0;
}

