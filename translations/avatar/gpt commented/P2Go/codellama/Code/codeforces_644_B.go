
package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Read the number of tasks (n) and the maximum number of concurrent tasks (b)
	var n, b int
	fmt.Scan(&n, &b)

	// Define a struct to represent a Task with its start time, duration, and index
	type Task struct {
		time      int
		duration  int
		index     int
	}

	// Initialize a queue to hold remaining tasks and variables to track the running state and finish time
	remaining := make([]Task, 0)
	running := false
	finishTime := 0

	// Function to run a task from the queue and update the finish time
	runTask := func(remaining []Task, finishTime int) (int, []int) {
		taskToRun := remaining[0] // Get the next task to run from the queue
		finishTime = max(finishTime, taskToRun.time) + taskToRun.duration // Update finish time
		result[taskToRun.index] = finishTime // Store the finish time for the task
		return finishTime, result // Return updated finish time and results
	}

	// Dictionary to store the finish time of each task
	result := make([]int, n)

	// Loop through each task input
	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scan(&time, &duration) // Read task's start time and duration
		task := Task{time, duration, i} // Create a Task object
		result[i] = 0 // Initialize the result for this task

		// Check if the task can run immediately
		if task.time > finishTime && len(remaining) == 0 {
			running = true // Mark that we are running a task
			finishTime = task.time + task.duration // Update finish time for this task
			result[i] = finishTime // Store the finish time for this task
		} else {
			// If the task starts after the last finished task and there are tasks in the queue
			if task.time >= finishTime && len(remaining) > 0 {
				finishTime, result = runTask(remaining, finishTime) // Run the next task
			}

			// Check if we can add the task to the queue
			if len(remaining) < b {
				remaining = append(remaining, task) // Add the task to the queue if there's capacity
			} else {
				result[i] = -1 // If the queue is full, mark this task as not runnable
			}
		}
	}

	// Process any remaining tasks in the queue
	for len(remaining) > 0 {
		finishTime, result = runTask(remaining, finishTime)
	}

	// Print the finish times for all tasks
	for i := 0; i < n; i++ {
		fmt.Println(result[i])
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

