<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Global variables
var N, K int
var A [200100]int
var B [200100]int
var now int
var cnt int

// Function to read input values
func readInput() {
	fmt.Scan(&N, &K)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i+1])
	}
}

// Function to initialize B array
func initB() {
	for i := 0; i < 200100; i++ {
		B[i] = -1
	}
}

// Function to simulate the algorithm
func simulate() {
	var j int
	for j = 1; j <= K; j++ {
		// Move to the next node
		now = A[now]

		// If the node has not been reached yet, update B[now]
		if B[now] == -1 {
			B[now] = j
		} else {
			// If the node has already been reached, calculate the answer
			cnt = j
			break
		}
	}

	// If the simulation has not reached the end, calculate the answer
	if j < K {
		var tmp int
		tmp = (K - B[now]) % (cnt - B[now])

		// Move to the final node
		for j = 0; j < tmp; j++ {
			now = A[now]
		}
	}
}

// Function to print the answer
func printAnswer() {
	fmt.Println(now)
}

// Main function
func main() {
	// Read input values
	readInput()

	// Initialize B array
	initB()

	// Simulate the algorithm
	simulate()

	// Print the answer
	printAnswer()
}

