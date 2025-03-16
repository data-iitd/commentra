#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <stdbool.h> // Including library for boolean type

// Defining a structure for a queue
typedef struct Queue {
    int *array; // Array to hold the queue elements
    int front; // Index of the front element
    int rear; // Index of the rear element
    int capacity; // Maximum number of elements in the queue
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue)); // Allocating memory for the queue
    queue->capacity = capacity; // Setting the capacity
    queue->front = 0; // Initializing front index
    queue->rear = -1; // Initializing rear index
    queue->array = (int*)malloc(queue->capacity * sizeof(int)); // Allocating memory for the array
    return queue; // Returning the created queue
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front > queue->rear; // Returns true if front index is greater than rear index
}

// Function to add an element to the queue
void enqueue(Queue* queue, int item) {
    queue->array[++queue->rear] = item; // Increment rear and add item
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    return queue->array[queue->front++]; // Return the front item and increment front index
}

// Function to get the front element of the queue
int peek(Queue* queue) {
    return queue->array[queue->front]; // Return the front item without removing it
}

int main() { // Starting the main function
    int n, m; // Declaring variables for input
    scanf("%d %d", &n, &m); // Reading the first two integers n and m

    Queue* q1 = createQueue(n); // Creating queue q1
    Queue* q2 = createQueue(n); // Creating queue q2

    for (int i = 1; i <= n; i++) { // Iterating through the input values from 1 to n
        int value;
        scanf("%d", &value); // Reading the next integer value
        enqueue(q1, value); // Adding the value to queue q1
        enqueue(q2, i); // Adding the current index value to queue q2
    }

    int ans = 0; // Initializing the answer variable to 0
    while (!isEmpty(q1)) { // Starting the while loop to process the queues until q1 is empty
        if (peek(q1) <= m) { // Checking if the next value in q1 is less than or equal to m
            ans = dequeue(q2); // Removing the corresponding index value from q2 and assigning it to the answer variable
            dequeue(q1); // Removing the next value from q1
        } else { // If the next value in q1 is greater than m
            int x = dequeue(q1); // Removing the next value from q1
            int val = x - m; // Calculating the new value by subtracting m from the next value
            enqueue(q1, val); // Adding the new value back to the queue q1
            int val2 = dequeue(q2); // Removing the corresponding index value from q2
            enqueue(q2, val2); // Adding the index value back to the queue q2
        }
    }

    printf("%d\n", ans); // Printing the final answer

    // Freeing allocated memory
    free(q1->array);
    free(q1);
    free(q2->array);
    free(q2);

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
