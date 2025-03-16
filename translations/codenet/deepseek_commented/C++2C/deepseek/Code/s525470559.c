#include <stdio.h>  // Include the standard input-output library for input and output operations.
#include <string.h> // Include the string library for string handling functions.
#include <stdlib.h> // Include the standard library for general utilities like malloc and free.

typedef struct { // Define a struct named 'task' to hold the name and time for each task.
    char name[100]; // The name of the task.
    int time;       // The time required to complete the task.
} task;

int main() { // The main function is where the program execution begins.
    int n, q;        // Declare variables for the number of tasks, the time quantum, and the elapsed time.
    int elaps = 0;   // Initialize the elapsed time to 0.
    task* Q = NULL;  // Declare a pointer to a queue of tasks.
    int head = 0, tail = 0; // Initialize the head and tail indices for the queue.

    scanf("%d %d", &n, &q); // Read the number of tasks and the time quantum from the standard input.

    Q = (task*)malloc(n * sizeof(task)); // Allocate memory for the queue of tasks.

    for(int i = 0; i < n; i++) { // Loop to read each task's name and time.
        scanf("%s %d", Q[tail].name, &Q[tail].time); // Read the task's name and time from the standard input.
        tail++; // Increment the tail index to point to the next free slot in the queue.
    }

    while(head != tail) { // Process each task in the queue until it is empty.
        task p = Q[head]; // Get the front task from the queue.
        head++; // Increment the head index to point to the next task in the queue.
        if(p.time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
            elaps += p.time; // Update the elapsed time by adding the task's remaining time.
            printf("%s %d\n", p.name, elaps); // Print the task's name and the current elapsed time.
        }
        else { // If the task's remaining time is greater than the time quantum.
            p.time -= q; // Reduce the task's remaining time by the time quantum.
            elaps += q;  // Update the elapsed time by adding the time quantum.
            Q[tail] = p; // Add the task back to the end of the queue with the remaining time.
            tail++; // Increment the tail index to point to the next free slot in the queue.
        }
    }
    free(Q); // Free the allocated memory for the queue.
    return 0; // Return 0 to indicate successful execution of the program.
}
