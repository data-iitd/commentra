#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
    int day;
    int salary;
} Job;

typedef struct {
    int value;
} Salary;

void push(Job* heap, int* size, int day, int salary) {
    heap[*size].day = day;
    heap[*size].salary = salary;
    int i = *size;
    while (i > 0 && heap[(i - 1) / 2].day < heap[i].day) {
        Job temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    (*size)++;
}

Job pop(Job* heap, int* size) {
    Job root = heap[0];
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
        Job temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }
    return root;
}

void pushSalary(Salary* heap, int* size, int value) {
    heap[*size].value = value;
    int i = *size;
    while (i > 0 && heap[(i - 1) / 2].value < heap[i].value) {
        Salary temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    (*size)++;
}

Salary popSalary(Salary* heap, int* size) {
    Salary root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    int i = 0;
    while (2 * i + 1 < *size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = left;
        if (right < *size && heap[right].value > heap[left].value) {
            largest = right;
        }
        if (heap[i].value > heap[largest].value) {
            break;
        }
        Salary temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }
    return root;
}

int main() {
    int n, m;
    Job x[MAX_N];
    Salary y[MAX_M];
    int xSize = 0;
    int ySize = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        int day, salary;
        scanf("%d %d", &day, &salary);
        push(x, &xSize, day, salary);
    }

    while (xSize > 0) {
        Job job = pop(x, &xSize);
        int r = m - ySize;
        if (r >= job.day) {
            pushSalary(y, &ySize, job.salary);
        } else {
            pushSalary(y, &ySize, job.salary);
            popSalary(y, &ySize);
        }
    }

    int totalSalary = 0;
    for (int i = 0; i < ySize; i++) {
        totalSalary += y[i].value;
    }

    printf("%d\n", totalSalary);

    return 0;
}
