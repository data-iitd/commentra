#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100000

typedef struct {
    long *data;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->data = (long *)malloc(MAX_QUEUE_SIZE * sizeof(long));
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void enqueue(Queue *q, long value) {
    if (q->size < MAX_QUEUE_SIZE) {
        q->data[q->rear] = value;
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->size++;
    }
}

void dequeue(Queue *q) {
    if (q->size > 0) {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->size--;
    }
}

long front(Queue *q) {
    return q->data[q->front];
}

long back(Queue *q) {
    return q->data[(q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE];
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void freeQueue(Queue *q) {
    free(q->data);
}

int main() {
    // Read the number of elements (n) and the maximum size of the queue (b)
    int n, b;
    scanf("%d %d", &n, &b);
    
    // Initialize an array to store the results
    long *ans = (long *)malloc(n * sizeof(long));
    
    // Create a queue for managing time values
    Queue q;
    initQueue(&q);
    
    // Process each element based on the input
    for (int i = 0; i < n; i++) {
        // Read the time (t) and duration (d) for the current element
        int t, d;
        scanf("%d %d", &t, &d);
        
        // Remove elements from the front of the queue that are no longer valid
        while (!isEmpty(&q) && front(&q) <= t) {
            dequeue(&q);
        }
        
        // Check if the size of the queue is within the allowed limit
        if (q.size <= b) {
            // If the queue is empty, set the answer to the current time (t) plus duration (d)
            // Otherwise, set it to the last element in the queue plus duration (d)
            ans[i] = (isEmpty(&q) ? t : back(&q)) + d;
            
            // Add the computed answer to the queue
            enqueue(&q, ans[i]);
        } else {
            // If the queue size exceeds the limit, set the answer to -1
            ans[i] = -1;
        }
    }
    
    // Print the results stored in the ans array
    for (int i = 0; i < n; ++i) {
        printf("%ld ", ans[i]);
    }
    
    // Free allocated memory
    free(ans);
    freeQueue(&q);
    
    return 0;
}

// <END-OF-CODE>
