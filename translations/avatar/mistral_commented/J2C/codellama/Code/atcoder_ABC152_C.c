#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    struct Node* node = queue->front;
    int data = node->data;
    queue->front = node->next;
    free(node);
    return data;
}

// Function to find the sum of elements in the queue
int sum(struct Queue* queue) {
    int sum = 0;
    while (!isEmpty(queue)) {
        sum += dequeue(queue);
    }
    return sum;
}

// Function to check if the current element is smaller than or equal to the top element of the queue
bool isSmaller(struct Queue* queue, int data) {
    if (isEmpty(queue)) {
        return false;
    }

    int top = queue->front->data;
    return data <= top;
}

// Function to find the number of elements in the queue that are smaller than or equal to the current element
int countSmaller(struct Queue* queue, int data) {
    int count = 0;
    while (!isEmpty(queue) && isSmaller(queue, data)) {
        dequeue(queue);
        count++;
    }
    return count;
}

// Function to find the solution
int solve() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Queue* queue = createQueue();
    int sum = 0;
    for (int i = 0; i < N; i++) {
        enqueue(queue, arr[i]);
        sum += countSmaller(queue, arr[i]);
    }

    free(queue);
    return sum;
}

int main() {
    printf("%d\n", solve());
    return 0;
}

