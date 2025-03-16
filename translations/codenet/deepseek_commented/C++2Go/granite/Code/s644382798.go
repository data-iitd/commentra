
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Fscanf(scanner, "%d %d\n", &n, &q) // Read the number of processes and the time quantum

	// Read each process's name and time
	for i = 1; i <= n; i++ {
		fmt.Fscanf(scanner, "%s", &Q[i].name) // Read the process name
		fmt.Fscanf(scanner, "%d", &Q[i].t) // Read the process time
	}
	head = 1 // Initialize head to the first position in the queue
	tail = n + 1 // Initialize tail to the position after the last process

	// Process each process in the queue
	for head!= tail {
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

