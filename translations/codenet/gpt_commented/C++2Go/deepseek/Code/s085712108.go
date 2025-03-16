package main

import (
	"fmt"
)

// Define a constant for the modulus value
const MOD = 7007

// Structure to represent the state of the glass
type QUEUE struct {
	a, b, c, tot int
}

// Array to define the possible operations on the glasses
var F = [][3]int{{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}}

// Hash table to keep track of visited states
var Hash [MOD][]int

// Function to check if a state has already been visited
func HASH(n int) bool {
	// Check if the state is already in the hash table
	for _, v := range Hash[n%MOD] {
		if n == v {
			return false // State already visited
		}
	}
	// If not visited, add the state to the hash table
	Hash[n%MOD] = append(Hash[n%MOD], n)
	return true // State is new
}

func main() {
	// Initialize the total operations count
	var Push QUEUE
	Push.tot = 0

	// Create a queue to perform BFS
	queue := []QUEUE{Push}

	// Read the initial amounts in the glasses
	fmt.Scan(&Push.a, &Push.b, &Push.c)
	// Push the initial state into the queue
	queue = append(queue, Push)

	// Perform BFS until the queue is empty
	for len(queue) > 0 {
		// Get the front state from the queue
		Fro := queue[0]
		queue = queue[1:]

		// Check if all glasses have the same amount
		if Fro.a == Fro.b && Fro.b == Fro.c {
			// If they are equal, print the number of operations and exit
			fmt.Println(Fro.tot)
			return
		}

		// Iterate through all possible operations
		for _, op := range F {
			// Copy the current state to a new state
			Push = Fro
			Push.tot++ // Increment the operation count

			// Apply the operation to the glasses
			Push.a += op[0]
			Push.b += op[1]
			Push.c += op[2]

			// Create a unique identifier for the new state
			n := Push.a*10000 + Push.b*100 + Push.c

			// Check if the new state has been visited
			if !HASH(n) {
				continue // If visited, skip to the next operation
			}

			// Push the new state into the queue for further exploration
			queue = append(queue, Push)
		}
	}
}

