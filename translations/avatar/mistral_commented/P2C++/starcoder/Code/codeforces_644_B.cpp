#include <bits/stdc++.h>

using namespace std;

// Defining a Task class to store the time, duration, and index of each task
class Task {
public:
    int time;
    int duration;
    int index;
    Task(int time, int duration, int index) {
        this->time = time;
        this->duration = duration;
        this->index = index;
    }
};

// Function to execute the next task in the queue and update the finish time and result accordingly
void run_task(queue<Task> &remaining, int &finish_time, map<int, int> &result) {
    // Getting the next task from the queue
    Task task_to_run = remaining.front();
    remaining.pop();
    // Updating the finish time based on the current task's time and duration
    finish_time = max(finish_time, task_to_run.time) + task_to_run.duration;
    // Updating the result dictionary with the finish time for the current task
    result[task_to_run.index] = finish_time;
}

// Function to execute the remaining tasks in the queue, if any
void execute_remaining(queue<Task> &remaining, int &finish_time, map<int, int> &result) {
    while (!remaining.empty()) {
        run_task(remaining, finish_time, result);
    }
}

// Function to execute the tasks in the queue based on the current finish time and queue size
void execute_tasks(queue<Task> &remaining, int &finish_time, map<int, int> &result, int b) {
    // Iterating through each task and adding it to the queue or updating the result dictionary based on the current finish time and queue size
    for (int i = 0; i < remaining.size(); i++) {
        Task task = remaining.front();
        remaining.pop();
        // If the current task can be executed immediately, update the finish time and result accordingly
        if (task.time > finish_time && remaining.empty()) {
            finish_time = task.time + task.duration;
            result[task.index] = finish_time;
        }
        // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result dictionary with -1 if the queue is full
        else if (task.time >= finish_time &&!remaining.empty()) {
            execute_remaining(remaining, finish_time, result);
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[task.index] = -1;
            }
        }
    }
    // Executing the remaining tasks in the queue, if any
    execute_remaining(remaining, finish_time, result);
}

// Function to print the finish time for each task
void print_result(map<int, int> result) {
    for (auto it = result.begin(); it!= result.end(); it++) {
        cout << it->second << endl;
    }
}

// Main function
int main() {
    // Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
    int n, b;
    cin >> n >> b;
    // Initializing an empty queue for storing the tasks to be executed
    queue<Task> remaining;
    // Initializing some variables for tracking the current finish time and whether any task is currently running
    int finish_time = 0;
    bool running = false;
    // Initializing an empty dictionary for storing the finish time for each task
    map<int, int> result;
    // Iterating through each task and adding it to the queue or updating the result dictionary based on the current finish time and queue size
    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration;
        // Creating a new Task instance and adding it to the result dictionary with an initial finish time of 0
        Task task(time, duration, i);
        result.insert(pair<int, int>(i, 0));
        // If the current task can be executed immediately, update the finish time and result accordingly
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        }
        // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result dictionary with -1 if the queue is full
        else if (task.time >= finish_time &&!remaining.empty()) {
            execute_tasks(remaining, finish_time, result, b);
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        }
    }
    // Executing the remaining tasks in the queue, if any
    execute_tasks(remaining, finish_time, result, b);
    // Printing the finish time for each task
    print_result(result);
    return 0;
}

