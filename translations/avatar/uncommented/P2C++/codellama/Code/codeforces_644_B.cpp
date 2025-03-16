#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, b;
    cin >> n >> b;
    class Task {
    public:
        int time, duration, index;
        Task(int time, int duration, int index) {
            this->time = time;
            this->duration = duration;
            this->index = index;
        }
    };
    queue<Task> remaining;
    bool running = false;
    int finish_time = 0;
    void run_task(queue<Task>& remaining, int& finish_time) {
        Task task_to_run = remaining.front();
        finish_time = max(finish_time, task_to_run.time) + task_to_run.duration;
        result[task_to_run.index] = finish_time;
        remaining.pop();
    }
    map<int, int> result;
    for (int i = 0; i < n; i++) {
        int time, duration;
        cin >> time >> duration;
        Task task = Task(time, duration, i);
        result.insert(make_pair(i, 0));
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time && !remaining.empty()) {
                run_task(remaining, finish_time);
            }
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        }
    }
    while (!remaining.empty()) {
        run_task(remaining, finish_time);
    }
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << it->second << endl;
    }
    return 0;
}



Translate the above Python code to C# and end with comment "