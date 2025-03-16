package main

import (
	"fmt"
	"os"
	"strconv"
)

// Define a structure to hold process name and time
type pp struct {
	name string
	t    int
}

// Global variables for the queue, head, tail, and number of processes
var Q [100005]pp
var head, tail, n int

// Enqueue function to add a process to the queue
func enqueue(x pp) {
	Q[tail] = x // Assign the process to the current tail position
	tail = (tail + 1) % 100005 // Update tail to the next position, wrapping around if necessary
}

// Dequeue function to remove and return the next process from the queue
func dequeue() pp {
	x := Q[head] // Get the process at the head
	head = (head + 1) % 100005 // Update head to the next position, wrapping around if necessary
	return x // Return the dequeued process
}

// Min function to return the smaller of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var elaps, c int // Initialize elapsed time and a variable to hold the time quantum
	var i, q int
	var u pp
	n, _ = strconv.Atoi(os.Args[1]) // Read the number of processes
	q, _ = strconv.Atoi(os.Args[2]) // Read the time quantum

	// Read each process's name and time
	for i = 1; i <= n; i++ {
		u.name = os.Args[i*2+2] // Read the process name
		u.t, _ = strconv.Atoi(os.Args[i*2+3]) // Read the process time
		enqueue(u)
	}
	head = 1 // Initialize head to the first position in the queue
	tail = n + 1 // Initialize tail to the position after the last process

	// Process each process in the queue
	for head != tail {
		u = dequeue() // Dequeue the next process
		c = min(q, u.t) // Determine the time slice to process the process
		u.t -= c // Reduce the process time by the time slice
		elaps += c // Add the time slice to the elapsed time
		if u.t > 0 {
			enqueue(u) // If there is more time left for the process, enqueue it again
		} else {
			fmt.Printf("%s %d\n", u.name, elaps) // Otherwise, print the process name and elapsed time
		}
	}
}

