#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int time;
    int duration;
    int index;
};

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    queue<Task> remaining;
    bool running = false;
    int finish_time = 0;

    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        Task task = {time, duration, i};

        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[task.index] = finish_time;
        } else {
            if (task.time >= finish_time && !remaining.empty()) {
                finish_time = max(finish_time, remaining.front().time) + remaining.front().duration;
                result[remaining.front().index] = finish_time;
                remaining.pop();
            }
            if (task.time >= finish_time && remaining.size() < b) {
                finish_time = task.time + task.duration;
                result[task.index] = finish_time;
            } else if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[task.index] = -1;
            }
        }
    }

    while (!remaining.empty()) {
        finish_time = max(finish_time, remaining.front().time) + remaining.front().duration;
        result[remaining.front().index] = finish_time;
        remaining.pop();
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
