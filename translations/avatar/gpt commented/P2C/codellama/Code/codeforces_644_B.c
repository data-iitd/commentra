#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct to represent a task with its start time, duration, and index
typedef struct {
    int time;
    int duration;
    int index;
} Task;

// Function to run a task from the queue and update the finish time
void run_task(Task *task, int *finish_time, int *result) {
    *finish_time = max(*finish_time, task->time) + task->duration;
    result[task->index] = *finish_time;
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    // Initialize a queue to hold remaining tasks and variables to track the running state and finish time
    Task *remaining = (Task *)malloc(n * sizeof(Task));
    bool running = false;
    int finish_time = 0;
    int *result = (int *)malloc(n * sizeof(int));

    // Loop through each task input
    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        Task task = {time, duration, i};
        result[i] = 0;

        // Check if the task can run immediately
        if (task.time > finish_time && i == 0) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            // If the task starts after the last finished task and there are tasks in the queue
            if (task.time >= finish_time && i > 0) {
                run_task(&remaining[i - 1], &finish_time, result);
            }

            // Check if we can add the task to the queue
            if (i < b) {
                remaining[i] = task;
            } else {
                result[i] = -1;
            }
        }
    }

    // Process any remaining tasks in the queue
    for (int i = 0; i < n; i++) {
        if (remaining[i].time > finish_time) {
            run_task(&remaining[i], &finish_time, result);
        }
    }

    // Print the finish times for all tasks
    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    free(remaining);
    free(result);

    return 0;
}

