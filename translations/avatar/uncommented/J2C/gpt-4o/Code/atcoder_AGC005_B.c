#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} ArrayDeque;

ArrayDeque* createDeque(int capacity) {
    ArrayDeque *deque = (ArrayDeque *)malloc(sizeof(ArrayDeque));
    deque->capacity = capacity;
    deque->front = -1;
    deque->rear = -1;
    deque->data = (int *)malloc(capacity * sizeof(int));
    return deque;
}

int isEmpty(ArrayDeque *deque) {
    return deque->front == -1;
}

void push(ArrayDeque *deque, int value) {
    if (deque->rear == deque->capacity - 1) {
        return; // Deque is full
    }
    if (isEmpty(deque)) {
        deque->front = 0;
    }
    deque->data[++deque->rear] = value;
}

int poll(ArrayDeque *deque) {
    if (isEmpty(deque)) {
        return -1; // Deque is empty
    }
    int value = deque->data[deque->front++];
    if (deque->front > deque->rear) {
        deque->front = deque->rear = -1; // Reset deque
    }
    return value;
}

int peek(ArrayDeque *deque) {
    if (isEmpty(deque)) {
        return -1; // Deque is empty
    }
    return deque->data[deque->front];
}

void freeDeque(ArrayDeque *deque) {
    free(deque->data);
    free(deque);
}

int main() {
    int N;
    scanf("%d", &N);
    int *a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    int *leftl = (int *)malloc(N * sizeof(int));
    int *rightl = (int *)malloc(N * sizeof(int));
    ArrayDeque *que = createDeque(N);
    int index = 0;

    while (index < N) {
        while (!isEmpty(que) && a[peek(que)] > a[index]) {
            int ind = poll(que);
            rightl[ind] = index - ind - 1;
        }
        push(que, index++);
    }
    while (!isEmpty(que)) {
        int ind = poll(que);
        rightl[ind] = N - ind - 1;
    }

    index = N - 1;
    while (index >= 0) {
        while (!isEmpty(que) && a[peek(que)] > a[index]) {
            int ind = poll(que);
            leftl[ind] = ind - index - 1;
        }
        push(que, index--);
    }
    while (!isEmpty(que)) {
        int ind = poll(que);
        leftl[ind] = ind - index - 1;
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    printf("%lld\n", ans);

    free(a);
    free(leftl);
    free(rightl);
    freeDeque(que);
    return 0;
}

// <END-OF-CODE>
