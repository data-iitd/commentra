#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100 // Define a maximum number of tasks
<<<<<<< HEAD
#define MAX_NAME_LENGTH 100 // Define a maximum length for task names

// Define a structure to represent a task with a name and time
struct task {
    char name[MAX_NAME_LENGTH]; // Name of the task
    int time;                  // Time required to complete the task
=======

// Define a structure to represent a task with a name and time
struct task {
    char name[100]; // Name of the task
    int time;       // Time required to complete the task
>>>>>>> 98c87cb78a (data updated)
};

int main() {
    int n, q; // n: number of tasks, q: time quantum
    int elaps = 0; // Variable to keep track of elapsed time
<<<<<<< HEAD
    struct task Q[MAX_TASKS]; // Array to manage tasks in a FIFO manner
    int front = 0, rear = 0; // Indices for the queue
=======
    struct task Q[MAX_TASKS]; // Array to manage tasks
    int front = 0, rear = 0; // Queue pointers
>>>>>>> 98c87cb78a (data updated)

    // Read the number of tasks and the time quantum from input
    scanf("%d %d", &n, &q);

    // Read each task's name and time, and add it to the queue
    for(int i = 0; i < n; i++) {
        struct task tmp; // Temporary task variable
        scanf("%s %d", tmp.name, &tmp.time); // Input task name and time
        Q[rear++] = tmp; // Add the task to the queue
    }

    // Process tasks until the queue is empty
    while(front < rear) {
        struct task p = Q[front++]; // Get the task at the front of the queue
        
        // Check if the task can be completed within the time quantum
        if(p.time <= q) {
            elaps += p.time; // Update elapsed time
            printf("%s %d\n", p.name, elaps); // Output task name and total elapsed time
        } else {
            // If the task cannot be completed, reduce its time and re-add it to the queue
            p.time -= q; // Decrease the remaining time of the task
            elaps += q; // Update elapsed time by the time quantum
            Q[rear++] = p; // Re-add the task to the queue for further processing
        }
    }
    return 0; // Exit the program
}

// <END-OF-CODE>
