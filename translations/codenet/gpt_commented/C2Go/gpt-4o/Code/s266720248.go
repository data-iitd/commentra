package main

import (
	"fmt"
)

const LEN = 100005

// Define a structure to hold the name and time of each process
type P struct {
	name string // Name of the process
	t    int    // Remaining time for the process
}

// Declare a queue to hold the processes
var Q [LEN]P
var head, tail, n int // Variables for queue management and number of processes

// Function to add a process to the queue
func enqueue(x P) {
	Q[tail] = x // Add the process to the queue at the tail
	tail = (tail + 1) % LEN // Move the tail pointer in a circular manner
}

// Function to remove a process from the queue
func dequeue() P {
	x := Q[head] // Get the process at the head of the queue
	head = (head + 1) % LEN // Move the head pointer in a circular manner
	return x // Return the removed process
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a // Return the smaller of the two values
	}
	return b
}

func main() {
	elaps := 0 // elaps keeps track of elapsed time
	var c int   // c for current time slice
	var q int   // the time quantum
	var u P     // Variable to hold the current process

	// Read the number of processes and the time quantum
	fmt.Scan(&n, &q)

	// Read the process names and their respective times
	for i := 1; i <= n; i++ {
		fmt.Scan(&Q[i].name) // Read process name
		fmt.Scan(&Q[i].t)    // Read remaining time for the process
	}

	// Initialize head and tail pointers for the queue
	head = 1
	tail = n + 1

	// Process the queue until all processes are completed
	for head != tail {
		u = dequeue() // Remove the next process from the queue
		c = min(q, u.t) // Determine the time slice to process (minimum of quantum and remaining time)
		u.t -= c // Decrease the remaining time of the process
		elaps += c // Increase the elapsed time by the time slice
		if u.t > 0 {
			enqueue(u) // If the process is not finished, re-add it to the queue
		} else {
			// If the process is finished, print its name and the total elapsed time
			fmt.Printf("%s %d\n", u.name, elaps)
		}
	}
}

// <END-OF-CODE>
