<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var n int
var G [100][100]int

// Function to implement Prim's algorithm
func prim() int {
	var u, i, v, mincost int
	var d [100]int
	var pi [100]int
	var color [100]int
	var sum int

	// Initialize all distances to infinity, predecessors to nil, and colors to white
	for u := 0; u < n; u++ {
		d[u] = 999999
		pi[u] = -1
		color[u] = 0
	}

	// Set the distance of the first vertex to 0
	d[0] = 0

	// While there are vertices that have not yet been visited
	for {
		// Initialize mincost to infinity
		mincost = 999999

		// Find the vertex with the smallest distance that is not yet black
		for i := 0; i < n; i++ {
			if color[i]!= 1 && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		// If no more vertices can be reached, break the loop
		if mincost == 999999 {
			break
		}

		// Mark the current vertex as black
		color[u] = 1

		// Update the distances and predecessors for the neighboring vertices that are not black and have a valid edge weight
		for v := 0; v < n; v++ {
			if color[v]!= 1 && G[u][v] < d[v] && G[u][v]!= -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}

	// Calculate the total cost of the Minimum Spanning Tree by summing up the distances of all vertices
	for i := 0; i < n; i++ {
		if d[i]!= 999999 {
			sum += d[i]
		}
	}

	return sum
}

// Main function to execute the program
func main() {
	var i, j int

	// Read the number of vertices from the input
	fmt.Scanf("%d", &n)

	// Read the adjacency matrix representing the graph from the input
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			fmt.Scanf("%d", &G[i][j])
		}
	}

	// Call the prim function and print the result
	fmt.Printf("%d\n", prim())
}

// 