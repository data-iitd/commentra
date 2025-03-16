package main

import (
	"fmt"
)

const LEN = 100005 // Maximum size of the queue

// Define a structure 'P' to store name and time of each process
type P struct {
	name string // Name of the process
	t    int    // Time taken by the process
}

// Initialize head and tail pointers and size of the queue
var Q [LEN]P
var head, tail, n int

// Function to add an element to the queue
func enqueue(x P) {
	Q[tail] = x // Add the process to the queue
	tail = (tail + 1) % LEN // Increment tail pointer
}

// Function to remove an element from the queue
func dequeue() P {
	x := Q[head] // Store the process to be removed
	head = (head + 1) % LEN // Increment head pointer
	return x // Return the removed process
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a // Return the smaller integer
	}
	return b
}

func main() {
	elaps := 0 // Initialize elapsed time
	var c, q int // Control variable c and number of processes to be served

	// Read number of processes and number of queries
	fmt.Scan(&n, &q)

	// Allocate memory for each process and read its name and time
	for i := 1; i <= n; i++ {
		var name string
		var t int
		fmt.Scan(&name, &t) // Read name of the process and time taken
		enqueue(P{name: name, t: t}) // Add the process to the queue
	}
	head = 1
	tail = n + 1 // Initialize head and tail pointers

	// Simulate the queue and serve processes based on their arrival time and time taken
	for head != tail {
		u := dequeue() // Dequeue a process
		c = min(q, u.t) // Find the minimum of remaining queries and time taken by the process
		u.t -= c // Subtract the time taken to serve the queries
		elaps += c // Add the time taken to serve the queries to elapsed time
		if u.t > 0 {
			enqueue(u) // If the process still has time left, add it back to the queue
		} else {
			fmt.Printf("%s %d\n", u.name, elaps) // Print the name of the process and elapsed time when it is finished
		}
	}
}
