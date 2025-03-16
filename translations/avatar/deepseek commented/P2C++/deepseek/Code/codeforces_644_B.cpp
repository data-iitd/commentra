#include <iostream>
#include <queue>
#include <map>

class Task {
public:
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
    bool running = false;
    int finish_time = 0;

    for (int i = 0; i < n; ++i) {
        int time, duration;
        std::cin >> time >> duration;
        Task task(time, duration, i);
        result[i] = 0;
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time && !remaining.empty()) {
                finish_time = std::max(finish_time, remaining.front().time) + remaining.front().duration;
                result[remaining.front().index] = finish_time;
                remaining.pop();
            }
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        }
    }

    while (!remaining.empty()) {
        finish_time = std::max(finish_time, remaining.front().time) + remaining.front().duration;
        result[remaining.front().index] = finish_time;
        remaining.pop();
    }

    for (const auto& pair : result) {
        std::cout << pair.second << std::endl;
    }

    return 0;
}
