#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a task with a name and time
struct task {
    char name[100]; // Name of the task
    int time;       // Time required to complete the task
};

int main()
{
    int n, q; // n: number of tasks, q: time quantum
    int elaps = 0; // Variable to keep track of elapsed time
    struct task *Q; // Queue to manage tasks in a FIFO manner

    // Read the number of tasks and the time quantum from input
    scanf("%d %d", &n, &q);

    // Allocate memory for the queue
    Q = (struct task *)malloc(n * sizeof(struct task));

    // Read each task's name and time, and add it to the queue
    for(int i = 0; i < n; i++) {
        scanf("%s %d", Q[i].name, &Q[i].time); // Input task name and time
    }

    // Process tasks until the queue is empty
    while(n > 0) {
        struct task p = Q[0]; // Get the task at the front of the queue
        memmove(Q, Q + 1, (n - 1) * sizeof(struct task)); // Remove the task from the queue
        n--; // Decrease the number of tasks
        
        // Check if the task can be completed within the time quantum
        if(p.time <= q) {
            elaps += p.time; // Update elapsed time
            printf("%s %d\n", p.name, elaps); // Output task name and total elapsed time
        }
        else {
            // If the task cannot be completed, reduce its time and re-add it to the queue
            p.time -= q; // Decrease the remaining time of the task
            elaps += q; // Update elapsed time by the time quantum
            Q[n++] = p; // Re-add the task to the queue for further processing
        }
    }
    free(Q); // Free the memory allocated for the queue
    return 0; // Exit the program
}

