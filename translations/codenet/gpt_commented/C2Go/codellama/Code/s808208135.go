package main

import (
	"fmt"
)

const (
	N = 100000  // Define a constant for the maximum number of nodes
	INF = 1000000  // Define a constant for representing infinity
)

// Structure to represent a directed edge with a cost
type Date struct {
	go int    // Destination node
	back int  // Source node
	cost int  // Cost of the edge
}

var n int  // n: number of nodes, d: array to store the shortest distances
var d [N]int
var a [500000]Date  // Array to store edges

func root(b int) {
	var i, j, k, u, count int = 0, 0, 0, 0, 0  // Loop variables and counter for edges
	fmt.Scan(&n)  // Read the number of nodes

	// Read edges for each node
	for i = 0; i < n; i++ {
		fmt.Scan(&u, &k)  // Read the current node and number of edges
		for j = 0; j < k; j++ {
			a[count].back = u  // Set the source node for the edge
			fmt.Scan(&a[count].go, &a[count].cost)  // Read destination and cost
			count++  // Increment the edge counter
		}
	}

	// Call the root function to compute shortest paths
	root(count)

	// Print the shortest distances from the source node to each node
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i])  // Output the node index and its distance
	}
}

// Function to compute shortest paths using the Bellman-Ford algorithm
func root(b int) {
	var i, flag int = 0, 1  // Loop variable and flag to indicate changes

	// Initialize distances to all nodes as infinity
	for i = 0; i < n; i++ {
		d[i] = INF
	}
	d[0] = 0  // Set the distance to the source node (node 0) as 0

	// Repeat the process until no changes occur
	for flag != 0 {
		flag = 0  // Reset flag for this iteration
		// Relax all edges
		for i = 0; i < b; i++ {
			// Check if the current edge can provide a shorter path
			if a[i].cost+d[a[i].back] < d[a[i].go] {
				d[a[i].go] = a[i].cost + d[a[i].back]  // Update the shortest distance
				flag = 1  // Set flag to indicate a change occurred
			}
		}
	}
}

