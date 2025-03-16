#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100000

/**
 * Structure to represent a queue
 */
typedef struct {
    long *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

/**
 * Function to create a queue
 */
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->data = (long*)malloc(capacity * sizeof(long));
    return queue;
}

/**
 * Function to add an element to the queue
 */
void enqueue(Queue* queue, long value) {
    if (queue->size < queue->capacity) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->data[queue->rear] = value;
        queue->size++;
    }
}

/**
 * Function to remove an element from the queue
 */
void dequeue(Queue* queue) {
    if (queue->size > 0) {
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
    }
}

/**
 * Function to get the first element of the queue
 */
long front(Queue* queue) {
    return queue->data[queue->front];
}

/**
 * Function to check if the queue is empty
 */
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

/**
 * Main function to manage task processing with a buffer
 */
int main() {
    int n, b;
    scanf("%d %d", &n, &b); // Read the number of tasks and buffer size
    long ans[MAX_TASKS]; // Array to store task completion times
    Queue* q = createQueue(b); // Queue to manage buffer

    /**
     * Process each task
     */
    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d); // Read the task's start time and duration

        /**
         * Remove completed tasks from the front of the queue
         */
        while (!isEmpty(q) && front(q) <= t) {
            dequeue(q);
        }

        /**
         * Check if the task can be added to the buffer
         */
        if (q->size < b) {
            ans[i] = (isEmpty(q) ? t : front(q)) + d;
            enqueue(q, ans[i]);
        } else {
            ans[i] = -1;
        }
    }

    /**
     * Output the completion times of all tasks
     */
    for (int i = 0; i < n; ++i) {
        printf("%ld ", ans[i]);
    }

    // Free allocated memory
    free(q->data);
    free(q);

    return 0;
}

/* <END-OF-CODE> */
