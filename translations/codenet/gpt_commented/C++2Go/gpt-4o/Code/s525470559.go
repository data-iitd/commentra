package main

import (
	"container/list"
	"fmt"
)

type task struct {
	name string // Name of the task
	time int    // Time required to complete the task
}

func main() {
	var n, q int // n: number of tasks, q: time quantum
	elaps := 0  // Variable to keep track of elapsed time
	Q := list.New() // Queue to manage tasks in a FIFO manner

	// Read the number of tasks and the time quantum from input
	fmt.Scan(&n, &q)

	// Read each task's name and time, and add it to the queue
	for i := 0; i < n; i++ {
		var tmp task // Temporary task variable
		fmt.Scan(&tmp.name, &tmp.time) // Input task name and time
		Q.PushBack(tmp) // Push the task onto the queue
	}

	// Process tasks until the queue is empty
	for Q.Len() > 0 {
		front := Q.Front() // Get the task at the front of the queue
		p := front.Value.(task) // Type assert to task
		Q.Remove(front) // Remove the task from the queue

		// Check if the task can be completed within the time quantum
		if p.time <= q {
			elaps += p.time // Update elapsed time
			fmt.Println(p.name, elaps) // Output task name and total elapsed time
		} else {
			// If the task cannot be completed, reduce its time and re-add it to the queue
			p.time -= q // Decrease the remaining time of the task
			elaps += q // Update elapsed time by the time quantum
			Q.PushBack(p) // Re-add the task to the queue for further processing
		}
	}
}

// <END-OF-CODE>
