#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int duration;
    int index;
} Task;

typedef struct Node {
    Task task;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue* q, Task task) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = task;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

Task dequeue(Queue* q) {
    if (q->front == NULL) {
        Task emptyTask = {0, 0, -1};
        return emptyTask;
    }
    Node* temp = q->front;
    Task task = temp->task;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return task;
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
    initQueue(&remaining);

    int finish_time = 0;
    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }

    int running = 0;

    for (int i = 0; i < n; i++) {
        enqueue(&remaining, tasks[i]);
    }

    while (remaining.size > 0) {
        Task task_to_run = dequeue(&remaining);
        if (task_to_run.index == -1) {
            break;
        }
        finish_time = (finish_time > task_to_run.time) ? finish_time + task_to_run.duration : task_to_run.time + task_to_run.duration;
        result[task_to_run.index] = finish_time;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
