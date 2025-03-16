
#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

typedef struct Task {
    int time;
    int duration;
    int index;
} Task;

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    struct queue *remaining = queue_create();
    int running = 0;
    int finish_time = 0;

    int result[n];
    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        Task task = {time, duration, i};
        result[i] = 0;
        if (task.time > finish_time && queue_empty(remaining)) {
            running = 1;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time &&!queue_empty(remaining)) {
                finish_time = MAX(finish_time, task.time) + task.duration;
                result[i] = finish_time;
            }
            if (queue_size(remaining) < b) {
                queue_push(remaining, &task);
            } else {
                result[i] = -1;
            }
        }
    }

    while (!queue_empty(remaining)) {
        Task task = queue_pop(remaining);
        finish_time = MAX(finish_time, task.time) + task.duration;
        result[task.index] = finish_time;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
// Translate the above Python code to C and end with comment "