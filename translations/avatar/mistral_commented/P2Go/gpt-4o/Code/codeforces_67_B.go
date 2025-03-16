package main

import (
	"fmt"
	"strings"
)

func main() {
	// Get the number of nodes 'n' and the number of edges 'k' from user input
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize a slice 'M' of size 'n' to represent the status of each node
	M := make([]int, n)
	var input string
	fmt.Scan(&input)
	for i, val := range strings.Split(input, " ") {
		fmt.Sscanf(val, "%d", &M[i])
	}

	// Initialize a counter 'm' to keep track of the number of nodes printed
	m := 0

	// Iterate through each node 'j' in the range of 0 to 'n'
	for j := 0; j < n; j++ {
		// Iterate through each node 'p' in the range of 0 to 'n'
		for p := 0; p < n; p++ {
			// Check if the current node 'p' is not yet processed (M[p] == 0)
			if M[p] == 0 {
				// Print the index of the current node 'p' and increment the counter 'm'
				fmt.Print(p + 1, " ")
				break
			}
		}
		// Decrement the status of all nodes 'l' in the range of 0 to 'p' (exclusive)
		for l := 0; l < p+1-k; l++ {
			M[l]--
		}
		// Decrement the status of the current node 'p'
		M[p]--
	}
}

// <END-OF-CODE>
