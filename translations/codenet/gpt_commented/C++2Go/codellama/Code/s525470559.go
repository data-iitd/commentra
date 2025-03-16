package main

import (
	"fmt"
	"os"
)

// Define a structure to represent a task with a name and time
type task struct {
	name string // Name of the task
	time int    // Time required to complete the task
}

func main() {
	var n, q int // n: number of tasks, q: time quantum
	var elaps int // Variable to keep track of elapsed time
	Q := make([]task, 0) // Queue to manage tasks in a FIFO manner

	// Read the number of tasks and the time quantum from input
	fmt.Scan(&n, &q)

	// Read each task's name and time, and add it to the queue
	for i := 0; i < n; i++ {
		var tmp task // Temporary task variable
		fmt.Scan(&tmp.name, &tmp.time) // Input task name and time
		Q = append(Q, tmp) // Push the task onto the queue
	}

	// Process tasks until the queue is empty
	for len(Q) > 0 {
		p := Q[0] // Get the task at the front of the queue
		Q = Q[1:] // Remove the task from the queue

		// Check if the task can be completed within the time quantum
		if p.time <= q {
			elaps += p.time // Update elapsed time
			fmt.Printf("%s %d\n", p.name, elaps) // Output task name and total elapsed time
		} else {
			// If the task cannot be completed, reduce its time and re-add it to the queue
			p.time -= q // Decrease the remaining time of the task
			elaps += q // Update elapsed time by the time quantum
			Q = append(Q, p) // Re-add the task to the queue for further processing
		}
	}
}

