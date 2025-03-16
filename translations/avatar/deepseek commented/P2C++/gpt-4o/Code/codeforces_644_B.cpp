#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Task {
public:
    int time;
    int duration;
    int index;

    Task(int t, int d, int i) : time(t), duration(d), index(i) {}
};

int main() {
    int n, b;
    cin >> n >> b; // Read the number of tasks (n) and the buffer size (b)

    queue<Task> remaining;
    bool running = false;
    int finish_time = 0;
    map<int, int> result; // Initialize a map to store the finish time of each task

    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration; // Read each task's start time and duration
        Task task(time, duration, i);
        result[i] = 0; // Initialize the result for each task

        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time && !remaining.empty()) {
                Task task_to_run = remaining.front();
                remaining.pop();
                finish_time = max(finish_time, task_to_run.time) + task_to_run.duration;
                result[task_to_run.index] = finish_time;
            }
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1; // Buffer is full, mark the task as unable to run
            }
        }
    }

    while (!remaining.empty()) {
        Task task_to_run = remaining.front();
        remaining.pop();
        finish_time = max(finish_time, task_to_run.time) + task_to_run.duration;
        result[task_to_run.index] = finish_time;
    }

    for (const auto& key : result) {
        cout << key.second << endl; // Print the finish time of each task
    }

    return 0;
}
// <END-OF-CODE>
