#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Define a maximum size for the queues

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Function to add an element to the queue
void enqueue(Queue *q, int value) {
    if (q->rear < MAX_SIZE) {
        q->data[q->rear++] = value;
    }
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return -1; // Return -1 if the queue is empty
}

// Function to get the front element of the queue
int peek(Queue *q) {
    if (!isEmpty(q)) {
        return q->data[q->front];
    }
    return -1; // Return -1 if the queue is empty
}

int main() {
    // Create a queue for values and indices
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    // Read the number of elements (n) and the threshold value (m)
    int n, m;
    scanf("%d %d", &n, &m);

    // Populate the queues with input values and their corresponding indices
    for (int i = 1; i <= n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(&q1, value); // Add the value to the first queue
        enqueue(&q2, i);      // Add the index to the second queue
    }

    // Variable to store the final answer (the index of the last processed element)
    int ans = 0;

    // Process the elements in the queue until it is empty
    while (!isEmpty(&q1)) {
        // Check if the front element of q1 is less than or equal to m
        if (peek(&q1) <= m) {
            // If yes, remove it from q1 and update the answer with the corresponding index from q2
            dequeue(&q1);
            ans = dequeue(&q2);
        }
        // If the front element is greater than m
        else if (peek(&q1) > m) {
            // Remove the element, reduce it by m, and add it back to q1
            int x = dequeue(&q1);
            int val = x - m;
            enqueue(&q1, val);

            // Remove the index from q2 and add it back to maintain the order
            int val2 = dequeue(&q2);
            enqueue(&q2, val2);
        }
    }

    // Output the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
