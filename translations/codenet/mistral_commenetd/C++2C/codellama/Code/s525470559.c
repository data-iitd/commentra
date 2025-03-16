#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom struct for tasks
struct task {
    // Name of the task
    char name[100];
    // Time taken by the task
    int time;
};

int main()
{
    int n, q; // Number of tasks and queries
    int elaps = 0; // Elapsed time
    struct task *Q; // Queue to store tasks

    // Read number of tasks and queries from standard input
    scanf("%d %d", &n, &q);

    // Allocate memory for the queue
    Q = (struct task *)malloc(n * sizeof(struct task));

    // Read tasks details and add them to the queue
    for(int i = 0; i < n; i++) {
        scanf("%s %d", Q[i].name, &Q[i].time); // Read task name and time from standard input
    }

    // Process tasks in the queue until it is empty
    while(n > 0) {
        struct task p = Q[0]; // Get the task at the front of the queue

        // Check if the current task can be completed within the given query time
        if(p.time <= q) {
            elaps += p.time; // Add the time taken by the task to the elapsed time
            printf("%s %d\n", p.name, elaps); // Print the name and elapsed time of the task
            n--; // Decrement the number of tasks
            memmove(Q, Q + 1, n * sizeof(struct task)); // Remove the task from the queue
        }
        else { // If the current task cannot be completed within the given query time
            // Subtract the query time from the time taken by the task
            p.time -= q;
            // Add the task back to the queue with updated time
            Q[0] = p;
        }
    }

    // Free memory allocated for the queue
    free(Q);

    // Return 0 to indicate successful execution of the program
    return 0;
}

