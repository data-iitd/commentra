package main

import (
	"fmt"
	"container/list"
)

// Defining a Task struct to store the time, duration, and index of each task
type Task struct {
	time     int
	duration int
	index    int
}

func main() {
	// Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
	var n, b int
	fmt.Scan(&n, &b)

	// Initializing an empty queue for storing the tasks to be executed
	remaining := list.New()

	// Initializing some variables for tracking the current finish time and whether any task is currently running
	var running bool
	var finishTime int

	// Initializing an empty map for storing the finish time for each task
	result := make(map[int]int)

	// Iterating through each task and adding it to the queue or updating the result map accordingly
	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scan(&time, &duration)

		// Creating a new Task instance and adding it to the result map with an initial finish time of 0
		task := Task{time, duration, i}
		result[i] = 0

		// If the current task can be executed immediately, update the finish time and result map accordingly
		if task.time > finishTime && remaining.Len() == 0 {
			running = true
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else if task.time >= finishTime {
			// Execute the next task in the queue and update the finish time and result map accordingly
			finishTime, result = runTask(remaining, finishTime)
			if remaining.Len() < b {
				remaining.PushBack(task)
			} else {
				result[i] = -1
			}
		}
	}

	// Executing the remaining tasks in the queue, if any
	for remaining.Len() > 0 {
		finishTime, result = runTask(remaining, finishTime)
	}

	// Printing the finish time for each task
	for _, value := range result {
		fmt.Println(value)
	}
}

// Function to execute the next task in the queue and update the finish time and result map accordingly
func runTask(remaining *list.List, finishTime int) (int, map[int]int) {
	// Getting the next task from the queue
	element := remaining.Front()
	remaining.Remove(element)
	task := element.Value.(Task)

	// Updating the finish time based on the current task's time and duration
	finishTime = max(finishTime, task.time) + task.duration

	// Updating the result map with the finish time for the current task
	result[task.index] = finishTime

	return finishTime, result
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

