#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Structure for a priority queue (min-heap and max-heap)
typedef struct {
    int *data;
    int size;
    int capacity;
} PriorityQueue;

// Function to create a priority queue
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->data = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

// Function to swap two elements in the priority queue
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert an element into the min-heap
void insertMinHeap(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) return;
    pq->data[pq->size] = value;
    int i = pq->size;
    pq->size++;
    while (i != 0 && pq->data[(i - 1) / 2] > pq->data[i]) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to insert an element into the max-heap
void insertMaxHeap(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) return;
    pq->data[pq->size] = value;
    int i = pq->size;
    pq->size++;
    while (i != 0 && pq->data[(i - 1) / 2] < pq->data[i]) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element from the min-heap
int extractMin(PriorityQueue *pq) {
    if (pq->size <= 0) return -1; // Error value
    if (pq->size == 1) {
        pq->size--;
        return pq->data[0];
    }
    int root = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    // Heapify down
    int i = 0;
    while (i < pq->size / 2) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < pq->size && pq->data[left] < pq->data[smallest]) {
            smallest = left;
        }
        if (right < pq->size && pq->data[right] < pq->data[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(&pq->data[i], &pq->data[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    return root;
}

// Function to extract the maximum element from the max-heap
int extractMax(PriorityQueue *pq) {
    if (pq->size <= 0) return -1; // Error value
    if (pq->size == 1) {
        pq->size--;
        return pq->data[0];
    }
    int root = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    // Heapify down
    int i = 0;
    while (i < pq->size / 2) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < pq->size && pq->data[left] > pq->data[largest]) {
            largest = left;
        }
        if (right < pq->size && pq->data[right] > pq->data[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(&pq->data[i], &pq->data[largest]);
            i = largest;
        } else {
            break;
        }
    }
    return root;
}

int main() {
    int t;
    scanf("%d", &t);
    
    PriorityQueue *pqmin = createPriorityQueue(MAX_SIZE);
    PriorityQueue *pqmax = createPriorityQueue(MAX_SIZE);
    
    long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    while (t-- > 0) {
        int command;
        scanf("%d", &command);
        
        if (command == 2) {
            long ans = min * pqmin->size - sumMin;
            long ans1 = sumMax - min * pqmax->size;
            printf("%d %ld\n", min, ans + ans1 + sumb);
        } else {
            int in;
            long value;
            scanf("%d %ld", &in, &value);
            sumb += value;

            if (in > min) {
                insertMaxHeap(pqmax, in);
                sumMax += in;
            } else {
                insertMinHeap(pqmin, in);
                sumMin += in;
            }

            // Balance the heaps
            if (pqmin->size > pqmax->size) {
                sumMax += pqmin->data[0];
                sumMin -= pqmin->data[0];
                insertMaxHeap(pqmax, extractMin(pqmin));
            }
            if (pqmin->size < pqmax->size) {
                sumMax -= pqmax->data[0];
                sumMin += pqmax->data[0];
                insertMinHeap(pqmin, extractMax(pqmax));
            }

            // Update the minimum value
            if (pqmin->size > 0) {
                min = pqmin->data[0];
            }
        }
    }

    // Free allocated memory
    free(pqmin->data);
    free(pqmin);
    free(pqmax->data);
    free(pqmax);

    return 0;
}

// <END-OF-CODE>
