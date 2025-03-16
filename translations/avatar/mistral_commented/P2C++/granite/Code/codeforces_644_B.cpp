
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
int n, b;
cin >> n >> b;

// Defining a Task class to store the time, duration, and index of each task
class Task {
public:
    int time, duration, index;
    Task(int time, int duration, int index) : time(time), duration(duration), index(index) {}
};

// Initializing an empty queue for storing the tasks to be executed
queue<Task> remaining;

// Initializing some variables for tracking the current finish time and whether any task is currently running
bool running = false;
int finish_time = 0;

// Function to execute the next task in the queue and update the finish time and result accordingly
void run_task(queue<Task>& remaining, int& finish_time, unordered_map<int, int>& result) {
    // Getting the next task from the queue
    Task task_to_run = remaining.front();
    remaining.pop();
    // Updating the finish time based on the current task's time and duration
    finish_time = max(finish_time, task_to_run.time) + task_to_run.duration;
    // Updating the result dictionary with the finish time for the current task
    result[task_to_run.index] = finish_time;
}

// Initializing an empty dictionary for storing the finish time for each task
unordered_map<int, int> result;

// Iterating through each task and adding it to the queue or updating the result dictionary based on the current finish time and queue size
for (int i = 0; i < n; i++) {
    int time, duration;
    cin >> time >> duration;
    // Creating a new Task instance and adding it to the result dictionary with an initial finish time of 0
    Task task(time, duration, i);
    result[i] = 0;
    // If the current task can be executed immediately, update the finish time and result accordingly
    if (task.time > finish_time && remaining.empty()) {
        running = true;
        finish_time = task.time + task.duration;
        result[i] = finish_time;
    }
    // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result dictionary with -1 if the queue is full
    else if (task.time >= finish_time &&!remaining.empty()) {
        run_task(remaining, finish_time, result);
        if (remaining.size() < b) {
            remaining.push(task);
        } else {
            result[i] = -1;
        }
    }
}
// Executing the remaining tasks in the queue, if any
while (!remaining.empty()) {
    run_task(remaining, finish_time, result);
}

// Printing the finish time for each task
for (auto const& [key, value] : result) {
    cout << value << endl;
}
