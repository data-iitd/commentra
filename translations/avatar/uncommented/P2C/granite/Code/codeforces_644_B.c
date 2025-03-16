
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <queue>

typedef struct Task {
    int time;
    int duration;
    int index;
} Task;

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    std::queue<Task> remaining;
    bool running = false;
    int finish_time = 0;
    int result[n];
    memset(result, 0, sizeof(result));

    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        Task task = {time, duration, i};

        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time &&!remaining.empty()) {
                finish_time = std::max(finish_time, task.time) + task.duration;
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
        Task task = remaining.front();
        remaining.pop();
        finish_time = std::max(finish_time, task.time) + task.duration;
        result[task.index] = finish_time;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
