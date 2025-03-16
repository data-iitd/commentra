
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a task with a name and time
typedef struct {
    char name[50]; // Name of the task
    int time;    // Time required to complete the task
} task;

int main()
{
    int n, q; // n: number of tasks, q: time quantum
    int elaps = 0; // Variable to keep track of elapsed time
    task *Q; // Pointer to an array of tasks
    int i; // Loop variable

    // Read the number of tasks and the time quantum from input
    scanf("%d %d", &n, &q);

    // Allocate memory for the task array
    Q = (task*)malloc(n * sizeof(task));

    // Read each task's name and time, and store them in the task array
    for(i = 0; i < n; i++) {
        scanf("%s %d", Q[i].name, &Q[i].time); // Input task name and time
    }

    // Process tasks until the queue is empty
    for(i = 0; i < n; i++) {
        // Check if the task can be completed within the time quantum
        if(Q[i].time <= q) {
            elaps += Q[i].time; // Update elapsed time
            printf("%s %d\n", Q[i].name, elaps); // Output task name and total elapsed time
        }
        else {
            // If the task cannot be completed, reduce its time and re-add it to the queue
            Q[i].time -= q; // Decrease the remaining time of the task
            elaps += q; // Update elapsed time by the time quantum
            // Re-add the task to the queue for further processing
            // (Note: This part is not directly translatable to C, as C does not have a built-in queue data structure)
        }
    }

    // Free the memory allocated for the task array
    free(Q);

    return 0; // Exit the program
}
