
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a struct to represent a Task with its start time, duration, and index
struct Task {
    int time;
    int duration;
    int index;
};

int main() {
    int n, b;
    cin >> n >> b;

    // Initialize a queue to hold remaining tasks and variables to track the running state and finish time
    queue<Task> remaining;
    bool running = false;
    int finish_time = 0;

    // Dictionary to store the finish time of each task
    vector<int> result(n, 0);

    // Loop through each task input
    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration;
        Task task = {time, duration, i};

        // Check if the task can run immediately
        if (task.time > finish_time && remaining.empty()) {
            running = true;  // Mark that we are running a task
            finish_time = task.time + task.duration;  // Update finish time for this task
            result[i] = finish_time;  // Store the finish time for this task
        } else {
            // If the task starts after the last finished task and there are tasks in the queue
            if (task.time >= finish_time &&!remaining.empty()) {
                auto next_task = remaining.front();
                remaining.pop();
                finish_time = max(finish_time, next_task.time) + next_task.duration;  // Update finish time for the next task
                result[next_task.index] = finish_time;  // Store the finish time for the next task
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
        auto next_task = remaining.front();
        remaining.pop();
        finish_time = max(finish_time, next_task.time) + next_task.duration;  // Update finish time for the next task
        result[next_task.index] = finish_time;  // Store the finish time for the next task
    }

    // Print the finish times for all tasks
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
