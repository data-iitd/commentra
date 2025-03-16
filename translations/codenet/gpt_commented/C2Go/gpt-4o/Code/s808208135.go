package main

import (
	"fmt"
	"math"
)

const (
	N   = 100000  // Define a constant for the maximum number of nodes
	INF = 1000000 // Define a constant for representing infinity
)

// Structure to represent a directed edge with a cost
type Edge struct {
	go    int // Destination node
	back  int // Source node
	cost  int // Cost of the edge
}

var (
	n   int          // Number of nodes
	d   [N]int       // Array to store the shortest distances
	a   [500000]Edge // Array to store edges
)

func main() {
	var count int // Counter for edges
	fmt.Scan(&n)  // Read the number of nodes

	// Read edges for each node
	for i := 0; i < n; i++ {
		var u, k int
		fmt.Scan(&u, &k) // Read the current node and number of edges
		for j := 0; j < k; j++ {
			a[count].back = u // Set the source node for the edge
			fmt.Scan(&a[count].go, &a[count].cost) // Read destination and cost
			count++ // Increment the edge counter
		}
	}

	// Call the root function to compute shortest paths
	root(count)

	// Print the shortest distances from the source node to each node
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i]) // Output the node index and its distance
	}
}

// Function to compute shortest paths using the Bellman-Ford algorithm
func root(b int) {
	flag := true // Flag to indicate changes

	// Initialize distances to all nodes as infinity
	for i := 0; i < n; i++ {
		d[i] = INF
	}
	d[0] = 0 // Set the distance to the source node (node 0) as 0

	// Repeat the process until no changes occur
	for flag {
		flag = false // Reset flag for this iteration
		// Relax all edges
		for i := 0; i < b; i++ {
			// Check if the current edge can provide a shorter path
			if a[i].cost+d[a[i].back] < d[a[i].go] {
				d[a[i].go] = a[i].cost + d[a[i].back] // Update the shortest distance
				flag = true // Set flag to indicate a change occurred
			}
		}
	}
}

// <END-OF-CODE>
