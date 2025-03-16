#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Queue* q1 = createQueue();
    Queue* q2 = createQueue();
    
    for (int i = 1; i <= n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(q1, value);
        enqueue(q2, i);
    }
    
    int ans = 0;
    while (!isEmpty(q1)) {
        if (q1->front->data <= m) {
            ans = dequeue(q2);
            dequeue(q1);
        } else {
            int x = dequeue(q1);
            int val = x - m;
            enqueue(q1, val);
            int val2 = dequeue(q2);
            enqueue(q2, val2);
        }
    }
    
    printf("%d\n", ans);
    
    // Free memory (not shown for simplicity)
    
    return 0;
}

// <END-OF-CODE>
