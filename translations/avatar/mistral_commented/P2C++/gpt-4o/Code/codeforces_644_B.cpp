#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Defining a Task class to store the time, duration, and index of each task
class Task {
public:
    int time;
    int duration;
    int index;

    Task(int t, int d, int i) : time(t), duration(d), index(i) {}
};

// Function to execute the next task in the queue and update the finish time and result accordingly
pair<int, vector<int>> run_task(queue<Task>& remaining, int finish_time, vector<int>& result) {
    // Getting the next task from the queue
    Task task_to_run = remaining.front();
    remaining.pop();
    // Updating the finish time based on the current task's time and duration
    finish_time = max(finish_time, task_to_run.time) + task_to_run.duration;
    // Updating the result vector with the finish time for the current task
    result[task_to_run.index] = finish_time;
    // Returning the updated finish time and result vector
    return {finish_time, result};
}

int main() {
    // Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
    int n, b;
    cin >> n >> b;

    // Initializing an empty queue for storing the tasks to be executed
    queue<Task> remaining;

    // Initializing some variables for tracking the current finish time
    int finish_time = 0;
    vector<int> result(n, 0); // Initializing result vector with size n

    // Iterating through each task and adding it to the queue or updating the result vector based on the current finish time and queue size
    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration;
        Task task(time, duration, i);

        // If the current task can be executed immediately, update the finish time and result accordingly
        if (task.time > finish_time && remaining.empty()) {
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        }
        // If the current task cannot be executed immediately
        else if (task.time >= finish_time && !remaining.empty()) {
            auto [new_finish_time, new_result] = run_task(remaining, finish_time, result);
            finish_time = new_finish_time;
            result = new_result;

            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        } else {
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        }
    }

    // Executing the remaining tasks in the queue, if any
    while (!remaining.empty()) {
        auto [new_finish_time, new_result] = run_task(remaining, finish_time, result);
        finish_time = new_finish_time;
        result = new_result;
    }

    // Printing the finish time for each task
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}

// <END-OF-CODE>
