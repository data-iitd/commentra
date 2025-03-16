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

    Task(int time, int duration, int index) : time(time), duration(duration), index(index) {}
};

int main() {
    int n, b;
    cin >> n >> b;

    // Initializing an empty queue for storing the tasks to be executed
    queue<Task> remaining;

    // Initializing some variables for tracking the current finish time and whether any task is currently running
    bool running = false;
    int finish_time = 0;

    // Initializing an empty vector for storing the finish time for each task
    vector<int> result(n, 0);

    // Iterating through each task and adding it to the queue or updating the result vector based on the current finish time and queue size
    for (int i = 0; i < n; ++i) {
        int time, duration;
        cin >> time >> duration;
        // Creating a new Task instance and adding it to the result vector with an initial finish time of 0
        Task task(time, duration, i);
        result[i] = 0;
        // If the current task can be executed immediately, update the finish time and result vector accordingly
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        }
        // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result vector with -1 if the queue is full
        else if (task.time >= finish_time && !remaining.empty()) {
            finish_time = max(finish_time, remaining.front().time) + task.duration;
            result[i] = finish_time;
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        } else {
            remaining.push(task);
        }
    }

    // Executing the remaining tasks in the queue, if any
    while (!remaining.empty()) {
        finish_time = max(finish_time, remaining.front().time) + remaining.front().duration;
        result[remaining.front().index] = finish_time;
        remaining.pop();
    }

    // Printing the finish time for each task
    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
