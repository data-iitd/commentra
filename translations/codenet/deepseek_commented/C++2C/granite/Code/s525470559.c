
#include <stdio.h>  // Include the standard input/output library for input and output operations.
#include <stdlib.h> // Include the standard library for dynamic memory allocation and deallocation.

typedef struct task { // Define a struct named 'task' to hold the name and time for each task.
    char name[100]; // The name of the task.
    int time;       // The time required to complete the task.
} task;

int main() { // The main function is where the program execution begins.
    int n, q; // Declare variables for the number of tasks, the time quantum, and the elapsed time.
    int elaps = 0; // Initialize the elapsed time to 0.
    task *Q; // Declare a pointer to a task object.
    Q = (task*)malloc(sizeof(task)*n); // Allocate memory for the queue of tasks.

    scanf("%d %d", &n, &q); // Read the number of tasks and the time quantum from the standard input.

    for(int i = 0; i < n; i++) { // Loop to read each task's name and time.
        scanf("%s %d", Q[i].name, &Q[i].time); // Read the task's name and time from the standard input.
    }

    for(int i = 0; i < n; i++) { // Process each task in the queue until it is empty.
        if(Q[i].time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
            elaps += Q[i].time; // Update the elapsed time by adding the task's remaining time.
            printf("%s %d\n", Q[i].name, elaps); // Print the task's name and the current elapsed time.
        }
        else { // If the task's remaining time is greater than the time quantum.
            Q[i].time -= q; // Reduce the task's remaining time by the time quantum.
            elaps += q; // Update the elapsed time by adding the time quantum.
            Q[n] = Q[i]; // Push the task back into the queue with the remaining time.
            n++; // Increment the number of tasks in the queue.
        }
    }
    free(Q); // Deallocate the memory for the queue of tasks.
    return 0; // Return 0 to indicate successful execution of the program.
}
