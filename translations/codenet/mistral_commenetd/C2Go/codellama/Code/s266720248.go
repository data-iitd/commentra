package main

import (
	"fmt"
	"strconv"
)

// Define a structure 'pp' to store name and time of each process
type pp struct {
	name string // Name of the process
	t    int    // Time taken by the process
}

// Initialize head and tail pointers and size of the queue
var Q [100005]pp
var head, tail, n int

// Function to add an element to the queue
func enqueue(x pp) {
	Q[tail] = x // Add the process to the queue
	tail = (tail + 1) % 100005 // Increment tail pointer
}

// Function to remove an element from the queue
func dequeue() pp {
	x := Q[head] // Store the process to be removed
	head = (head + 1) % 100005 // Increment head pointer
	return x // Return the removed process
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var elaps, c int // Initialize elapsed time and control variable c
	var i, q int     // Loop counter and number of processes to be served

	// Read number of processes and number of queries
	fmt.Scan(&n, &q)

	// Allocate memory for each process and read its name and time
	for i = 1; i <= n; i++ {
		fmt.Scan(&Q[i].name) // Read name of the process
		fmt.Scan(&Q[i].t)    // Read time taken by the process
		enqueue(Q[i])        // Add the process to the queue
	}
	head = 1
	tail = n + 1 // Initialize head and tail pointers

	// Simulate the queue and serve processes based on their arrival time and time taken
	for head != tail {
		u := dequeue() // Dequeue a process
		c = min(q, u.t) // Find the minimum of remaining queries and time taken by the process
		u.t -= c        // Subtract the time taken to serve the queries
		elaps += c      // Add the time taken to serve the queries to elapsed time
		if u.t > 0 {
			enqueue(u) // If the process still has time left, add it back to the queue
		} else {
			fmt.Printf("%s %d\n", u.name, elaps) // Print the name of the process and elapsed time when it is finished
		}
	}
}

