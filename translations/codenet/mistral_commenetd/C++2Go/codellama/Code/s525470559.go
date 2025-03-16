package main

import (
	"fmt"
	"os"
)

// Define a custom struct for tasks
type task struct {
	// Name of the task
	name string
	// Time taken by the task
	time int
}

func main() {
	var n, q int // Number of tasks and queries
	var elaps int // Elapsed time
	Q := make([]task, 0) // Queue to store tasks

	// Read number of tasks and queries from standard input
	fmt.Scan(&n, &q)

	// Read tasks details and add them to the queue
	for i := 0; i < n; i++ {
		var tmp task // Create a new task
		fmt.Scan(&tmp.name, &tmp.time) // Read task name and time from standard input
		Q = append(Q, tmp) // Add the task to the queue
	}

	// Process tasks in the queue until it is empty
	for len(Q) > 0 {
		p := Q[0] // Get the task at the front of the queue
		Q = Q[1:] // Remove the task from the queue

		// Check if the current task can be completed within the given query time
		if p.time <= q {
			elaps += p.time // Add the time taken by the task to the elapsed time
			fmt.Println(p.name, elaps) // Print the name and elapsed time of the task
		} else { // If the current task cannot be completed within the given query time
			// Subtract the query time from the time taken by the task
			p.time -= q
			// Add the task back to the queue with updated time
			Q = append(Q, p)
		}
	}

	// Return 0 to indicate successful execution of the program
	os.Exit(0)
}

