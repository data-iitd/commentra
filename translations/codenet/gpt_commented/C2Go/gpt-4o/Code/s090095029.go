package main

import (
	"fmt"
)

func main() {
	// Declare variables for the number of nodes (n) and edges (m)
	var n, m int
	
	// Read the number of nodes and edges from standard input
	fmt.Scan(&n, &m)
	
	// Initialize a slice to track connections (r0) and set all values to false
	r0 := make([]bool, n)
	
	// Initialize a slice to store nodes connected to node n (r1) and a counter for it
	r1 := make([]int, n)
	nr1 := 0
	
	// Process each edge input
	for i := 0; i < m; i++ {
		var a, b int
		
		// Read the endpoints of the edge
		fmt.Scan(&a, &b)
		
		// Ensure a is the smaller node and b is the larger node
		if a > b {
			a, b = b, a
		}
		
		// Mark the connection from node a to node b in r0
		if a == 1 {
			r0[b-1] = true // If a is 1, mark b-1 as connected
		}
		
		// If b is the last node (n), store a-1 in r1
		if b == n {
			r1[nr1] = a - 1 // Store a-1 in r1
			nr1++          // Increment the count
		}
	}
	
	// Initialize a result variable to determine if a connection is possible
	res := false
	
	// Check if any of the nodes connected to node n are also connected to node 1
	for i := 0; i < nr1; i++ {
		if r0[r1[i]] {
			res = true // If r0 at r1[i] is true, set res to true
		}
	}
	
	// Output the result based on the value of res
	if res {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

// <END-OF-CODE>
