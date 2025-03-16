#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a Task struct to store the time, duration, and index of each task
typedef struct Task {
    int time;
    int duration;
    int index;
} Task;

// Function to execute the next task in the queue and update the finish time and result accordingly
void run_task(Task *task_to_run, int *finish_time, int *result) {
    // Updating the finish time based on the current task's time and duration
    *finish_time = (*finish_time > task_to_run->time) ? *finish_time : task_to_run->time + task_to_run->duration;
    // Updating the result dictionary with the finish time for the current task
    result[task_to_run->index] = *finish_time;
}

int main() {
    // Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
    int n, b;
    scanf("%d %d", &n, &b);

    // Initializing an empty queue for storing the tasks to be executed
    Task *remaining = (Task *)malloc(n * sizeof(Task));
    int remaining_size = 0;

    // Initializing some variables for tracking the current finish time and whether any task is currently running
    int running = 0;
    int finish_time = 0;

    // Initializing an empty dictionary for storing the finish time for each task
    int *result = (int *)malloc(n * sizeof(int));
    memset(result, 0, n * sizeof(int));

    // Iterating through each task and adding it to the queue or updating the result dictionary based on the current finish time and queue size
    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        // Creating a new Task instance and adding it to the result dictionary with an initial finish time of 0
        Task task = {time, duration, i};
        result[i] = 0;
        // If the current task can be executed immediately, update the finish time and result accordingly
        if (task.time > finish_time && remaining_size == 0) {
            running = 1;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        }
        // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result dictionary with -1 if the queue is full
        else if (task.time >= finish_time && remaining_size < b) {
            remaining[remaining_size++] = task;
        } else {
            result[i] = -1;
        }
    }
    // Executing the remaining tasks in the queue, if any
    while (remaining_size > 0) {
        run_task(&remaining[--remaining_size], &finish_time, result);
    }

    // Printing the finish time for each task
    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    // Freeing the memory allocated for the queue and result dictionary
    free(remaining);
    free(result);

    return 0;
}

