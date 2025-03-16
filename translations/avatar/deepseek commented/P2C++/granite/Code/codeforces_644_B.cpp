
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    struct Task {
        int time, duration, index;
    };

    queue<Task> remaining;
    bool running = false;
    int finish_time = 0;
    map<int, int> result;

    auto run_task = [&remaining, &finish_time, &result]() {
        Task task = remaining.front();
        remaining.pop();
        finish_time = max(finish_time, task.time) + task.duration;
        result[task.index] = finish_time;
    };

    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration;
        Task task = {time, duration, i};
        result[i] = 0;
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time &&!remaining.empty()) {
                run_task();
            }
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        }
    }

    while (!remaining.empty()) {
        run_task();
    }

    for (auto& pair : result) {
        cout << pair.second << endl;
    }

    return 0;
}
// Translate the given Python code to C++ and end with the comment "