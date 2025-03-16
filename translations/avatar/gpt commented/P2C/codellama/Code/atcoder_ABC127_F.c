#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_HEAP_SIZE 100000

// Structure for a node in the heap
typedef struct {
    int value;
    int index;
} node;

// Structure for a heap
typedef struct {
    node* nodes;
    int size;
    int capacity;
} heap;

// Function to create a new heap
heap* create_heap(int capacity) {
    heap* h = (heap*)malloc(sizeof(heap));
    h->capacity = capacity;
    h->size = 0;
    h->nodes = (node*)malloc(h->capacity * sizeof(node));
    return h;
}

// Function to swap two nodes
void swap(node* a, node* b) {
    node temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the heap
void heapify(heap* h, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < h->size && h->nodes[l].value > h->nodes[largest].value)
        largest = l;

    if (r < h->size && h->nodes[r].value > h->nodes[largest].value)
        largest = r;

    if (largest != i) {
        swap(&h->nodes[i], &h->nodes[largest]);
        heapify(h, largest);
    }
}

// Function to insert a new node into the heap
void insert(heap* h, int value, int index) {
    if (h->size >= h->capacity) {
        printf("Heap is full");
        return;
    }

    node n;
    n.value = value;
    n.index = index;

    h->nodes[h->size] = n;
    int i = h->size;
    h->size++;

    while (i > 0 && h->nodes[i].value > h->nodes[(i - 1) / 2].value) {
        swap(&h->nodes[i], &h->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove the root node from the heap
node remove(heap* h) {
    if (h->size <= 0) {
        printf("Heap is empty");
        node n;
        return n;
    }

    if (h->size == 1) {
        h->size--;
        return h->nodes[0];
    }

    node root = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    heapify(h, 0);

    return root;
}

// Function to print the heap
void print_heap(heap* h) {
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->nodes[i].value);
    printf("\n");
}

// Function to free the heap
void free_heap(heap* h) {
    free(h->nodes);
    free(h);
}

// Function to perform a query
void perform_query(heap* p1, heap* p2, int* sum_p1, int* sum_p2, int* sum_b, int ql[3]) {
    if (ql[0] == 2) {
        if (p1->size == p2->size) {
            printf("%d %d\n", -p2->nodes[0].value, *sum_p1 - p1->size * -p2->nodes[0].value + p2->size * -p2->nodes[0].value - *sum_p2 + *sum_b);
        } else {
            printf("%d %d\n", p1->nodes[0].value, *sum_p1 - p1->size * p1->nodes[0].value + p2->size * p1->nodes[0].value - *sum_p2 + *sum_b);
        }
    } else {
        *sum_b += ql[2];

        if (p1->size == 0) {
            insert(p1, ql[1], ql[1]);
            *sum_p1 += ql[1];
        } else if (p1->nodes[0].value <= ql[1]) {
            insert(p1, ql[1], ql[1]);
            *sum_p1 += ql[1];
        } else {
            insert(p2, -ql[1], ql[1]);
            *sum_p2 += ql[1];
        }

        if (p1->size < p2->size) {
            node k = remove(p2);
            insert(p1, -k.value, k.value);
            *sum_p2 -= k.value;
            *sum_p1 += k.value;
        } else if (p1->size - 1 > p2->size) {
            node k = remove(p1);
            insert(p2, -k.value, k.value);
            *sum_p1 -= k.value;
            *sum_p2 += k.value;
        }
    }
}

int main() {
    int q;
    scanf("%d", &q);

    heap* p1 = create_heap(MAX_HEAP_SIZE);
    heap* p2 = create_heap(MAX_HEAP_SIZE);
    int sum_p1 = 0;
    int sum_p2 = 0;
    int sum_b = 0;

    for (int i = 0; i < q; i++) {
        int ql[3];
        scanf("%d %d %d", &ql[0], &ql[1], &ql[2]);
        perform_query(p1, p2, &sum_p1, &sum_p2, &sum_b, ql);
    }

    free_heap(p1);
    free_heap(p2);

    return 0;
}

