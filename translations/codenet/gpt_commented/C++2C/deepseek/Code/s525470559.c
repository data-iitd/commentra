#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a task with a name and time
typedef struct {
    char name[100]; // Name of the task
    int time;       // Time required to complete the task
} task;

int main() {
    int n, q; // n: number of tasks, q: time quantum
    int elaps = 0; // Variable to keep track of elapsed time
    task *Q = NULL; // Array to manage tasks in a FIFO manner
    int head = 0, tail = 0; // Pointers to manage the queue

    // Read the number of tasks and the time quantum from input
    scanf("%d %d", &n, &q);

    // Allocate memory for the queue
    Q = (task *)malloc(n * sizeof(task));
    if (Q == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read each task's name and time, and add it to the queue
    for (int i = 0; i < n; i++) {
        task tmp; // Temporary task variable
        scanf("%s %d", tmp.name, &tmp.time); // Input task name and time
        Q[tail] = tmp; // Add the task to the queue
        tail = (tail + 1) % n; // Update the tail pointer
    }

    // Process tasks until the queue is empty
    while (head != tail) {
        task p = Q[head]; // Get the task at the front of the queue
        head = (head + 1) % n; // Update the head pointer

        // Check if the task can be completed within the time quantum
        if (p.time <= q) {
            elaps += p.time; // Update elapsed time
            printf("%s %d\n", p.name, elaps); // Output task name and total elapsed time
        } else {
            // If the task cannot be completed, reduce its time and re-add it to the queue
            p.time -= q; // Decrease the remaining time of the task
            elaps += q; // Update elapsed time by the time quantum
            Q[tail] = p; // Add the task to the end of the queue
            tail = (tail + 1) % n; // Update the tail pointer
        }
    }

    // Free the allocated memory
    free(Q);
    return 0; // Exit the program
}
