#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <float.h>
#include <limits.h>
#include <queue>

// Defining a Task class to store the time, duration, and index of each task
typedef struct Task {
    int time;
    int duration;
    int index;
} Task;

// Function to execute the next task in the queue and update the finish time and result accordingly
void run_task(std::queue<Task> *remaining, int *finish_time, int *result) {
    // Getting the next task from the queue
    Task task_to_run = remaining->front();
    // Updating the finish time based on the current task's time and duration
    *finish_time = max(*finish_time, task_to_run.time) + task_to_run.duration;
    // Updating the result dictionary with the finish time for the current task
    result[task_to_run.index] = *finish_time;
    // Removing the task from the queue
    remaining->pop();
}

// Function to execute the remaining tasks in the queue, if any
void execute_remaining_tasks(std::queue<Task> *remaining, int *finish_time, int *result) {
    while (!remaining->empty()) {
        run_task(remaining, finish_time, result);
    }
}

// Main function for the program
int main() {
    // Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
    int n, b;
    scanf("%d %d", &n, &b);
    // Initializing an empty queue for storing the tasks to be executed
    std::queue<Task> remaining;
    // Initializing some variables for tracking the current finish time and whether any task is currently running
    bool running = false;
    int finish_time = 0;
    // Initializing an empty dictionary for storing the finish time for each task
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }
    // Iterating through each task and adding it to the queue or updating the result dictionary based on the current finish time and queue size
    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        // Creating a new Task instance and adding it to the result dictionary with an initial finish time of 0
        Task task = {time, duration, i};
        result[i] = 0;
        // If the current task can be executed immediately, update the finish time and result accordingly
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        }
        // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result dictionary with -1 if the queue is full
        else if (task.time >= finish_time &&!remaining.empty()) {
            execute_remaining_tasks(&remaining, &finish_time, result);
            if (remaining.size() < b) {
                remaining.push(task);
            }
            else {
                result[i] = -1;
            }
        }
    }
    // Executing the remaining tasks in the queue, if any
    execute_remaining_tasks(&remaining, &finish_time, result);
    // Printing the finish time for each task
    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}

