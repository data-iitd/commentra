// Importing the queue module for implementing a First-In-First-Out (FIFO) queue
import "container/list"

// Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
var n, b int
fmt.Scanf("%d %d", &n, &b)

// Defining a Task struct to store the time, duration, and index of each task
type Task struct {
    time     int
    duration int
    index    int
}

// Initializing an empty queue for storing the tasks to be executed
var remaining = list.New()

// Initializing some variables for tracking the current finish time and whether any task is currently running
var running bool
var finishTime int

// Function to execute the next task in the queue and update the finish time and result accordingly
func runTask(remaining *list.List, finishTime int) (int, map[int]int) {
    // Getting the next task from the queue
    taskToRun := remaining.Remove(remaining.Front()).(Task)
    // Updating the finish time based on the current task's time and duration
    finishTime = max(finishTime, taskToRun.time) + taskToRun.duration
    // Updating the result map with the finish time for the current task
    result[taskToRun.index] = finishTime
    // Returning the updated finish time and result map
    return finishTime, result
}

// Initializing an empty map for storing the finish time for each task
var result = make(map[int]int)

// Iterating through each task and adding it to the queue or updating the result map based on the current finish time and queue size
for i := 0; i < n; i++ {
    var time, duration int
    fmt.Scanf("%d %d", &time, &duration)
    // Creating a new Task instance and adding it to the result map with an initial finish time of 0
    task := Task{time: time, duration: duration, index: i}
    result[i] = 0
    // If the current task can be executed immediately, update the finish time and result accordingly
    if task.time > finishTime && remaining.Len() == 0 {
        running = true
        finishTime = task.time + task.duration
        result[i] = finishTime
    // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result map with -1 if the queue is full
    } else if task.time >= finishTime && remaining.Len() > 0 {
        finishTime, result = runTask(remaining, finishTime)
        if remaining.Len() < b {
            remaining.PushBack(task)
        } else {
            result[i] = -1
    }
}
// Executing the remaining tasks in the queue, if any
for remaining.Len() > 0 {
    finishTime, result = runTask(remaining, finishTime)
}

// Printing the finish time for each task
for key := range result {
    fmt.Println(result[key])
}

