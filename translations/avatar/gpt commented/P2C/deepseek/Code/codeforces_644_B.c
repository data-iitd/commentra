#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 1000

typedef struct {
    int time;
    int duration;
    int index;
} Task;

Task tasks[MAX_TASKS];
int finish_times[MAX_TASKS];
int remaining_count = 0;
int running = 0;
int finish_time = 0;

void run_task(int task_index) {
    Task task = tasks[task_index];
    finish_time = (finish_time > task.time) ? finish_time : task.time;
    finish_time += task.duration;
    finish_times[task.index] = finish_time;
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tasks[i].time, &tasks[i].duration);
        tasks[i].index = i;
        finish_times[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        Task task = tasks[i];
        if (task.time > finish_time && remaining_count == 0) {
            running = 1;
            run_task(i);
        } else {
            if (task.time >= finish_time && remaining_count > 0) {
                // Find the next task to run
                int next_task_index = -1;
                int next_task_time = 1e9;
                for (int j = 0; j < remaining_count; j++) {
                    if (tasks[j].time < next_task_time) {
                        next_task_time = tasks[j].time;
                        next_task_index = j;
                    }
                }
                run_task(next_task_index);
            }

            if (remaining_count < b) {
                tasks[remaining_count++] = task;
            } else {
                finish_times[task.index] = -1;
            }
        }
    }

    while (remaining_count > 0) {
        run_task(0); // Run the next task in the queue
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", finish_times[i]);
    }

    return 0;
}
