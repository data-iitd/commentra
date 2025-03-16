#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100000

int p1[MAX_HEAP_SIZE];
int p2[MAX_HEAP_SIZE];
int p1_size = 0;
int p2_size = 0;
long long sum_b = 0;
long long sum_p1 = 0;
long long sum_p2 = 0;

void heapify(int *heap, int size) {
    int i;
    for (i = size / 2 - 1; i >= 0; i--) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
        }
    }
}

void push(int *heap, int *size, long long *sum, int value) {
    heap[*size] = value;
    *size += 1;
    heapify(heap, *size);
    *sum += value;
}

int pop(int *heap, int *size, long long *sum) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    *size -= 1;
    heapify(heap, *size);
    *sum -= root;
    return root;
}

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int ql[3];
        scanf("%d %d %d", &ql[0], &ql[1], &ql[2]);
        if (ql[0] == 2) {
            if (p1_size == p2_size) {
                printf("%d %lld\n", -p2[0], sum_p1 - p1_size * -p2[0] + p2_size * -p2[0] - sum_p2 + sum_b);
            } else {
                printf("%d %lld\n", p1[0], sum_p1 - p1_size * p1[0] + p2_size * p1[0] - sum_p2 + sum_b);
            }
        } else {
            sum_b += ql[2];
            if (p1_size == 0) {
                push(p1, &p1_size, &sum_p1, ql[1]);
            } else if (p1[0] <= ql[1]) {
                push(p1, &p1_size, &sum_p1, ql[1]);
            } else {
                push(p2, &p2_size, &sum_p2, ql[1]);
            }
            if (p1_size < p2_size) {
                int k = pop(p2, &p2_size, &sum_p2);
                push(p1, &p1_size, &sum_p1, -k);
                sum_p2 += k;
                sum_p1 -= k;
            }
            if (p1_size - 1 > p2_size) {
                int k = pop(p1, &p1_size, &sum_p1);
                push(p2, &p2_size, &sum_p2, -k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }
    return 0;
}
