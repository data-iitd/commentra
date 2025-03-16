#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int duration;
    int index;
} Task;

typedef struct {
    Task *tasks;
    int size;
    int front;
    int rear;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->tasks = (Task *)malloc(capacity * sizeof(Task));
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, Task task) {
    q->rear = (q->rear + 1) % capacity;
    q->tasks[q->rear] = task;
    q->size++;
}

Task dequeue(Queue *q) {
    Task task = q->tasks[q->front];
    q->front = (q->front + 1) % capacity;
    q->size--;
    return task;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    Task tasks[n];
    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        tasks[i] = (Task){time, duration, i};
    }

    Queue remaining;
    initQueue(&remaining, b);
    int finish_time = 0;
    int result[n];

    for (int i = 0; i < n; i++) {
        Task task = tasks[i];
        if (task.time > finish_time && isEmpty(&remaining)) {
            finish_time = task.time + task.duration;
            result[task.index] = finish_time;
        } else {
            if (task.time >= finish_time) {
                if (!isEmpty(&remaining)) {
                    finish_time = dequeue(&remaining).time + dequeue(&remaining).duration;
                }
            }
            if (remaining.size < b) {
                enqueue(&remaining, task);
            } else {
                result[task.index] = -1;
            }
        }
    }

    while (!isEmpty(&remaining)) {
        finish_time = dequeue(&remaining).time + dequeue(&remaining).duration;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
