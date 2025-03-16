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

// Read the number of tasks (n) and the maximum number of concurrent tasks (b)
int n, b;
scanf("%d %d", &n, &b);

// Define a class to represent a Task with its start time, duration, and index
class Task {
    public:
        int time;      // The time at which the task is available to run
        int duration;  // The duration for which the task will run
        int index;     // The index of the task for result tracking
};

// Function to run a task from the queue and update the finish time
void run_task(std::queue<Task> &remaining, int &finish_time) {
    Task task_to_run = remaining.front();  // Get the next task to run from the queue
    remaining.pop();  // Remove the task from the queue
    finish_time = max(finish_time, task_to_run.time) + task_to_run.duration;  // Update finish time
    result[task_to_run.index] = finish_time;  // Store the finish time for the task
}

// Dictionary to store the finish time of each task
std::map<int, int> result;

// Loop through each task input
for (int i = 0; i < n; i++) {
    int time, duration;
    scanf("%d %d", &time, &duration);  // Read task's start time and duration
    Task task = Task();
    task.time = time;
    task.duration = duration;
    task.index = i;
    result.insert(std::pair<int, int>(i, 0));  // Initialize the result for this task

    // Check if the task can run immediately
    if (task.time > finish_time && remaining.empty()) {
        running = true;  // Mark that we are running a task
        finish_time = task.time + task.duration;  // Update finish time for this task
        result[i] = finish_time;  // Store the finish time for this task
    } else {
        // If the task starts after the last finished task and there are tasks in the queue
        if (task.time >= finish_time &&!remaining.empty()) {
            run_task(remaining, finish_time);  // Run the next task

        // Check if we can add the task to the queue
        if (remaining.size() < b) {
            remaining.push(task);  // Add the task to the queue if there's capacity
        else {
            result[i] = -1;  // If the queue is full, mark this task as not runnable
    }

// Process any remaining tasks in the queue
while (!remaining.empty()) {
    run_task(remaining, finish_time);
}

// Print the finish times for all tasks
for (std::map<int, int>::iterator it = result.begin(); it!= result.end(); it++) {
    printf("%d\n", it->second);
}

