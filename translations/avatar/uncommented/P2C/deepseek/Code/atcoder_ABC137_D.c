#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int salary;
} Job;

typedef struct {
    int day;
    int salary;
} JobHeap;

void push(JobHeap** heap, int* size, int day, int salary) {
    (*heap)[*size].day = day;
    (*heap)[*size].salary = salary;
    int i = *size;
    while (i > 0 && (*heap)[(i - 1) / 2].day < (*heap)[i].day) {
        JobHeap temp = (*heap)[(i - 1) / 2];
        (*heap)[(i - 1) / 2] = (*heap)[i];
        (*heap)[i] = temp;
        i = (i - 1) / 2;
    }
    (*size)++;
}

JobHeap pop(JobHeap* heap, int* size) {
    JobHeap result = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    int i = 0;
    while (2 * i + 1 < *size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = left;
        if (right < *size && heap[right].day > heap[left].day) {
            largest = right;
        }
        if (heap[i].day > heap[largest].day) {
            break;
        }
        JobHeap temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Job* x = (Job*)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i].day, &x[i].salary);
    }

    JobHeap* y = (JobHeap*)malloc(n * sizeof(JobHeap));
    int y_size = 0;

    for (int i = 0; i < n; i++) {
        int r = m - y_size;
        if (r >= x[i].day) {
            push(&y, &y_size, x[i].day, x[i].salary);
        } else if (y_size > 0) {
            JobHeap temp = pop(y, &y_size);
            if (temp.salary < x[i].salary) {
                push(&y, &y_size, temp.day, temp.salary);
            } else {
                push(&y, &y_size, x[i].day, x[i].salary);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < y_size; i++) {
        sum += y[i].salary;
    }
    printf("%d\n", sum);

    free(x);
    free(y);
    return 0;
}
