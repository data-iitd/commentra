package main

import (
	"fmt"
)

const MAX = 100005 // Define the maximum number of processes
const N = 100      // Define the maximum length of the process name

type Process struct { // Define a structure for processes
	name string // Store the process name
	t    int    // Store the time required for the process
}

var Q [MAX + 1]Process // Declare a queue of processes
var head, tail int      // Initialize pointers for the queue

func Enqueue(x Process) { // Function to add a process to the queue
	if tail == MAX { // Wrap around if tail reaches the maximum size
		tail = 0
	}
	Q[tail] = x // Assign the process to the queue
	tail++      // Increment the tail pointer
}

func Dequeue() Process { // Function to remove and return the process at the front of the queue
	if head == MAX { // Wrap around if head reaches the maximum size
		head = 0
	}
	process := Q[head] // Get the process at the front
	head++             // Increment the head pointer
	return process     // Return the process
}

func main() { // Main function to execute the process scheduling
	var n, q, T int // Declare variables for number of processes, quantum, and total time
	var a Process   // Declare a process variable

	fmt.Scanf("%d %d", &n, &q) // Read the number of processes and the quantum

	for i := 0; i < n; i++ { // Loop to read each process
		var name string
		var time int
		fmt.Scanf("%s %d", &name, &time) // Read the process name and time
		a = Process{name: name, t: time} // Create a new process
		Enqueue(a)                       // Enqueue the process
	}

	for n != 0 { // Loop to process each process
		a = Dequeue() // Dequeue a process
		if a.t > q { // If the process time is greater than the quantum
			a.t -= q // Reduce the process time by the quantum
			T += q    // Increment the total time by the quantum
			Enqueue(a) // Enqueue the process again
		} else { // If the process time is less than or equal to the quantum
			T += a.t // Increment the total time by the process time
			fmt.Printf("%s %d\n", a.name, T) // Print the process name and total time
			n-- // Decrement the number of processes
		}
	}
}
