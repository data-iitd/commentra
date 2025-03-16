
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a Task with its start time, duration, and index
typedef struct Task {
    int time;
    int duration;
    int index;
} Task;

// Function to run a task from the queue and update the finish time
int run_task(Task *remaining, int finish_time) {
    Task task_to_run = remaining[0];  // Get the next task to run from the queue
    finish_time = (finish_time > task_to_run.time)? finish_time : task_to_run.time;
    finish_time += task_to_run.duration;  // Update finish time
    result[task_to_run.index] = finish_time;  // Store the finish time for the task
    return finish_time;  // Return updated finish time
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    // Dictionary to store the finish time of each task
    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }

    // Initialize a queue to hold remaining tasks
    Task remaining[n];
    int remaining_size = 0;

    // Loop through each task input
    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        Task task = {time, duration, i};  // Create a Task object

        // Check if the task can run immediately
        if (task.time > finish_time && remaining_size == 0) {
            running = 1;  // Mark that we are running a task
            finish_time = task.time + task.duration;  // Update finish time for this task
            result[i] = finish_time;  // Store the finish time for this task
        } else {
            // If the task starts after the last finished task and there are tasks in the queue
            if (task.time >= finish_time && remaining_size > 0) {
                finish_time = run_task(remaining, finish_time);  // Run the next task
            }

            // Check if we can add the task to the queue
            if (remaining_size < b) {
                remaining[remaining_size++] = task;  // Add the task to the queue if there's capacity
            } else {
                result[i] = -1;  // If the queue is full, mark this task as not runnable
            }
        }
    }

    // Process any remaining tasks in the queue
    for (int i = 0; i < remaining_size; i++) {
        finish_time = run_task(remaining, finish_time);
    }

    // Print the finish times for all tasks
    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
