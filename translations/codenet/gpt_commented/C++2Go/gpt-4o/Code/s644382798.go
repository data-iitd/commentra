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

// Declare a queue to hold processes
var Q [LEN]P
var head, tail, n int // Queue pointers and number of processes

// Function to add a process to the queue
func enqueue(x P) {
	Q[tail] = x // Add the process to the tail of the queue
	tail = (tail + 1) % LEN // Move the tail pointer forward, wrapping around if necessary
}

// Function to remove and return a process from the front of the queue
func dequeue() P {
	x := Q[head] // Get the process at the head of the queue
	head = (head + 1) % LEN // Move the head pointer forward, wrapping around if necessary
	return x // Return the dequeued process
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var elaps, c int // elaps keeps track of elapsed time, c is the time slice
	var q int        // The time quantum
	var u P         // Variable to hold the current process

	// Read the number of processes and the time quantum
	fmt.Scan(&n, &q)

	// Read the name and time for each process
	for i := 1; i <= n; i++ {
		var name string
		var time int
		fmt.Scan(&name, &time) // Read the process name and remaining time
		Q[i] = P{name: name, t: time}
	}

	// Initialize the head and tail pointers for the queue
	head = 1
	tail = n + 1

	// Process the queue until all processes are completed
	for head != tail {
		u = dequeue() // Dequeue the next process
		c = min(q, u.t) // Determine the time slice to process (minimum of quantum and remaining time)
		u.t -= c // Reduce the remaining time of the process
		elaps += c // Increase the elapsed time by the time slice

		// If the process still has remaining time, enqueue it back
		if u.t > 0 {
			enqueue(u)
		} else { // If the process is completed, print its name and the elapsed time
			fmt.Printf("%s %d\n", u.name, elaps)
		}
	}
}

// <END-OF-CODE>
