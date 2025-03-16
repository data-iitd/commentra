package main

import (
	"container/list"
	"fmt"
)

func main() {
	var n, b int
	fmt.Scan(&n) // Read the number of tasks
	fmt.Scan(&b) // Read the buffer size
	ans := make([]int64, n) // Slice to store task completion times
	q := list.New() // Queue to manage buffer

	// Process each task
	for i := 0; i < n; i++ {
		var t, d int
		fmt.Scan(&t) // Read the task's start time
		fmt.Scan(&d) // Read the task's duration

		// Remove completed tasks from the front of the queue
		for q.Len() > 0 && q.Front().Value.(int64) <= int64(t) {
			q.Remove(q.Front())
		}

		// Check if the task can be added to the buffer
		if q.Len() < b {
			if q.Len() == 0 {
				ans[i] = int64(t) + int64(d)
			} else {
				ans[i] = q.Back().Value.(int64) + int64(d)
			}
			q.PushBack(ans[i])
		} else {
			ans[i] = -1
		}
	}

	// Output the completion times of all tasks
	for i := 0; i < n; i++ {
		fmt.Print(ans[i], " ")
	}
}

// <END-OF-CODE>
