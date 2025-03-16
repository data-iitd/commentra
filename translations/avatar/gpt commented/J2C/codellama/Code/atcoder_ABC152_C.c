#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent a node in the priority queue
typedef struct node {
    int value;
    struct node *next;
} node;

// Define a struct to represent the priority queue
typedef struct queue {
    node *head;
    node *tail;
} queue;

// Define a function to create a new node
node *new_node(int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Define a function to create a new priority queue
queue *new_queue() {
    queue *new_queue = (queue *)malloc(sizeof(queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

// Define a function to add an element to the priority queue
void enqueue(queue *q, int value) {
    node *new_node = new_node(value);
    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

// Define a function to remove an element from the priority queue
int dequeue(queue *q) {
    if (q->head == NULL) {
        return -1;
    }
    int value = q->head->value;
    node *temp = q->head;
    q->head = q->head->next;
    free(temp);
    return value;
}

// Define a function to check if the priority queue is empty
bool is_empty(queue *q) {
    return q->head == NULL;
}

// Define a function to check if the priority queue is full
bool is_full(queue *q) {
    return false;
}

// Define a function to print the elements of the priority queue
void print_queue(queue *q) {
    node *temp = q->head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Define a function to solve the problem
int solve() {
    // Create a scanner object to read input from the user
    int N;
    scanf("%d", &N);

    // Initialize an array to hold the input values
    int arr[N];

    // Populate the array with user input
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize a variable to keep track of the count of elements
    int sum = 0;

    // Create a priority queue to manage the elements
    queue *q = new_queue();

    // Iterate through the array to process each element
    for (int i = 0; i < N; i++) {
        // Add the current element to the priority queue
        enqueue(q, arr[i]);

        // Check if the current element is less than or equal to the smallest element in the queue
        if (arr[i] <= dequeue(q)) {
            // Increment the count if the condition is met
            sum++;
        }
    }

    // Return the final count of elements that met the condition
    return sum;
}

int main() {
    // Call the solve method and print the result
    printf("%d\n", solve());
    return 0;
}

