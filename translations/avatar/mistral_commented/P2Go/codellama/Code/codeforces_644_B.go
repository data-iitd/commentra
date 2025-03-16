// Importing the container/heap package for implementing a priority queue
import "container/heap"

// Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
n, b := make([]int, 2)
fmt.Scan(&n[0], &n[1])

// Defining a Task struct to store the time, duration, and index of each task
type Task struct {
    time, duration, index int
}

// Initializing an empty priority queue for storing the tasks to be executed
remaining := make([]Task, 0)

// Initializing some variables for tracking the current finish time and whether any task is currently running
running := false
finish_time := 0

// Function to execute the next task in the queue and update the finish time and result accordingly
func run_task(remaining []Task, finish_time int) (int, map[int]int) {
    // Getting the next task from the queue
    task_to_run := heap.Pop(&remaining).(Task)
    // Updating the finish time based on the current task's time and duration
    finish_time = max(finish_time, task_to_run.time) + task_to_run.duration
    // Updating the result dictionary with the finish time for the current task
    result[task_to_run.index] = finish_time
    // Returning the updated finish time and result dictionary
    return finish_time, result
}

// Initializing an empty dictionary for storing the finish time for each task
result := make(map[int]int)

// Iterating through each task and adding it to the queue or updating the result dictionary based on the current finish time and queue size
for i := 0; i < n[0]; i++ {
    time, duration := make([]int, 2)
    fmt.Scan(&time[0], &duration[0])
    // Creating a new Task instance and adding it to the result dictionary with an initial finish time of 0
    task := Task{time[0], duration[0], i}
    result[i] = 0
    // If the current task can be executed immediately, update the finish time and result accordingly
    if task.time > finish_time && len(remaining) == 0 {
        running = true
        finish_time = task.time + task.duration
        result[i] = finish_time
    // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result dictionary with -1 if the queue is full
    } else if task.time >= finish_time && len(remaining) > 0 {
        finish_time, result = run_task(remaining, finish_time)
        if len(remaining) < b {
            heap.Push(&remaining, task)
        } else {
            result[i] = -1
    }
}
// Executing the remaining tasks in the queue, if any
for len(remaining) > 0 {
    finish_time, result = run_task(remaining, finish_time)
}

// Printing the finish time for each task
for key, value := range result {
    fmt.Println(value)
}

// END-OF-CODE
