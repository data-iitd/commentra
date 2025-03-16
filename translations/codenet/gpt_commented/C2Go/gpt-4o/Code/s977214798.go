package main

import (
	"fmt"
	"math"
)

var (
	n   int
	a   [1000][999]int
	e1  [1000000]int
	e2  [1000000]int
	d   [1000000]int
	b   [1000000]bool
)

// Function to read an integer from input
func nextInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to calculate a unique identifier for a pair of nodes
func p(a, b int) int {
	if a < b {
		return a + b*n
	}
	return b + a*n
}

// Recursive function to compute the maximum distance from a given node
func f(from int) int {
	if b[from] {
		return -1 // Return -1 if the node has already been visited (cycle detected)
	}
	if d[from] != 0 {
		return d[from] // Return the computed distance if already calculated
	}
	b[from] = true // Mark the node as visited
	max := 0       // Variable to track the maximum distance

	to := e1[from] // Get the first edge
	if to != 0 {
		now := f(to) // Recursively compute distance for the first edge
		if now < 0 {
			return now // Return if a cycle is detected
		}
		if now > max {
			max = now // Update max if a longer distance is found
		}
	}

	to = e2[from] // Get the second edge
	if to != 0 {
		now := f(to) // Recursively compute distance for the second edge
		if now < 0 {
			return now // Return if a cycle is detected
		}
		if now > max {
			max = now // Update max if a longer distance is found
		}
	}

	b[from] = false // Unmark the node as visited for future calls
	d[from] = max + 1 // Store and return the computed distance
	return d[from]
}

func main() {
	n = nextInt() // Read the number of nodes

	// Read the adjacency list from input
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			a[i][j] = nextInt() - 1 // Store edges, adjusting for 0-based indexing
		}
	}

	// Build the edge representation
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			from := p(i, a[i][j]) // Get unique index for the current edge
			to := p(i, a[i][j+1]) // Get unique index for the next edge

			// Store the edges in e1 and e2
			if e1[from] == 0 {
				e1[from] = to // Assign the first edge
			} else if e2[from] == 0 {
				e2[from] = to // Assign the second edge
			} else {
				fmt.Println(-1) // Output -1 if more than two edges are found
				return          // Exit the program
			}
		}
	}

	ans := 0 // Variable to store the final answer

	// Compute the maximum distance for each node
	for i := 0; i < n; i++ {
		from := p(i, a[i][0]) // Get unique index for the starting edge
		now := f(from)        // Compute the distance
		if now < 0 {
			ans = -1 // Set answer to -1 if a cycle is detected
			break    // Exit the loop
		}
		if now > ans {
			ans = now // Update the answer if a longer distance is found
		}
	}

	fmt.Println(ans) // Output the final answer
}

// <END-OF-CODE>
