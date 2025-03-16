package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a struct to represent a Task with its start time, duration, and index
type Task struct {
	time     int
	duration int
	index    int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])

	// Initialize a slice to hold remaining tasks and variables to track the running state and finish time
	var remaining []Task
	running := false
	var finishTime int

	// Dictionary to store the finish time of each task
	result := make(map[int]int)

	// Loop through each task input
	for i := 0; i < n; i++ {
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		time, _ := strconv.Atoi(parts[0])
		duration, _ := strconv.Atoi(parts[1])
		task := Task{time, duration, i}
		result[i] = 0

		// Check if the task can run immediately
		if !running && time >= finishTime {
			running = true
			finishTime = time + duration
			result[i] = finishTime
		} else {
			// If the task starts after the last finished task and there are tasks in the queue
			if time >= finishTime {
				if len(remaining) > 0 {
					finishTime = runTask(remaining, finishTime)
				}
			}

			// Check if we can add the task to the queue
			if len(remaining) < b {
				remaining = append(remaining, task)
			} else {
				result[i] = -1
			}
		}
	}

	// Process any remaining tasks in the queue
	for len(remaining) > 0 {
		finishTime = runTask(remaining, finishTime)
	}

	// Print the finish times for all tasks
	for _, finishTime := range result {
		fmt.Println(finishTime)
	}
}

// Function to run a task from the queue and update the finish time
func runTask(remaining []Task, finishTime int) int {
	taskToRun := remaining[0]
	remaining = remaining[1:]
	finishTime = max(finishTime, taskToRun.time) + taskToRun.duration
	result[taskToRun.index] = finishTime
	return finishTime
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
