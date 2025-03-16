#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100000

typedef struct {
    int day;
    int salary;
} Employee;

typedef struct {
    Employee data[MAX_EMPLOYEES];
    int size;
} MinHeap;

void swap(Employee *a, Employee *b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    while (index > 0 && heap->data[index].day < heap->data[(index - 1) / 2].day) {
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left].day < heap->data[smallest].day) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right].day < heap->data[smallest].day) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insertHeap(MinHeap *heap, Employee emp) {
    if (heap->size == MAX_EMPLOYEES) {
        printf("Heap is full\n");
        return;
    }
    heap->data[heap->size] = emp;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

Employee extractMin(MinHeap *heap) {
    if (heap->size == 0) {
        Employee empty = {0, 0};
        return empty;
    }
    Employee root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    MinHeap x = {{0}, 0};
    MinHeap y = {{0}, 0};

    for (int i = 0; i < n; i++) {
        Employee emp;
        scanf("%d %d", &emp.day, &emp.salary);
        emp.day = -emp.day;
        emp.salary = -emp.salary;
        insertHeap(&x, emp);
    }

    while (x.size > 0) {
        Employee emp = extractMin(&x);
        int r = m - y.size;
        if (r >= -emp.day) {
            emp.salary = -emp.salary;
            insertHeap(&y, emp);
        } else {
            emp.salary = -emp.salary;
            insertHeap(&y, emp);
            extractMin(&y);
        }
    }

    int sum = 0;
    for (int i = 0; i < y.size; i++) {
        sum += y.data[i].salary;
    }

    printf("%d\n", sum);

    return 0;
}
