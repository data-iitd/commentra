#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct to represent a Task with its start time, duration, and index
struct Task {
    int time;      // The time at which the task is available to run
    int duration;  // The duration for which the task will run
    int index;     // The index of the task for result tracking

    Task(int t, int d, int i) : time(t), duration(d), index(i) {}
};

int main() {
    int n, b;
    cin >> n >> b;

    // Initialize a queue to hold remaining tasks and variables to track the running state and finish time
    queue<Task> remaining;
    vector<int> result(n, 0);
    int finish_time = 0;

    // Loop through each task input
    for (int i = 0; i < n; ++i) {
        int time, duration;
        cin >> time >> duration;
        Task task(time, duration, i);

        // Check if the task can run immediately
        if (time > finish_time && remaining.empty()) {
            finish_time = time + duration;  // Update finish time for this task
            result[i] = finish_time;  // Store the finish time for this task
        } else {
            // If the task starts after the last finished task and there are tasks in the queue
            if (time >= finish_time && !remaining.empty()) {
                finish_time = max(finish_time, remaining.front().time) + duration;  // Update finish time
                result[i] = finish_time;  // Store the finish time for this task
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
        finish_time = max(finish_time, remaining.front().time) + remaining.front().duration;  // Update finish time
        result[remaining.front().index] = finish_time;  // Store the finish time for this task
        remaining.pop();
    }

    // Print the finish times for all tasks
    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
