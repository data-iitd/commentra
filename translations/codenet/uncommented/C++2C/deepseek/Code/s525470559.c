#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int time;
} Task;

typedef struct Node {
    Task task;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Task t) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = t;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Task dequeue(Queue* q) {
    if (isEmpty(q)) {
        Task emptyTask = {"", 0};
        return emptyTask;
    }
    Node* temp = q->front;
    Task t = temp->task;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return t;
}

int main() {
    int n, q, elaps = 0;
    Queue Q;
    initQueue(&Q);

    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        Task tmp;
        scanf("%s %d", tmp.name, &tmp.time);
        enqueue(&Q, tmp);
    }

    while (!isEmpty(&Q)) {
        Task p = dequeue(&Q);
        if (p.time <= q) {
            elaps += p.time;
            printf("%s %d\n", p.name, elaps);
        } else {
            p.time -= q;
            elaps += q;
            enqueue(&Q, p);
        }
    }
    return 0;
}
