#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom struct for tasks
typedef struct {
    // Name of the task
    char* name;
    // Time taken by the task
    int time;
} task;

// Define a custom struct for a queue node
typedef struct QNode {
    task data;
    struct QNode* next;
} QNode;

// Define a custom struct for a queue
typedef struct {
    QNode* front;
    QNode* rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to create a new task
task createTask(char* name, int time) {
    task t;
    t.name = (char*)malloc(strlen(name) + 1);
    strcpy(t.name, name);
    t.time = time;
    return t;
}

// Function to add a task to the queue
void enqueue(Queue* q, task t) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->data = t;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a task from the queue
task dequeue(Queue* q) {
    if (q->front == NULL) {
        task emptyTask = {"", 0};
        return emptyTask;
    }
    QNode* temp = q->front;
    task t = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return t;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

int main() {
    int n, q; // Number of tasks and queries
    int elaps = 0; // Elapsed time
    Queue* Q = createQueue(); // Queue to store tasks

    // Read number of tasks and queries from standard input
    scanf("%d %d", &n, &q);

    // Read tasks details and add them to the queue
    for(int i = 0; i < n; i++) {
        char name[100];
        int time;
        scanf("%s %d", name, &time); // Read task name and time from standard input
        task tmp = createTask(name, time); // Create a new task
        enqueue(Q, tmp); // Add the task to the queue
    }

    // Process tasks in the queue until it is empty
    while(!isEmpty(Q)) {
        task p = dequeue(Q); // Get the task at the front of the queue

        // Check if the current task can be completed within the given query time
        if(p.time <= q) {
            elaps += p.time; // Add the time taken by the task to the elapsed time
            printf("%s %d\n", p.name, elaps); // Print the name and elapsed time of the task
        }
        else { // If the current task cannot be completed within the given query time
            // Subtract the query time from the time taken by the task
            p.time -= q;
            // Add the task back to the queue with updated time
            elaps += q;
            enqueue(Q, p);
        }
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}
