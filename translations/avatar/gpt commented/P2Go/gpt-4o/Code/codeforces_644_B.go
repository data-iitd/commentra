package main

import (
	"container/heap"
	"fmt"
)

type Task struct {
	time     int // The time at which the task is available to run
	duration int // The duration for which the task will run
	index    int // The index of the task for result tracking
}

// A priority queue for managing tasks based on their start time
type TaskQueue []*Task

func (pq TaskQueue) Len() int { return len(pq) }

func (pq TaskQueue) Less(i, j int) bool {
	return pq[i].time < pq[j].time
}

func (pq TaskQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *TaskQueue) Push(x interface{}) {
	*pq = append(*pq, x.(*Task))
}

func (pq *TaskQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	task := old[n-1]
	*pq = old[0 : n-1]
	return task
}

func runTask(remaining *TaskQueue, finishTime int, result map[int]int) (int, map[int]int) {
	taskToRun := heap.Pop(remaining).(*Task) // Get the next task to run from the queue
	finishTime = max(finishTime, taskToRun.time) + taskToRun.duration // Update finish time
	result[taskToRun.index] = finishTime // Store the finish time for the task
	return finishTime, result // Return updated finish time and results
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, b int
	fmt.Scan(&n, &b) // Read the number of tasks (n) and the maximum number of concurrent tasks (b)

	remaining := &TaskQueue{}
	heap.Init(remaining) // Initialize the priority queue
	finishTime := 0
	result := make(map[int]int)

	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scan(&time, &duration) // Read task's start time and duration
		task := &Task{time: time, duration: duration, index: i} // Create a Task object
		result[i] = 0 // Initialize the result for this task

		if time > finishTime && remaining.Len() == 0 {
			finishTime = time + duration // Update finish time for this task
			result[i] = finishTime // Store the finish time for this task
		} else {
			if time >= finishTime && remaining.Len() > 0 {
				finishTime, result = runTask(remaining, finishTime, result) // Run the next task
			}

			if remaining.Len() < b {
				heap.Push(remaining, task) // Add the task to the queue if there's capacity
			} else {
				result[i] = -1 // If the queue is full, mark this task as not runnable
			}
		}
	}

	// Process any remaining tasks in the queue
	for remaining.Len() > 0 {
		finishTime, result = runTask(remaining, finishTime, result)
	}

	// Print the finish times for all tasks
	for key := range result {
		fmt.Println(result[key])
	}
}

// <END-OF-CODE>
