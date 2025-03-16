#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
    int day;
    int salary;
} Job;

typedef struct {
    Job data[MAX_N];
    int size;
} MaxHeap;

void swap(Job *a, Job *b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MaxHeap *heap, int index) {
    while (index > 0 && heap->data[index].day > heap->data[(index - 1) / 2].day) {
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left].day > heap->data[largest].day) {
        largest = left;
    }
    if (right < heap->size && heap->data[right].day > heap->data[largest].day) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapifyDown(heap, largest);
    }
}

void insertJob(MaxHeap *heap, Job job) {
    heap->data[heap->size] = job;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

Job extractMax(MaxHeap *heap) {
    Job maxJob = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return maxJob;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    MaxHeap x = { .size = 0 };
    MaxHeap y = { .size = 0 };

    for (int i = 0; i < n; i++) {
        Job job;
        scanf("%d %d", &job.day, &job.salary);
        insertJob(&x, job);
    }

    while (x.size > 0) {
        Job job = extractMax(&x);
        int r = m - y.size;

        if (r >= job.day) {
            insertJob(&y, job);
        } else {
            insertJob(&y, job);
            extractMax(&y);
        }
    }

    int sum = 0;
    for (int i = 0; i < y.size; i++) {
        sum += y.data[i].salary;
    }

    printf("%d\n", sum);

    return 0;
}
