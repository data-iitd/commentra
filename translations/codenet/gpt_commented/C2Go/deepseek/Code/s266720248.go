package main

import (
	"fmt"
)

// Define a structure to hold the name and time of each process
type P struct {
	Name string // Name of the process
	T    int    // Remaining time for the process
}

// Declare a queue to hold the processes
var Q [100005]P
var head, tail, n int // Variables for queue management and number of processes

// Function to add a process to the queue
func enqueue(x P) {
	Q[tail] = x // Add the process to the queue at the tail
	tail = (tail + 1) % 100005
}

// Function to remove a process from the queue
func dequeue() P {
	x := Q[head] // Get the process at the head of the queue
	head = (head + 1) % 100005
	return x
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var elaps, c int // elaps keeps track of elapsed time, c for current time slice
	var i int
	var u P // Variable to hold the current process
	var q int // The time quantum

	// Read the number of processes and the time quantum
	fmt.Scan(&n, &q)

	// Read the process names and their respective times
	for i = 1; i <= n; i++ {
		fmt.Scan(&Q[i].Name, &Q[i].T)
	}

	// Initialize head and tail pointers for the queue
	head = 1
	tail = n + 1

	// Process the queue until all processes are completed
	for head != tail {
		u = dequeue() // Remove the next process from the queue
		c = min(q, u.T) // Determine the time slice to process (minimum of quantum and remaining time)
		u.T -= c // Decrease the remaining time of the process
		elaps += c // Increase the elapsed time by the time slice
		if u.T > 0 {
			enqueue(u) // If the process is not finished, re-add it to the queue
		} else {
			// If the process is finished, print its name and the total elapsed time
			fmt.Printf("%s %d\n", u.Name, elaps)
		}
	}
}

