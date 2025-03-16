#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    int *data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (int*)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int index) {
    while (index > 0 && pq->data[index] > pq->data[(index - 1) / 2]) {
        swap(&pq->data[index], &pq->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(PriorityQueue* pq, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->data[left] > pq->data[largest]) {
        largest = left;
    }

    if (right < pq->size && pq->data[right] > pq->data[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&pq->data[index], &pq->data[largest]);
        heapifyDown(pq, largest);
    }
}

void push(PriorityQueue* pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (int*)realloc(pq->data, pq->capacity * sizeof(int));
    }
    pq->data[pq->size] = value;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

int pop(PriorityQueue* pq) {
    if (pq->size == 0) {
        return -1; // or some error code
    }
    int root = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return root;
}

int peek(PriorityQueue* pq) {
    if (pq->size == 0) {
        return -1; // or some error code
    }
    return pq->data[0];
}

int main() {
    int t;
    scanf("%d", &t);
    getchar(); // consume newline

    PriorityQueue* pqmax = createPriorityQueue(10);
    PriorityQueue* pqmin = createPriorityQueue(10);
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    char line[MAX_LINE_LENGTH];
    while (t-- > 0) {
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strcspn(line, "\n")] = 0; // remove newline

        char* s[3];
        int i = 0;
        char* token = strtok(line, " ");
        while (token != NULL) {
            s[i++] = token;
            token = strtok(NULL, " ");
        }

        if (s[0][0] == '2') {
            long long ans = min;
            ans *= pqmin->size;
            ans -= sumMin;
            long long ans1 = min;
            ans1 = sumMax - ans1;
            printf("%d %lld\n", min, ans + ans1 + sumb);
        } else {
            int in = atoi(s[1]);
            sumb += atoll(s[2]);

            if (in > min) {
                push(pqmax, in);
                sumMax += in;
            } else {
                push(pqmin, in);
                sumMin += in;
            }

            if (pqmin->size > pqmax->size) {
                sumMax += peek(pqmin);
                sumMin -= peek(pqmin);
                push(pqmax, pop(pqmin));
            } else if (pqmin->size < pqmax->size) {
                sumMax -= peek(pqmax);
                sumMin += peek(pqmax);
                push(pqmin, pop(pqmax));
            }

            min = peek(pqmin);
        }
    }

    free(pqmax->data);
    free(pqmin->data);
    free(pqmax);
    free(pqmin);

    return 0;
}
