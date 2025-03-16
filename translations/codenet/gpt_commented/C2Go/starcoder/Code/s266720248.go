package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure to hold the name and time of each process
type pp struct {
	name string
	t    int
}

// Declare a queue to hold the processes
var Q [100005]pp
var head, tail, n int

// Function to add a process to the queue
func enqueue(x pp) {
	Q[tail] = x
	tail = (tail + 1) % 100005
}

// Function to remove a process from the queue
func dequeue() pp {
	x := Q[head]
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
	var elaps, c int
	var i, q int
	var u pp

	// Read the number of processes and the time quantum
	fmt.Scanf("%d %d\n", &n, &q)

	// Read the process names and their respective times
	for i = 1; i <= n; i++ {
		fmt.Scanf("%s\n", &Q[i].name)
		fmt.Scanf("%d\n", &Q[i].t)
	}

	// Initialize head and tail pointers for the queue
	head = 1
	tail = n + 1

	// Process the queue until all processes are completed
	for head!= tail {
		u = dequeue()
		c = min(q, u.t)
		u.t -= c
		elaps += c
		if u.t > 0 {
			enqueue(u)
		} else {
			// If the process is finished, print its name and the total elapsed time
			fmt.Printf("%s %d\n", u.name, elaps)
		}
	}
}

