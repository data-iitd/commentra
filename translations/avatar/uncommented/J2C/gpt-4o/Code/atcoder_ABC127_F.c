#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} PriorityQueue;

void initQueue(PriorityQueue *pq, int capacity) {
    pq->data = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
}

void freeQueue(PriorityQueue *pq) {
    free(pq->data);
}

void pushMax(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (int *)realloc(pq->data, pq->capacity * sizeof(int));
    }
    pq->data[pq->size++] = value;
    for (int i = pq->size - 1; i > 0; i--) {
        if (pq->data[i] > pq->data[(i - 1) / 2]) {
            int temp = pq->data[i];
            pq->data[i] = pq->data[(i - 1) / 2];
            pq->data[(i - 1) / 2] = temp;
        } else {
            break;
        }
    }
}

int popMax(PriorityQueue *pq) {
    int max = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    for (int i = 0; i < pq->size;) {
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
            int temp = pq->data[i];
            pq->data[i] = pq->data[largest];
            pq->data[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
    return max;
}

void pushMin(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (int *)realloc(pq->data, pq->capacity * sizeof(int));
    }
    pq->data[pq->size++] = value;
    for (int i = pq->size - 1; i > 0; i--) {
        if (pq->data[i] < pq->data[(i - 1) / 2]) {
            int temp = pq->data[i];
            pq->data[i] = pq->data[(i - 1) / 2];
            pq->data[(i - 1) / 2] = temp;
        } else {
            break;
        }
    }
}

int popMin(PriorityQueue *pq) {
    int min = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    for (int i = 0; i < pq->size;) {
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
            int temp = pq->data[i];
            pq->data[i] = pq->data[smallest];
            pq->data[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return min;
}

int main() {
    int t;
    scanf("%d", &t);
    
    PriorityQueue pqmax, pqmin;
    initQueue(&pqmax, 10);
    initQueue(&pqmin, 10);
    
    long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    while (t--) {
        int type;
        scanf("%d", &type);
        if (type == 2) {
            long ans = min * pqmin.size - sumMin;
            long ans1 = min * pqmax.size;
            ans1 = sumMax - ans1;
            printf("%d %ld\n", min, ans + ans1 + sumb);
        } else {
            int in;
            long value;
            scanf("%d %ld", &in, &value);
            sumb += value;
            if (in > min) {
                pushMax(&pqmax, in);
                sumMax += in;
            } else {
                pushMin(&pqmin, in);
                sumMin += in;
            }
            if (pqmin.size > pqmax.size) {
                sumMax += pqmin.data[0];
                sumMin -= pqmin.data[0];
                pushMax(&pqmax, popMin(&pqmin));
            }
            if (pqmin.size < pqmax.size) {
                sumMax -= pqmax.data[0];
                sumMin += pqmax.data[0];
                pushMin(&pqmin, popMax(&pqmax));
            }
            min = pqmin.data[0];
        }
    }

    freeQueue(&pqmax);
    freeQueue(&pqmin);
    return 0;
}

// <END-OF-CODE>
