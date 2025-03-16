
#include <stdio.h>
#include <stdlib.h>

// Define a Task struct to store the time, duration, and index of each task
typedef struct Task {
    int time;
    int duration;
    int index;
} Task;

// Define a Queue struct to store the tasks to be executed
typedef struct Queue {
    Task* data;
    int front;
    int rear;
    int size;
} Queue;

// Function to initialize a new Queue
Queue* initQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Task*)malloc(sizeof(Task) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to check if the Queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to check if the Queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

// Function to enqueue a new task into the Queue
void enqueue(Queue* queue, Task task) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->data[queue->rear] = task;
}

// Function to dequeue a task from the Queue
Task dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        Task emptyTask = {0, 0, 0};
        return emptyTask;
    }
    Task task = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    return task;
}

// Function to execute the next task in the Queue and update the finish time and result accordingly
void runTask(Queue* remaining, int* finishTime, int* result) {
    Task task = dequeue(remaining);
    *finishTime = *finishTime > task.time? *finishTime : task.time;
    *finishTime += task.duration;
    result[task.index] = *finishTime;
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    Queue* remaining = initQueue(n);
    int finishTime = 0;
    int result[n];
    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        Task task = {time, duration, i};
        result[i] = 0;
        if (time > finishTime && isEmpty(remaining)) {
            finishTime = time + duration;
            result[i] = finishTime;
        } else if (time >= finishTime &&!isEmpty(remaining)) {
            runTask(remaining, &finishTime, result);
            if (remaining->rear - remaining->front + 1 < b) {
                enqueue(remaining, task);
            } else {
                result[i] = -1;
            }
        }
    }
    while (!isEmpty(remaining)) {
        runTask(remaining, &finishTime, result);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}
