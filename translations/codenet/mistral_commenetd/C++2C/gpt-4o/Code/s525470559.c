#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100 // Define a maximum number of tasks

// Define a custom struct for tasks
struct task {
    // Name of the task
    char name[100];
    // Time taken by the task
    int time;
};

int main() {
    int n, q; // Number of tasks and queries
    int elaps = 0; // Elapsed time
    struct task Q[MAX_TASKS]; // Array to store tasks
    int front = 0, rear = 0; // Queue pointers

    // Read number of tasks and queries from standard input
    scanf("%d %d", &n, &q);

    // Read tasks details and add them to the queue
    for(int i = 0; i < n; i++) {
        struct task tmp; // Create a new task
        scanf("%s %d", tmp.name, &tmp.time); // Read task name and time from standard input
        Q[rear++] = tmp; // Add the task to the queue
    }

    // Process tasks in the queue until it is empty
    while(front < rear) {
        struct task p = Q[front++]; // Get the task at the front of the queue

        // Check if the current task can be completed within the given query time
        if(p.time <= q) {
            elaps += p.time; // Add the time taken by the task to the elapsed time
            printf("%s %d\n", p.name, elaps); // Print the name and elapsed time of the task
        } else { // If the current task cannot be completed within the given query time
            // Subtract the query time from the time taken by the task
            p.time -= q;
            // Add the task back to the queue with updated time
            Q[rear++] = p;
        }
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
