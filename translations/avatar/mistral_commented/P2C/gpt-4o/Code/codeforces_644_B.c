#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int time;
    int duration;
    int index;
} Task;

typedef struct {
    Task *tasks;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->tasks = (Task *)malloc(capacity * sizeof(Task));
    return queue;
}

bool isFull(Queue *queue) {
    return (queue->rear == queue->capacity);
}

bool isEmpty(Queue *queue) {
    return (queue->front == queue->rear);
}

void enqueue(Queue *queue, Task task) {
    if (!isFull(queue)) {
        queue->tasks[queue->rear++] = task;
    }
}

Task dequeue(Queue *queue) {
    return queue->tasks[queue->front++];
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    Queue *remaining = createQueue(b);
    int finish_time = 0;
    int *result = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        Task task = {time, duration, i};
        result[i] = 0;

        if (time > finish_time && isEmpty(remaining)) {
            finish_time = time + duration;
            result[i] = finish_time;
        } else if (time >= finish_time && !isEmpty(remaining)) {
            Task task_to_run = dequeue(remaining);
            finish_time = (finish_time > task_to_run.time ? finish_time : task_to_run.time) + task_to_run.duration;
            result[task_to_run.index] = finish_time;

            if (!isFull(remaining)) {
                enqueue(remaining, task);
            } else {
                result[i] = -1;
            }
        } else {
            if (!isFull(remaining)) {
                enqueue(remaining, task);
            } else {
                result[i] = -1;
            }
        }
    }

    while (!isEmpty(remaining)) {
        Task task_to_run = dequeue(remaining);
        finish_time = (finish_time > task_to_run.time ? finish_time : task_to_run.time) + task_to_run.duration;
        result[task_to_run.index] = finish_time;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    free(remaining->tasks);
    free(remaining);
    free(result);
    return 0;
}

// <END-OF-CODE>
