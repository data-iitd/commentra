package main

import (
	"fmt"
	"os"
	"strconv"
)

// Define a structure to hold the name and time of each process
type pp struct {
	name string // Name of the process
	t    int    // Remaining time for the process
}

// Declare a queue to hold processes
var Q [100005]pp
var head, tail, n int // Queue pointers and number of processes

// Function to add a process to the queue
func enqueue(x pp) {
	Q[tail] = x // Add the process to the tail of the queue
	tail = (tail + 1) % 100005 // Move the tail pointer forward, wrapping around if necessary
}

// Function to remove and return a process from the front of the queue
func dequeue() pp {
	x := Q[head] // Get the process at the head of the queue
	head = (head + 1) % 100005 // Move the head pointer forward, wrapping around if necessary
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
	var i, q int     // Loop variables and the time quantum
	var u pp         // Variable to hold the current process

	// Read the number of processes and the time quantum
	n, _ = strconv.Atoi(os.Args[1])
	q, _ = strconv.Atoi(os.Args[2])

	// Read the name and time for each process
	for i = 1; i <= n; i++ {
		Q[i].name = os.Args[2*i+2] // Read the process name
		Q[i].t, _ = strconv.Atoi(os.Args[2*i+3]) // Read the remaining time for the process
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

