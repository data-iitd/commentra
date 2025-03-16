#include <iostream>
#include <queue>
using namespace std;

class Task {
public:
    int time, duration, index;
    Task(int time, int duration, int index) {
        this->time = time;
        this->duration = duration;
        this->index = index;
    }
};

int main() {
    int n, b;
    cin >> n >> b;
    queue<Task> remaining;
    bool running = false;
    int finish_time = 0;
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration;
        Task task(time, duration, i);
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time && !remaining.empty()) {
                finish_time = max(finish_time, task.time) + task.duration;
                result[i] = finish_time;
            }
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        }
    }

    while (!remaining.empty()) {
        finish_time = max(finish_time, remaining.front().time) + remaining.front().duration;
        result[remaining.front().index] = finish_time;
        remaining.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}

