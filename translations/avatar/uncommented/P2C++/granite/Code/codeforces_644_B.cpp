
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Task {
    int time;
    int duration;
    int index;
};

int main() {
    int n, b;
    cin >> n >> b;

    queue<Task> remaining;
    bool running = false;
    int finish_time = 0;
    map<int, int> result;

    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration;
        Task task = {time, duration, i};
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[task.index] = finish_time;
        } else {
            if (task.time >= finish_time &&!remaining.empty()) {
                finish_time = max(finish_time, task.time) + task.duration;
                result[task.index] = finish_time;
            }
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[task.index] = -1;
            }
        }
    }

    while (!remaining.empty()) {
        Task task = remaining.front();
        remaining.pop();
        finish_time = max(finish_time, task.time) + task.duration;
        result[task.index] = finish_time;
    }

    for (auto const& [key, value] : result) {
        cout << value << endl;
    }

    return 0;
}
