#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1; // Return -1 if the queue is empty
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(Queue* queue) {
    if (isEmpty(queue)) return -1; // Return -1 if the queue is empty
    return queue->data[queue->front];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // Read the first integer input and the second integer input

    Queue* q1 = createQueue(n); // Initialize queue to store the elements
    Queue* q2 = createQueue(n); // Initialize queue to store the indices

    for (int i = 1; i <= n; i++) {
        int value;
        scanf("%d", &value); // Read each element
        enqueue(q1, value); // Add it to q1
        enqueue(q2, i); // Add the corresponding index to q2
    }

    int ans = 0; // Initialize ans to store the result

    while (!isEmpty(q1)) { // Continue the loop until q1 is empty
        if (front(q1) <= m) { // Check if the front element of q1 is less than or equal to m
            dequeue(q1); // Remove the front element from q1
            ans = dequeue(q2); // Assign the corresponding index to ans and remove it from q2
        } else if (front(q1) > m) { // Check if the front element of q1 is greater than m
            int x = dequeue(q1); // Remove the front element from q1
            int val = x - m; // Subtract m from the element
            enqueue(q1, val); // Add the result back to q1
            int val2 = dequeue(q2); // Remove the corresponding index from q2
            enqueue(q2, val2); // Add the index back to the end of q2
        }
    }

    printf("%d\n", ans); // Print the index of the last remaining element

    // Free allocated memory
    free(q1->data);
    free(q1);
    free(q2->data);
    free(q2);

    return 0;
}

// <END-OF-CODE>
