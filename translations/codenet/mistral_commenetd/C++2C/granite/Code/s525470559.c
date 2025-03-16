
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom struct for tasks
typedef struct {
    // Name of the task
    char name[50];
    // Time taken by the task
    int time;
} task;

int main()
{
    int n, q; // Number of tasks and queries
    int elaps = 0; // Elapsed time
    task *Q; // Pointer to an array of tasks

    // Read number of tasks and queries from standard input
    scanf("%d %d", &n, &q);

    // Allocate memory for an array of tasks
    Q = (task*)malloc(n * sizeof(task));

    // Read tasks details and add them to the queue
    for(int i = 0; i < n; i++) {
        scanf("%s %d", Q[i].name, &Q[i].time); // Read task name and time from standard input
    }

    // Process tasks in the queue until it is empty
    for(int i = 0; i < n; i++) {
        // Check if the current task can be completed within the given query time
        if(Q[i].time <= q) {
            elaps += Q[i].time; // Add the time taken by the task to the elapsed time
            printf("%s %d\n", Q[i].name, elaps); // Print the name and elapsed time of the task
        }
        else { // If the current task cannot be completed within the given query time
            // Subtract the query time from the time taken by the task
            Q[i].time -= q;
            // Add the task back to the queue with updated time
            Q[n++] = Q[i];
        }
    }

    // Free the memory allocated for the array of tasks
    free(Q);

    // Return 0 to indicate successful execution of the program
    return 0;
}


