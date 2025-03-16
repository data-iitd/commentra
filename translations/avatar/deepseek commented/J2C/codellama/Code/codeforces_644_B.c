
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1000000

typedef struct {
    int start_time;
    int duration;
} task;

int main(void) {
    int n, b;
    scanf("%d %d", &n, &b);

    task tasks[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tasks[i].start_time, &tasks[i].duration);
    }

    int buffer[MAX_BUFFER_SIZE];
    int buffer_size = 0;
    int buffer_front = 0;
    int buffer_back = 0;

    for (int i = 0; i < n; i++) {
        int task_start_time = tasks[i].start_time;
        int task_duration = tasks[i].duration;

        while (buffer_size > 0 && buffer[buffer_front] <= task_start_time) {
            buffer_front = (buffer_front + 1) % MAX_BUFFER_SIZE;
            buffer_size--;
        }

        if (buffer_size < b) {
            buffer[buffer_back] = task_start_time + task_duration;
            buffer_back = (buffer_back + 1) % MAX_BUFFER_SIZE;
            buffer_size++;
        } else {
            printf("-1 ");
        }
    }

    printf("\n");

    return 0;
}

