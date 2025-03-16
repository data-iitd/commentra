#include <stdio.h>  // Include the standard I/O library for input and output operations.
#include <stdlib.h> // Include the standard library for memory allocation and other utilities.

<<<<<<< HEAD
#define MAX_TASKS 100 // Define a constant for the maximum number of tasks.
=======
#define MAX_TASKS 100 // Define a maximum number of tasks.
>>>>>>> 98c87cb78a (data updated)

struct task {       // Define a struct named 'task' to hold the name and time for each task.
    char name[50];  // The name of the task (assuming a maximum length of 49 characters + null terminator).
    int time;       // The time required to complete the task.
};

<<<<<<< HEAD
struct queue {      // Define a struct for the queue to hold tasks.
    struct task tasks[MAX_TASKS]; // Array to hold tasks.
    int front;      // Index of the front of the queue.
    int rear;       // Index of the rear of the queue.
};

// Function to initialize the queue.
void initQueue(struct queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Function to check if the queue is empty.
int isEmpty(struct queue *q) {
    return q->front == q->rear;
}

// Function to add a task to the queue.
void enqueue(struct queue *q, struct task t) {
    if (q->rear < MAX_TASKS) {
        q->tasks[q->rear++] = t; // Add the task to the rear of the queue.
    }
}

// Function to remove a task from the queue.
struct task dequeue(struct queue *q) {
    return q->tasks[q->front++]; // Remove the task from the front of the queue.
}

int main() {        // The main function is where the program execution begins.
    int n, q;       // Declare variables for the number of tasks and the time quantum.
    int elaps = 0;  // Initialize the elapsed time to 0.
    struct queue Q; // Declare a queue of tasks.
    initQueue(&Q);  // Initialize the queue.
=======
int main() {       // The main function is where the program execution begins.
    int n, q;       // Declare variables for the number of tasks and the time quantum.
    int elaps = 0;  // Initialize the elapsed time to 0.
    struct task Q[MAX_TASKS]; // Declare an array to hold tasks as a queue.
    int front = 0;  // Index for the front of the queue.
    int rear = 0;   // Index for the rear of the queue.
>>>>>>> 98c87cb78a (data updated)

    scanf("%d %d", &n, &q); // Read the number of tasks and the time quantum from the standard input.

    for(int i = 0; i < n; i++) { // Loop to read each task's name and time.
        struct task tmp;          // Create a temporary task object.
        scanf("%s %d", tmp.name, &tmp.time); // Read the task's name and time from the standard input.
<<<<<<< HEAD
        enqueue(&Q, tmp);        // Enqueue the task into the queue.
    }

    while(!isEmpty(&Q)) { // Process each task in the queue until it is empty.
        struct task p = dequeue(&Q); // Get the front task from the queue and remove it from the queue.
        if(p.time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
            elaps += p.time; // Update the elapsed time by adding the task's remaining time.
            printf("%s %d\n", p.name, elaps); // Print the task's name and the current elapsed time.
        }
        else { // If the task's remaining time is greater than the time quantum.
            p.time -= q; // Reduce the task's remaining time by the time quantum.
            elaps += q;  // Update the elapsed time by adding the time quantum.
            enqueue(&Q, p); // Enqueue the task back into the queue with the remaining time.
=======
        Q[rear++] = tmp;         // Add the task to the queue and increment the rear index.
    }

    while(front < rear) { // Process each task in the queue until it is empty.
        struct task p = Q[front++]; // Get the front task from the queue and increment the front index.
        if(p.time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
            elaps += p.time; // Update the elapsed time by adding the task's remaining time.
            printf("%s %d\n", p.name, elaps); // Print the task's name and the current elapsed time.
        } else { // If the task's remaining time is greater than the time quantum.
            p.time -= q; // Reduce the task's remaining time by the time quantum.
            elaps += q;  // Update the elapsed time by adding the time quantum.
            Q[rear++] = p; // Push the task back into the queue with the remaining time.
>>>>>>> 98c87cb78a (data updated)
        }
    }
    return 0; // Return 0 to indicate successful execution of the program.
}

// <END-OF-CODE>
