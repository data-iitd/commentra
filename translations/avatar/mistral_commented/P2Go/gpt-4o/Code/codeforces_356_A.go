package main

import (
	"fmt"
)

func main() {
	// Define the number of nodes 'n' and the number of edges 'm'
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize an output slice 'out' of size 'n' with zeros
	out := make([]int, n)

	// Initialize a complement slice 'comp' of size 'n' with values 'i+2' for 'i' in range(n)
	comp := make([]int, n)
	for i := 0; i < n; i++ {
		comp[i] = i + 2
	}

	// Process each edge in the given 'm' edges
	for i := 0; i < m; i++ {
		// Read the left node 'l', right node 'r', and value 'x' of the current edge
		var l, r, x int
		fmt.Scan(&l, &r, &x)

		// Set the initial index 't' to the left node 'l'
		t := l

		// Iterate through the nodes from 'l' to 'r'
		for t <= r {
			// Get the next value in the complement slice 'comp'
			nextVal := comp[t-1]

			// If the current node 't' in the output slice 'out' is zero and it's not the value 'x'
			if out[t-1] == 0 && t != x {
				// Update the output slice 'out' with the value 'x' at index 't-1'
				out[t-1] = x
			}

			// Update the complement slice 'comp' with the next value or the value 'x' depending on the condition
			if t >= x {
				comp[t-1] = r + 1
			} else {
				comp[t-1] = x
			}

			// Update the index 't' to the next value in the complement slice 'comp'
			t = nextVal
		}
	}

	// Print the output slice 'out'
	for _, value := range out {
		fmt.Print(value, " ")
	}
	fmt.Println()
}

// <END-OF-CODE>
