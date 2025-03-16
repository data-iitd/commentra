
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
};

struct Queue *createQueue(int size) {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

bool isEmpty(struct Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

bool isFull(struct Queue *q) {
    return (q->rear == q->size - 1);
}

void enqueue(struct Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = val;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return val;
}

int main() {
    struct Queue *q1 = createQueue(100000);
    struct Queue *q2 = createQueue(100000);
    int n, m, i, x, val, val2;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q1, x);
        enqueue(q2, i + 1);
    }
    int ans = 0;
    while (!isEmpty(q1)) {
        if (q1->arr[q1->front] <= m) {
            dequeue(q1);
            ans = dequeue(q2);
        } else if (q1->arr[q1->front] > m) {
            x = dequeue(q1);
            val = x - m;
            enqueue(q1, val);
            val2 = dequeue(q2);
            enqueue(q2, val2);
        }
    }
    printf("%d\n", ans);
    return 0;
}

