#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int time;      // The time at which the task is available to run
    int duration;  // The duration for which the task will run
    int index;     // The index of the task for result tracking
} Task;

typedef struct {
    Task* tasks;   // Array of tasks
    int front;     // Index of the front of the queue
    int rear;      // Index of the rear of the queue
    int capacity;  // Maximum number of tasks in the queue
    int size;      // Current number of tasks in the queue
} Queue;

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->tasks = (Task*)malloc(capacity * sizeof(Task));
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to add a task to the queue
void enqueue(Queue* queue, Task task) {
    if (queue->size < queue->capacity) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->tasks[queue->rear] = task;
        queue->size++;
    }
}

// Function to remove a task from the queue
Task dequeue(Queue* queue) {
    Task task = queue->tasks[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return task;
}

// Function to run a task from the queue and update the finish time
void run_task(Queue* remaining, int* finish_time, int* result) {
    Task task_to_run = dequeue(remaining);  // Get the next task to run from the queue
    *finish_time = (*finish_time > task_to_run.time ? *finish_time : task_to_run.time) + task_to_run.duration;  // Update finish time
    result[task_to_run.index] = *finish_time;  // Store the finish time for the task
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);  // Read the number of tasks (n) and the maximum number of concurrent tasks (b)

    Queue* remaining = createQueue(b);  // Initialize a queue to hold remaining tasks
    bool running = false;
    int finish_time = 0;
    int* result = (int*)malloc(n * sizeof(int));  // Array to store the finish time of each task

    // Loop through each task input
    for (int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);  // Read task's start time and duration
        Task task = {time, duration, i};  // Create a Task object
        result[i] = 0;  // Initialize the result for this task

        // Check if the task can run immediately
        if (task.time > finish_time && isEmpty(remaining)) {
            running = true;  // Mark that we are running a task
            finish_time = task.time + task.duration;  // Update finish time for this task
            result[i] = finish_time;  // Store the finish time for this task
        } else {
            // If the task starts after the last finished task and there are tasks in the queue
            if (task.time >= finish_time && !isEmpty(remaining)) {
                run_task(remaining, &finish_time, result);  // Run the next task
            }

            // Check if we can add the task to the queue
            if (remaining->size < b) {
                enqueue(remaining, task);  // Add the task to the queue if there's capacity
            } else {
                result[i] = -1;  // If the queue is full, mark this task as not runnable
            }
        }
    }

    // Process any remaining tasks in the queue
    while (!isEmpty(remaining)) {
        run_task(remaining, &finish_time, result);
    }

    // Print the finish times for all tasks
    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }

    // Free allocated memory
    free(remaining->tasks);
    free(remaining);
    free(result);

    return 0;
}

// <END-OF-CODE>
