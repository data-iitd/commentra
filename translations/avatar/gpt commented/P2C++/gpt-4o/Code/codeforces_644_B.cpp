#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Define a class to represent a Task with its start time, duration, and index
class Task {
public:
    int time;      // The time at which the task is available to run
    int duration;  // The duration for which the task will run
    int index;     // The index of the task for result tracking

    Task(int t, int d, int i) : time(t), duration(d), index(i) {}
};

// Function to run a task from the queue and update the finish time
pair<int, vector<int>> run_task(queue<Task>& remaining, int finish_time, vector<int>& result) {
    Task task_to_run = remaining.front();  // Get the next task to run from the queue
    remaining.pop();  // Remove the task from the queue
    finish_time = max(finish_time, task_to_run.time) + task_to_run.duration;  // Update finish time
    result[task_to_run.index] = finish_time;  // Store the finish time for the task
    return {finish_time, result};  // Return updated finish time and results
}

int main() {
    // Read the number of tasks (n) and the maximum number of concurrent tasks (b)
    int n, b;
    cin >> n >> b;

    queue<Task> remaining;  // Initialize a queue to hold remaining tasks
    bool running = false;   // Track if a task is currently running
    int finish_time = 0;    // Variable to track the finish time

    // Vector to store the finish time of each task
    vector<int> result(n, 0);

    // Loop through each task input
    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration;  // Read task's start time and duration
        Task task(time, duration, i);  // Create a Task object

        // Check if the task can run immediately
        if (task.time > finish_time && remaining.empty()) {
            running = true;  // Mark that we are running a task
            finish_time = task.time + task.duration;  // Update finish time for this task
            result[i] = finish_time;  // Store the finish time for this task
        } else {
            // If the task starts after the last finished task and there are tasks in the queue
            if (task.time >= finish_time && !remaining.empty()) {
                tie(finish_time, result) = run_task(remaining, finish_time, result);  // Run the next task
            }

            // Check if we can add the task to the queue
            if (remaining.size() < b) {
                remaining.push(task);  // Add the task to the queue if there's capacity
            } else {
                result[i] = -1;  // If the queue is full, mark this task as not runnable
            }
        }
    }

    // Process any remaining tasks in the queue
    while (!remaining.empty()) {
        tie(finish_time, result) = run_task(remaining, finish_time, result);
    }

    // Print the finish times for all tasks
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}

// <END-OF-CODE>
