package main

import (
	"fmt"
)

const (
	MAX  = 100005  // Maximum size of the queue
	N    = 100       // Maximum size of the name string
)

// Define a structure to hold a person's name and their time
type P struct {
	name [N]byte  // Name of the person
	t    int        // Time associated with the person
}

// Declare a queue to hold P structures
var Q [MAX+1]P
var head, tail int  // Head and tail pointers for the queue

// Function to add an element to the queue
func Enqueue(x P) {
	// Wrap around the tail if it reaches the maximum size
	if MAX == tail {
		tail = 0
	}
	Q[tail] = x  // Add the element to the queue
	tail++       // Move the tail pointer forward
}

// Function to remove and return an element from the queue
func Dequeue() P {
	// Wrap around the head if it reaches the maximum size
	if head == MAX {
		head = 0
	}
	element := Q[head]  // Return the element at the head
	head++              // Move the head pointer forward
	return element
}

func main() {
	var i, q, n, T int  // Initialize variables for loop counters, query time, number of people, and total time
	var a P  // Declare a variable of type P to hold the current person

	// Read the number of people and the query time
	fmt.Scan(&n, &q)

	// Read each person's name and time, and enqueue them
	for i = 0; i < n; i++ {
		fmt.Scan(&a.name, &a.t)  // Read name and time
		Enqueue(a)  // Add the person to the queue
	}

	// Process the queue until all people have been served
	for n != 0 {
		a = Dequeue()  // Remove the front person from the queue
		// Check if the person's time exceeds the query time
		if a.t > q {
			a.t = a.t - q  // Reduce their time by the query time
			T += q         // Add query time to total time
			Enqueue(a)     // Re-enqueue the person with the remaining time
		} else {
			T = T + a.t    // Add the person's time to total time
			fmt.Println(string(a.name[:]), T)  // Print the person's name and total time
			n--  // Decrease the count of people left to serve
		}
	}
}

