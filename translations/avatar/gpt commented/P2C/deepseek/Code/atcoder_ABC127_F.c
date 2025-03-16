#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100000

int p1[MAX_HEAP_SIZE];
int p2[MAX_HEAP_SIZE];
int p1_size = 0;
int p2_size = 0;
long long sum_p1 = 0;
long long sum_p2 = 0;
long long sum_b = 0;

void heapify(int *heap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        int parent = i;
        while (2 * parent + 1 < size) {
            int child = 2 * parent + 1;
            if (child + 1 < size && heap[child] > heap[child + 1]) {
                child++;
            }
            if (heap[parent] > heap[child]) {
                int temp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = temp;
                parent = child;
            } else {
                break;
            }
        }
    }
}

void push(int *heap, int *size, long long *sum, int value) {
    heap[*size] = value;
    (*size)++;
    heapify(heap, *size);
    *sum += value;
}

int pop(int *heap, int *size, long long *sum) {
    int value = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size);
    *sum -= value;
    return value;
}

int main() {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int query[3];
        scanf("%d %d %d", &query[0], &query[1], &query[2]);

        if (query[0] == 2) {
            if (p1_size == p2_size) {
                printf("%d %lld\n", -p2[0], sum_p1 - p1_size * -p2[0] + p2_size * -p2[0] - sum_p2 + sum_b);
            } else {
                printf("%d %lld\n", p1[0], sum_p1 - p1_size * p1[0] + p2_size * p1[0] - sum_p2 + sum_b);
            }
        } else {
            sum_b += query[2];

            if (p1_size == 0) {
                push(p1, &p1_size, &sum_p1, query[1]);
            } else if (p1[0] <= query[1]) {
                push(p1, &p1_size, &sum_p1, query[1]);
            } else {
                push(p2, &p2_size, &sum_p2, query[1]);
            }

            if (p1_size < p2_size) {
                int temp = pop(p2, &p2_size, &sum_p2);
                push(p1, &p1_size, &sum_p1, -temp);
                sum_p2 += temp;
                sum_p1 -= temp;
            }

            if (p1_size - 1 > p2_size) {
                int temp = pop(p1, &p1_size, &sum_p1);
                push(p2, &p2_size, &sum_p2, -temp);
                sum_p1 -= temp;
                sum_p2 += temp;
            }
        }
    }

    return 0;
}
