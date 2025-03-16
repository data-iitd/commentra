package main

import (
	"fmt"
	"os"
)

func main() {
	var n, b int
	fmt.Scan(&n, &b)
	// Read the number of tasks (n) and the buffer size (b) from the input.

	type Task struct {
		time, duration, index int
	}
	// Define the Task struct to represent a task with its starting time, duration, and index.

	remaining := make([]Task, 0)
	running := false
	finishTime := 0
	// Initialize a slice to store tasks waiting to be processed, a boolean flag to check if a task is running, and a variable to keep track of the finish time.

	result := make(map[int]int)
	// Initialize a map to store the finish time of each task.

	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scan(&time, &duration)
		task := Task{time, duration, i}
		result[i] = 0
		if task.time > finishTime && len(remaining) == 0 {
			running = true
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else {
			if task.time >= finishTime && len(remaining) > 0 {
				finishTime, result = runTask(remaining, finishTime, result)
			}
			if len(remaining) < b {
				remaining = append(remaining, task)
			} else {
				result[i] = -1
			}
		}
	}
	// Read each task, create a Task struct, and process it according to the specified rules:
	// - If the task's start time is greater than the current finish time and the queue is empty, start the task.
	// - If the task's start time is greater than or equal to the current finish time and the queue is not empty, finish the current task and start the new one.
	// - If the buffer is full, mark the task as unable to run.

	for len(remaining) > 0 {
		finishTime, result = runTask(remaining, finishTime, result)
	}
	// Continue processing tasks in the queue until it is empty.

	for key := range result {
		fmt.Println(result[key])
	}
	// Print the finish time of each task stored in the result map.
}

func runTask(remaining []Task, finishTime int, result map[int]int) (int, map[int]int) {
	taskToRun := remaining[0]
	finishTime = max(finishTime, taskToRun.time) + taskToRun.duration
	result[taskToRun.index] = finishTime
	return finishTime, result
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// END-OF-CODE
