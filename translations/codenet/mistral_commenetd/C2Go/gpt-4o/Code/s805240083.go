package main

import (
	"fmt"
)

const MAX = 100005
const N = 100

type Process struct {
	name string
	t    int // time taken by each process
}

var Q [MAX + 1]Process // Circular queue to store the processes
var head, tail int      // pointers for head and tail of the queue

func Enqueue(x Process) {
	// Function to add a process to the queue
	if tail == MAX {
		tail = 0 // Wrap around if tail reaches the maximum
	}
	Q[tail] = x // Store the process in the queue
	tail++      // Increment the tail pointer
}

func Dequeue() Process {
	// Function to remove a process from the queue
	var temp Process // Temporary variable to store the process to be removed
	if head == MAX {
		head = 0 // Wrap around if head reaches the maximum
	}
	temp = Q[head] // Store the process to be removed
	head++         // Increment the head pointer
	return temp    // Return the process
}

func main() {
	var n, q int // Declare variables for input
	var a Process // Declare a variable to store the current process
	T := 0       // Initialize the total time to 0

	fmt.Scanf("%d %d", &n, &q) // Read the number of processes and the time limit from the input

	for i := 0; i < n; i++ { // Loop to read the details of each process and enqueue it
		fmt.Scanf("%s %d", &a.name, &a.t)
		Enqueue(a)
	}

	for n != 0 { // While there are still processes in the queue
		a = Dequeue() // Dequeue the current process
		if a.t > q { // If the process takes more time than the limit
			a.t -= q // Subtract the time limit from the process time
			T += q   // Add the time limit to the total time
			Enqueue(a) // Re-enqueue the process
		} else { // If the process takes less time than the limit
			T += a.t // Add the process time to the total time
			fmt.Printf("%s %d\n", a.name, T) // Print the name and total time taken for the process
			n-- // Decrement the number of processes left
		}
	}
}
