package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Task represents a task with its start time, duration, and index
type Task struct {
	time     int
	duration int
	index    int
}

// Read the number of tasks (n) and the maximum number of concurrent tasks (b)
func readInput() (int, int) {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &b)
	return n, b
}

// Run a task from the queue and update the finish time
func runTask(remaining *[]Task, finishTime int) (int, map[int]int) {
	task := (*remaining)[0]
	finishTime = max(finishTime, task.time) + task.duration
	result[task.index] = finishTime
	*remaining = (*remaining)[1:]
	return finishTime, result
}

// Main function
func main() {
	n, b := readInput()
	remaining := make([]Task, 0)
	result := make(map[int]int)
	finishTime := 0

	// Loop through each task input
	for i := 0; i < n; i++ {
		time, duration := readInput()
		task := Task{time, duration, i}
		result[i] = 0

		// Check if the task can run immediately
		if task.time > finishTime && len(remaining) == 0 {
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else {
			// If the task starts after the last finished task and there are tasks in the queue
			if task.time >= finishTime && len(remaining) > 0 {
				finishTime, result = runTask(&remaining, finishTime)
			}

			// Check if we can add the task to the queue
			if len(remaining) < b {
				remaining = append(remaining, task)
			} else {
				result[i] = -1
		}
	}

	// Process any remaining tasks in the queue
	for len(remaining) > 0 {
		finishTime, result = runTask(&remaining, finishTime)
	}

	// Print the finish times for all tasks
	for key := range result {
		fmt.Println(result[key])
	}
}

// Read the number of tasks (n) and the maximum number of concurrent tasks (b)
func readInput() (int, int) {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &b)
	return n, b
}

// Function to run a task from the queue and update the finish time
func runTask(remaining *[]Task, finishTime int) (int, map[int]int) {
	task := (*remaining)[0]
	finishTime = max(finishTime, task.time) + task.duration
	result[task.index] = finishTime
	*remaining = (*remaining)[1:]
	return finishTime, result
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

