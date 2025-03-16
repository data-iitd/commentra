/*Lucky_Glass*/
package main

import (
	"fmt"
	"math"
)

// Define a constant for the modulus value
const MOD = 7007

// Structure to represent the state of the glass
type QUEUE struct {
	a, b, c, tot int // a, b, c represent the amounts in the glasses, tot represents the number of operations
}

// Array to define the possible operations on the glasses
var F = [6][3]int{
	{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2},
}

// Hash table to keep track of visited states
var Hash [MOD][]int

// Function to check if a state has already been visited
func HASH(n int) bool {
	// Check if the state is already in the hash table
	for i := 0; i < len(Hash[n%MOD]); i++ {
		if n == Hash[n%MOD][i] {
			return false // State already visited
		}
	}
	// If not visited, add the state to the hash table
	Hash[n%MOD] = append(Hash[n%MOD], n)
	return true // State is new
}

func main() {
	// Initialize the total operations count
	Push := QUEUE{0, 0, 0, 0}

	// Create a queue to perform BFS
	que := make([]QUEUE, 0)

	// Read the initial amounts in the glasses
	fmt.Scan(&Push.a, &Push.b, &Push.c)
	// Push the initial state into the queue
	que = append(que, Push)

	// Perform BFS until the queue is empty
	for len(que) > 0 {
		// Get the front state from the queue
		Fro := que[0]

		// Check if all glasses have the same amount
		if Fro.a == Fro.b && Fro.b == Fro.c {
			// If they are equal, print the number of operations and exit
			fmt.Println(Fro.tot)
			return
		}

		// Iterate through all possible operations
		for i := 0; i < 6; i++ {
			// Copy the current state to a new state
			Push = Fro
			Push.tot++ // Increment the operation count

			// Apply the operation to the glasses
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]

			// Create a unique identifier for the new state
			n := Push.a*10000 + Push.b*100 + Push.c

			// Check if the new state has been visited
			if !HASH(n) {
				continue // If visited, skip to the next operation
			}

			// Push the new state into the queue for further exploration
			que = append(que, Push)
		}

		// Remove the processed state from the queue
		que = que[1:]
	}
}

