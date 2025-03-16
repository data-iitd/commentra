#include <iostream>
#include <queue>
#include <vector>
#include <map>

struct Task {
    int time;
    int duration;
    int index;
    Task(int time, int duration, int index) : time(time), duration(duration), index(index) {}
};

int main() {
    int n, b;
    std::cin >> n >> b;
    std::queue<Task> remaining;
    std::map<int, int> result;
    int finish_time = 0;

    for (int i = 0; i < n; ++i) {
        int time, duration;
        std::cin >> time >> duration;
        Task task(time, duration, i);
        result[i] = 0;
        if (task.time > finish_time && remaining.empty()) {
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time && !remaining.empty()) {
                finish_time = run_task(remaining, finish_time);
            }
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        }
    }

    while (!remaining.empty()) {
        finish_time = run_task(remaining, finish_time);
    }

    for (const auto& pair : result) {
        std::cout << pair.second << std::endl;
    }

    return 0;
}

int run_task(std::queue<Task>& remaining, int finish_time) {
    Task task_to_run = remaining.front();
    remaining.pop();
    finish_time = std::max(finish_time, task_to_run.time) + task_to_run.duration;
    result[task_to_run.index] = finish_time;
    return finish_time;
}
