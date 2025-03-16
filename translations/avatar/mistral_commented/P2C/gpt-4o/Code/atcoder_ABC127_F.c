#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Function to implement a min-heap
void minHeapify(int heap[], int size, int i) {
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
        minHeapify(heap, size, smallest);
    }
}

// Function to insert into min-heap
void insertMinHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    for (int i = (*size - 1) / 2; i >= 0; i--) {
        minHeapify(heap, *size, i);
    }
}

// Function to extract the minimum from min-heap
int extractMin(int heap[], int *size) {
    if (*size <= 0) return -1; // Heap is empty
    if (*size == 1) {
        (*size)--;
        return heap[0];
    }
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return root;
}

int main() {
    int q;
    scanf("%d", &q);
    
    int p1[MAX_SIZE], p2[MAX_SIZE];
    int size_p1 = 0, size_p2 = 0;
    long long sum_b = 0, sum_p1 = 0, sum_p2 = 0;

    for (int i = 0; i < q; i++) {
        int query[3];
        scanf("%d", &query[0]);
        
        if (query[0] == 2) {
            if (size_p1 == size_p2) {
                printf("%d %lld\n", -p2[0], sum_p1 - size_p1 * -p2[0] + size_p2 * -p2[0] - sum_p2 + sum_b);
            } else {
                printf("%d %lld\n", p1[0], sum_p1 - size_p1 * p1[0] + size_p2 * p1[0] - sum_p2 + sum_b);
            }
        } else {
            scanf("%d %d", &query[1], &query[2]);
            sum_b += query[2];

            if (size_p1 == 0) {
                insertMinHeap(p1, &size_p1, query[1]);
                sum_p1 += query[1];
            } else if (p1[0] <= query[1]) {
                insertMinHeap(p1, &size_p1, query[1]);
                sum_p1 += query[1];
            } else {
                insertMinHeap(p2, &size_p2, -query[1]);
                sum_p2 += query[1];
                sum_p1 -= query[1];
                sum_p2 -= query[1];
            }

            if (size_p1 < size_p2) {
                int k = extractMin(p2, &size_p2);
                insertMinHeap(p1, &size_p1, -k);
                sum_p2 += k;
                sum_p1 -= k;
            }

            if (size_p1 - 1 > size_p2) {
                int k = extractMin(p1, &size_p1);
                insertMinHeap(p2, &size_p2, -k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
