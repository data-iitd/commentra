package main

import (
	"container/list"
	"fmt"
)

type task struct {
	name string
	time int
}

func main() {
	var n, q int // Number of tasks and queries
	elaps := 0  // Elapsed time
	Q := list.New() // Queue to store tasks

	// Read number of tasks and queries from standard input
	fmt.Scan(&n, &q)

	// Read tasks details and add them to the queue
	for i := 0; i < n; i++ {
		var tmp task // Create a new task
		fmt.Scan(&tmp.name, &tmp.time) // Read task name and time from standard input
		Q.PushBack(tmp) // Add the task to the queue
	}

	// Process tasks in the queue until it is empty
	for Q.Len() > 0 {
		front := Q.Front() // Get the task at the front of the queue
		p := front.Value.(task) // Type assert to task
		Q.Remove(front) // Remove the task from the queue

		// Check if the current task can be completed within the given query time
		if p.time <= q {
			elaps += p.time // Add the time taken by the task to the elapsed time
			fmt.Println(p.name, elaps) // Print the name and elapsed time of the task
		} else { // If the current task cannot be completed within the given query time
			// Subtract the query time from the time taken by the task
			p.time -= q
			// Add the task back to the queue with updated time
			Q.PushBack(p)
		}
	}

	// Return 0 to indicate successful execution of the program
}
